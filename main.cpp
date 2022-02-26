#include <iostream>
#include "dji_mavlink/common/mavlink.h"

int main() {
    mavlink_heartbeat_t  value;
    mavlink_heartbeat_t *heartbeat_t = &value;
    heartbeat_t->system_status = MAV_STATE_ACTIVE;
    heartbeat_t->base_mode = MAV_MODE_AUTO_ARMED;
    heartbeat_t->autopilot = MAV_AUTOPILOT_GENERIC;
    heartbeat_t->type = MAV_TYPE_QUADROTOR;
    heartbeat_t->mavlink_version = 3;
    mavlink_message_t  msg;
    mavlink_msg_heartbeat_encode(0, 200, &msg, heartbeat_t);
    uint8_t buf[279];
    int len = mavlink_msg_to_send_buffer(buf, &msg);
    for (int i = 0; i < len; ++i) {
        printf("%02X ", buf[i]);
    }
    printf("\n");
    heartbeat_t->system_status = MAV_STATE_ACTIVE;
    heartbeat_t->base_mode = MAV_MODE_AUTO_ARMED;
    heartbeat_t->autopilot = MAV_AUTOPILOT_GENERIC;
    heartbeat_t->type = MAV_TYPE_QUADROTOR;
    heartbeat_t->mavlink_version = 3;
    mavlink_msg_heartbeat_encode(0, 200, &msg, heartbeat_t);
    len = mavlink_msg_to_send_buffer(buf, &msg);
    for (int i = 0; i < len; ++i) {
        printf("%02X ", buf[i]);
    }
    printf("\n");
    return 0;
}
