#include "mavlink_connector.h"
#include <string>

namespace mavlink_adapter
{
    void set_mavlink(std::string _tty,int _port);
    void recv_function();
    void send_heartbeat(mavlink_heartbeat_t *heartbeat);
    void send_attitude(mavlink_attitude_quaternion_t *attitudeQuaternion);
}
