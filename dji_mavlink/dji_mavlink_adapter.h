#ifndef MAVLINK_ADAPTER
#define MAVLINK_ADAPTER

#include "mavlink_connector.h"
#include <string>

namespace mavlink_adapter {

    void set_mavlink(std::string _tty, int _port);

    mavlink_connector *get_mavlink_connector(void);

    void recv_function();

    void loop_callback(long timestamp);
/**
 * example:
 * mavlink_sys_status_t sysStatus;
 * memset(&sysStatus, 0, sizeof(sysStatus));
 * mavlink_adapter::send_mavlink_msg(&sysStatus, mavlink_msg_sys_status_encode);
 * */
    template<typename T>
    void
    send_mavlink_msg(T const *message, uint16_t (*func)(uint8_t, uint8_t, mavlink_message_t *, const T *)) {
        mavlink_message_t msg;
        func(0, 200, &msg, message);;
        get_mavlink_connector()->send_msg(&msg);
    }
}
#endif
