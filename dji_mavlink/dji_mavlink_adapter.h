#include "mavlink_connector.h"
#include <string>

namespace mavlink_adapter
{
    void set_mavlink(std::string _tty,int _port);
    void recv_function();
    void loop_callback(long timestamp);
    void send_heartbeat(mavlink_heartbeat_t *heartbeat);
    void send_attitude(mavlink_attitude_quaternion_t *attitudeQuaternion);
    void send_system_time(mavlink_system_time_t *systemTime);
    void send_gps_global_origin(mavlink_gps_global_origin_t *gpsGlobalOrigin);
    void send_gps_raw_int(mavlink_gps_raw_int_t *gps);
    void send_sys_status(mavlink_sys_status_t *sysStatus);
}
