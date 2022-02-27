#include <iostream>
#include "dji_mavlink/common/mavlink.h"
#include "dji_mavlink/dji_mavlink_adapter.h"
#include "thread"

int main() {
    mavlink_heartbeat_t value;
    mavlink_heartbeat_t *heartbeat_t = &value;
    heartbeat_t->system_status = MAV_STATE_ACTIVE;
    heartbeat_t->base_mode = MAV_MODE_AUTO_ARMED;
    heartbeat_t->autopilot = MAV_AUTOPILOT_GENERIC;
    heartbeat_t->type = MAV_TYPE_QUADROTOR;
    heartbeat_t->mavlink_version = 3;
    mavlink_message_t msg;
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
    mavlink_adapter::set_mavlink("192.168.254.223", 14550);
    std::thread th_rec([&] {
                           mavlink_adapter::recv_function();
                       }
    );
    uint8_t count = 10;
    while (count) {
//        mavlink_adapter::loop_callback(NULL);
        mavlink_sys_status_t sysStatus;
        memset(&sysStatus, 0, sizeof(sysStatus));
        sysStatus.battery_remaining = 97;
        sysStatus.voltage_battery = 17;
        sysStatus.current_battery = 2;
        sysStatus.load = 100;
        sysStatus.onboard_control_sensors_present = 326171663;
        sysStatus.onboard_control_sensors_enabled = 309369871;
        sysStatus.onboard_control_sensors_health = 57711631;
        mavlink_adapter::send_sys_status(&sysStatus);
        usleep(1000000);
    }
    printf("___________________\n");
    usleep(5000000);
    return 0;
}
