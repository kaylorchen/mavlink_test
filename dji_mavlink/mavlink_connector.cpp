#include "mavlink_connector.h"
#include <vector>

namespace mavlink_adapter {

    void mavlink_connector::init_network(std::string ip, int port) {
        //create a UDP socket
        if ((socket_s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1) {
            printf("Socket Create failed");
        }

        memset((char *) &si_other, 0, sizeof(si_other));
        si_other.sin_family = AF_INET;
        si_other.sin_port = htons(port);
        if (inet_aton(ip.c_str(), &si_other.sin_addr) == 0) {
            fprintf(stderr, "inet_aton() failed\n");
        }

        printf("build udp %s via port %d\n", ip.c_str(), port);

        addr_len = sizeof(struct sockaddr_in);
    }


    int mavlink_connector::write(const char *s, int len) {
        const char *buf = s;
        int slen = sizeof(si_other);
        if (sendto(socket_s, buf, len, 0, (sockaddr *) &si_other, slen) == -1) {
            printf("failed:len %d\n", len);
            return -1;
        }

        return 0;
    }

    mavlink_heartbeat_t *mavlink_connector::make_heartbeat() {
        heartbeat_t->system_status = MAV_STATE_ACTIVE;
        heartbeat_t->base_mode = MAV_MODE_FLAG_MANUAL_INPUT_ENABLED;
        heartbeat_t->autopilot = MAV_AUTOPILOT_GENERIC;
        heartbeat_t->type = MAV_TYPE_QUADROTOR;
        return heartbeat_t;
    }

    void mavlink_connector::slow_send() {

        mavlink_gps_raw_int_t gps_raw_int_t;
        mavlink_battery_status_t battery_status_t;
        mavlink_rc_channels_t rc_channels_t;

        mavlink_message_t msg;


        mavlink_msg_gps_raw_int_encode(0, 200, &msg, &gps_raw_int_t);
        send_msg(&msg);


        mavlink_msg_heartbeat_encode(0, 200, &msg, make_heartbeat());
        send_msg(&msg);
//        printf("sended heartbeating......\n");

        mavlink_msg_battery_status_encode(0, 200, &msg, &battery_status_t);
        send_msg(&msg);

        mavlink_sys_status_t sys_status_t;
        memset(&sys_status_t, 0, sizeof(sys_status_t));

        mavlink_msg_sys_status_encode(0, 200, &msg, &sys_status_t);
        send_msg(&msg);

        mavlink_rc_channels_scaled_t rc_channels_scaled_t;

        mavlink_msg_rc_channels_scaled_encode(0, 200, &msg, &rc_channels_scaled_t);
        send_msg(&msg);

    }

    void mavlink_connector::fast_send() {

        mavlink_attitude_quaternion_t att;
        mavlink_local_position_ned_t pos;
        mavlink_global_position_int_t global_position_int_t;
        mavlink_message_t msg;


        global_position_int_t.vx = (int16_t) (pos.vx * 100);
        global_position_int_t.vy = (int16_t) (pos.vy * 100);
        global_position_int_t.vz = (int16_t) (pos.vz * 100);


        mavlink_msg_attitude_quaternion_encode(0, 200, &msg, &att);
        send_msg(&msg);
        mavlink_msg_local_position_ned_encode(0, 200, &msg, &pos);
        send_msg(&msg);
        mavlink_msg_global_position_int_encode(0, 200, &msg, &global_position_int_t);
        send_msg(&msg);

    }

    int mavlink_connector::send_msg(mavlink_message_t *msg) {

        int len = mavlink_msg_to_send_buffer((uint8_t *) buffer, msg);
        write(buffer, len);
        return 0;
    }

    void mavlink_connector::recv() {
        bzero(rec_buffer, sizeof(rec_buffer));
        int len = (int) recvfrom(socket_s, (void *) rec_buffer, sizeof(rec_buffer), 0, (struct sockaddr *) &si_other,
                                 (socklen_t *) &addr_len);
//        for (int i = 0; i < len; ++i) {
//            printf("%X ", (uint8_t)rec_buffer[i]);
//        }
//        printf("\n");
        handle_mavlink(rec_buffer, len);
    }

    mavlink_connector::mavlink_connector(std::string ip, int port) {
        init_network(ip, port);
        heartbeat_t = new mavlink_heartbeat_t;
    }

    void mavlink_connector::handle_mavlink(char *buffer, int len) {
        mavlink_message_t msg;
        mavlink_status_t status;
        for (ssize_t i = 0; i < len; i++) {
            if (mavlink_parse_char(MAVLINK_COMM_1, buffer[i], &msg, &status)) {
                handle_message(&msg);
            }
        }
    }

    void mavlink_connector::handle_message(mavlink_message_t *msg) {
        switch (msg->msgid) {
            case MAVLINK_MSG_ID_HEARTBEAT:
                printf("I can hear you heart, sys_id = %d, seq = %d\n", msg->sysid, msg->seq);
                break;
            case MAVLINK_MSG_ID_COMMAND_LONG:
                printf("I receive a command long message\n");
                handle_command_long(msg);
                break;
            case MAVLINK_MSG_ID_MISSION_REQUEST_LIST:
            case MAVLINK_MSG_ID_MISSION_REQUEST:
            case MAVLINK_MSG_ID_MISSION_COUNT:
            case MAVLINK_MSG_ID_MISSION_SET_CURRENT:
            case MAVLINK_MSG_ID_MISSION_ITEM:
                handle_missions(msg);
                printf("aaa\n");
                break;
            default:
                printf("msg id is %d\n", msg->msgid);
        }
    }

    void mavlink_connector::handle_command_long(mavlink_message_t *msg) {
        mavlink_command_long_t cmd;
        mavlink_msg_command_long_decode(msg, &cmd);
        switch (cmd.command) {
            case MAV_CMD_NAV_TAKEOFF:
                printf("recv takeof..\n");
                break;

            case MAV_CMD_NAV_LAND:
                printf("land mode..\n");
                break;

            case MAV_CMD_NAV_RETURN_TO_LAUNCH:
                printf("return to home\n");
                break;
            default:
                printf("cmd is %d\n", cmd.command);
        }
    }

    void mavlink_connector::handle_missions(mavlink_message_t *msg) {
        printf("handle_missions test\n");
    }

    void mavlink_connector::handle_local_position_sp(mavlink_message_t *msg) {
        printf("setted \n");
    }

};