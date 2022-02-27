#include <iostream>
#include "dji_mavlink/common/mavlink.h"
#include "dji_mavlink/dji_mavlink_adapter.h"
#include "thread"

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
    mavlink_adapter::set_mavlink("192.168.254.223",14550);
    std::thread th_rec([&]{
                           mavlink_adapter::recv_function();
                       }
    );
    while(1)
    {
        mavlink_heartbeat_t heartbeat;
        heartbeat.type = MAV_TYPE_QUADROTOR; //四旋翼
        heartbeat.autopilot = MAV_AUTOPILOT_GENERIC; //通用自动驾驶仪
        heartbeat.base_mode = MAV_MODE_FLAG_MANUAL_INPUT_ENABLED; // 远程控制输入
        heartbeat.system_status = MAV_STATE_ACTIVE;
        mavlink_adapter::send_heartbeat(&heartbeat);
        usleep(1000000);
    }
    return 0;
}
