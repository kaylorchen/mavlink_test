#pragma once
// MESSAGE MAVLINK_MSG_ID_LOCAL_POSITION_NED PACKING

#define MAVLINK_MSG_ID_MAVLINK_MSG_ID_LOCAL_POSITION_NED 200


typedef struct __mavlink_mavlink_msg_id_local_position_ned_t {
 int32_t latitude; /*< [degE7] Latitude (WGS84)*/
 int32_t longitude; /*< [degE7] Longitude (WGS84)*/
 int32_t altitude; /*< [mm] Altitude (MSL). Positive for up.*/
} mavlink_mavlink_msg_id_local_position_ned_t;

#define MAVLINK_MSG_ID_MAVLINK_MSG_ID_LOCAL_POSITION_NED_LEN 12
#define MAVLINK_MSG_ID_MAVLINK_MSG_ID_LOCAL_POSITION_NED_MIN_LEN 12
#define MAVLINK_MSG_ID_200_LEN 12
#define MAVLINK_MSG_ID_200_MIN_LEN 12

#define MAVLINK_MSG_ID_MAVLINK_MSG_ID_LOCAL_POSITION_NED_CRC 86
#define MAVLINK_MSG_ID_200_CRC 86



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MAVLINK_MSG_ID_LOCAL_POSITION_NED { \
    200, \
    "MAVLINK_MSG_ID_LOCAL_POSITION_NED", \
    3, \
    {  { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_mavlink_msg_id_local_position_ned_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_mavlink_msg_id_local_position_ned_t, longitude) }, \
         { "altitude", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_mavlink_msg_id_local_position_ned_t, altitude) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MAVLINK_MSG_ID_LOCAL_POSITION_NED { \
    "MAVLINK_MSG_ID_LOCAL_POSITION_NED", \
    3, \
    {  { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_mavlink_msg_id_local_position_ned_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_mavlink_msg_id_local_position_ned_t, longitude) }, \
         { "altitude", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_mavlink_msg_id_local_position_ned_t, altitude) }, \
         } \
}
#endif

