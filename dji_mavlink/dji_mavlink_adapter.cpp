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

    void send_heartbeat(mavlink_heartbeat_t *heartbeat){
        mavlink_message_t  msg;
        mavlink_msg_heartbeat_encode(0, 200, &msg, heartbeat);
        uint8_t buf[279];
        int len = mavlink_msg_to_send_buffer(buf, &msg);
        mav->send_msg(&msg);
    }

    void send_attitude(mavlink_attitude_quaternion_t *attitudeQuaternion)
    {
        mavlink_message_t  msg;
        mavlink_msg_attitude_quaternion_encode(0, 200, &msg, attitudeQuaternion);
        uint8_t buf[279];
        int len = mavlink_msg_to_send_buffer(buf, &msg);
        mav->send_msg(&msg);
    }
}
