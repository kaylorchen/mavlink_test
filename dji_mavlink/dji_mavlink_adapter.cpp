#include "dji_mavlink_adapter.h"
#include <stdio.h>
#include <string>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include <ostream>
#include <vector>
#include "mavlink_connector.h"

namespace mavlink_adapter {
    mavlink_connector *mav = nullptr;

    void set_mavlink(std::string _tty, int _port) {
        mav = new mavlink_connector(_tty, _port);
    }

    void recv_function() {
        printf("starting recving....\n");
        while (true) {
            if (mav != nullptr)
                mav->recv();
        }
    }

    void send_heartbeat(mavlink_heartbeat_t *heartbeat) {
        mavlink_message_t msg;
        mavlink_msg_heartbeat_encode(0, 200, &msg, heartbeat);
        mav->send_msg(&msg);
    }

    void send_attitude(mavlink_attitude_quaternion_t *attitudeQuaternion) {
        mavlink_message_t msg;
        mavlink_msg_attitude_quaternion_encode(0, 200, &msg, attitudeQuaternion);
        mav->send_msg(&msg);
    }

    void send_system_time(mavlink_system_time_t *systemTime) {
        mavlink_message_t msg;
        mavlink_msg_system_time_encode(0, 200, &msg, systemTime);;
        mav->send_msg(&msg);
    }

    void send_gps_global_origin(mavlink_gps_global_origin_t *gpsGlobalOrigin) {
        mavlink_message_t msg;
        mavlink_msg_gps_global_origin_encode(0, 200, &msg, gpsGlobalOrigin);;
        mav->send_msg(&msg);
    }

    void send_gps_raw_int(mavlink_gps_raw_int_t *gps) {
        mavlink_message_t msg;
        mavlink_msg_gps_raw_int_encode(0, 200, &msg, gps);;
        mav->send_msg(&msg);
    }

    void send_sys_status(mavlink_sys_status_t *sysStatus){
        mavlink_message_t msg;
        mavlink_msg_sys_status_encode(0, 200, &msg, sysStatus);;
        mav->send_msg(&msg);
    }

    void loop_callback(long timestamp)
    {
        mav -> fast_send();
        static int k = 0;
        if (k++ % 50 == 0)
        {
            mav -> slow_send();
        }
    }
}