/**
 * @brief Pack a mavlink_msg_id_local_position_ned message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param latitude [degE7] Latitude (WGS84)
 * @param longitude [degE7] Longitude (WGS84)
 * @param altitude [mm] Altitude (MSL). Positive for up.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mavlink_msg_id_local_position_ned_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               int32_t latitude, int32_t longitude, int32_t altitude)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MAVLINK_MSG_ID_LOCAL_POSITION_NED_LEN];
    _mav_put_int32_t(buf, 0, latitude);
    _mav_put_int32_t(buf, 4, longitude);
    _mav_put_int32_t(buf, 8, altitude);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MAVLINK_MSG_ID_LOCAL_POSITION_NED_LEN);
#else
    mavlink_mavlink_msg_id_local_position_ned_t packet;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.altitude = altitude;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MAVLINK_MSG_ID_LOCAL_POSITION_NED_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MAVLINK_MSG_ID_LOCAL_POSITION_NED;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MAVLINK_MSG_ID_LOCAL_POSITION_NED_MIN_LEN, MAVLINK_MSG_ID_MAVLINK_MSG_ID_LOCAL_POSITION_NED_LEN, MAVLINK_MSG_ID_MAVLINK_MSG_ID_LOCAL_POSITION_NED_CRC);
}

/**
 * @brief Pack a mavlink_msg_id_local_position_ned message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param latitude [degE7] Latitude (WGS84)
 * @param longitude [degE7] Longitude (WGS84)
 * @param altitude [mm] Altitude (MSL). Positive for up.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mavlink_msg_id_local_position_ned_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   int32_t latitude,int32_t longitude,int32_t altitude)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MAVLINK_MSG_ID_LOCAL_POSITION_NED_LEN];
    _mav_put_int32_t(buf, 0, latitude);
    _mav_put_int32_t(buf, 4, longitude);
    _mav_put_int32_t(buf, 8, altitude);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MAVLINK_MSG_ID_LOCAL_POSITION_NED_LEN);
#else
    mavlink_mavlink_msg_id_local_position_ned_t packet;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.altitude = altitude;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MAVLINK_MSG_ID_LOCAL_POSITION_NED_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MAVLINK_MSG_ID_LOCAL_POSITION_NED;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MAVLINK_MSG_ID_LOCAL_POSITION_NED_MIN_LEN, MAVLINK_MSG_ID_MAVLINK_MSG_ID_LOCAL_POSITION_NED_LEN, MAVLINK_MSG_ID_MAVLINK_MSG_ID_LOCAL_POSITION_NED_CRC);
}

/**
 * @brief Encode a mavlink_msg_id_local_position_ned struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param mavlink_msg_id_local_position_ned C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mavlink_msg_id_local_position_ned_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_mavlink_msg_id_local_position_ned_t* mavlink_msg_id_local_position_ned)
{
    return mavlink_msg_mavlink_msg_id_local_position_ned_pack(system_id, component_id, msg, mavlink_msg_id_local_position_ned->latitude, mavlink_msg_id_local_position_ned->longitude, mavlink_msg_id_local_position_ned->altitude);
}

/**
 * @brief Encode a mavlink_msg_id_local_position_ned struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param mavlink_msg_id_local_position_ned C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mavlink_msg_id_local_position_ned_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_mavlink_msg_id_local_position_ned_t* mavlink_msg_id_local_position_ned)
{
    return mavlink_msg_mavlink_msg_id_local_position_ned_pack_chan(system_id, component_id, chan, msg, mavlink_msg_id_local_position_ned->latitude, mavlink_msg_id_local_position_ned->longitude, mavlink_msg_id_local_position_ned->altitude);
}

/**
 * @brief Send a mavlink_msg_id_local_position_ned message
 * @param chan MAVLink channel to send the message
 *
 * @param latitude [degE7] Latitude (WGS84)
 * @param longitude [degE7] Longitude (WGS84)
 * @param altitude [mm] Altitude (MSL). Positive for up.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_mavlink_msg_id_local_position_ned_send(mavlink_channel_t chan, int32_t latitude, int32_t longitude, int32_t altitude)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MAVLINK_MSG_ID_LOCAL_POSITION_NED_LEN];
    _mav_put_int32_t(buf, 0, latitude);
    _mav_put_int32_t(buf, 4, longitude);
    _mav_put_int32_t(buf, 8, altitude);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MAVLINK_MSG_ID_LOCAL_POSITION_NED, buf, MAVLINK_MSG_ID_MAVLINK_MSG_ID_LOCAL_POSITION_NED_MIN_LEN, MAVLINK_MSG_ID_MAVLINK_MSG_ID_LOCAL_POSITION_NED_LEN, MAVLINK_MSG_ID_MAVLINK_MSG_ID_LOCAL_POSITION_NED_CRC);
#else
    mavlink_mavlink_msg_id_local_position_ned_t packet;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.altitude = altitude;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MAVLINK_MSG_ID_LOCAL_POSITION_NED, (const char *)&packet, MAVLINK_MSG_ID_MAVLINK_MSG_ID_LOCAL_POSITION_NED_MIN_LEN, MAVLINK_MSG_ID_MAVLINK_MSG_ID_LOCAL_POSITION_NED_LEN, MAVLINK_MSG_ID_MAVLINK_MSG_ID_LOCAL_POSITION_NED_CRC);
#endif
}

/**
 * @brief Send a mavlink_msg_id_local_position_ned message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_mavlink_msg_id_local_position_ned_send_struct(mavlink_channel_t chan, const mavlink_mavlink_msg_id_local_position_ned_t* mavlink_msg_id_local_position_ned)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_mavlink_msg_id_local_position_ned_send(chan, mavlink_msg_id_local_position_ned->latitude, mavlink_msg_id_local_position_ned->longitude, mavlink_msg_id_local_position_ned->altitude);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MAVLINK_MSG_ID_LOCAL_POSITION_NED, (const char *)mavlink_msg_id_local_position_ned, MAVLINK_MSG_ID_MAVLINK_MSG_ID_LOCAL_POSITION_NED_MIN_LEN, MAVLINK_MSG_ID_MAVLINK_MSG_ID_LOCAL_POSITION_NED_LEN, MAVLINK_MSG_ID_MAVLINK_MSG_ID_LOCAL_POSITION_NED_CRC);
#endif
}

#if MAVLINK_MSG_ID_MAVLINK_MSG_ID_LOCAL_POSITION_NED_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_mavlink_msg_id_local_position_ned_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int32_t latitude, int32_t longitude, int32_t altitude)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int32_t(buf, 0, latitude);
    _mav_put_int32_t(buf, 4, longitude);
    _mav_put_int32_t(buf, 8, altitude);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MAVLINK_MSG_ID_LOCAL_POSITION_NED, buf, MAVLINK_MSG_ID_MAVLINK_MSG_ID_LOCAL_POSITION_NED_MIN_LEN, MAVLINK_MSG_ID_MAVLINK_MSG_ID_LOCAL_POSITION_NED_LEN, MAVLINK_MSG_ID_MAVLINK_MSG_ID_LOCAL_POSITION_NED_CRC);
#else
    mavlink_mavlink_msg_id_local_position_ned_t *packet = (mavlink_mavlink_msg_id_local_position_ned_t *)msgbuf;
    packet->latitude = latitude;
    packet->longitude = longitude;
    packet->altitude = altitude;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MAVLINK_MSG_ID_LOCAL_POSITION_NED, (const char *)packet, MAVLINK_MSG_ID_MAVLINK_MSG_ID_LOCAL_POSITION_NED_MIN_LEN, MAVLINK_MSG_ID_MAVLINK_MSG_ID_LOCAL_POSITION_NED_LEN, MAVLINK_MSG_ID_MAVLINK_MSG_ID_LOCAL_POSITION_NED_CRC);
#endif
}
#endif

#endif

// MESSAGE MAVLINK_MSG_ID_LOCAL_POSITION_NED UNPACKING


/**
 * @brief Get field latitude from mavlink_msg_id_local_position_ned message
 *
 * @return [degE7] Latitude (WGS84)
 */
static inline int32_t mavlink_msg_mavlink_msg_id_local_position_ned_get_latitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field longitude from mavlink_msg_id_local_position_ned message
 *
 * @return [degE7] Longitude (WGS84)
 */
static inline int32_t mavlink_msg_mavlink_msg_id_local_position_ned_get_longitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field altitude from mavlink_msg_id_local_position_ned message
 *
 * @return [mm] Altitude (MSL). Positive for up.
 */
static inline int32_t mavlink_msg_mavlink_msg_id_local_position_ned_get_altitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Decode a mavlink_msg_id_local_position_ned message into a struct
 *
 * @param msg The message to decode
 * @param mavlink_msg_id_local_position_ned C-struct to decode the message contents into
 */
static inline void mavlink_msg_mavlink_msg_id_local_position_ned_decode(const mavlink_message_t* msg, mavlink_mavlink_msg_id_local_position_ned_t* mavlink_msg_id_local_position_ned)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_id_local_position_ned->latitude = mavlink_msg_mavlink_msg_id_local_position_ned_get_latitude(msg);
    mavlink_msg_id_local_position_ned->longitude = mavlink_msg_mavlink_msg_id_local_position_ned_get_longitude(msg);
    mavlink_msg_id_local_position_ned->altitude = mavlink_msg_mavlink_msg_id_local_position_ned_get_altitude(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_MAVLINK_MSG_ID_LOCAL_POSITION_NED_LEN? msg->len : MAVLINK_MSG_ID_MAVLINK_MSG_ID_LOCAL_POSITION_NED_LEN;
        memset(mavlink_msg_id_local_position_ned, 0, MAVLINK_MSG_ID_MAVLINK_MSG_ID_LOCAL_POSITION_NED_LEN);
    memcpy(mavlink_msg_id_local_position_ned, _MAV_PAYLOAD(msg), len);
#endif
}
