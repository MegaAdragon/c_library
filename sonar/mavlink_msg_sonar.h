// MESSAGE SONAR PACKING

#define MAVLINK_MSG_ID_SONAR 150

typedef struct __mavlink_sonar_t
{
 uint64_t usec; /*< Timestamp (microseconds, synced to UNIX time or since system boot)*/
 int32_t raw_value; /*< The raw value from the sonar sensor read from the ADC.*/
 float distance; /*< The measured distance from the sonar sensor.*/
 uint16_t id; /*< The internal id of the sensor.*/
} mavlink_sonar_t;

#define MAVLINK_MSG_ID_SONAR_LEN 18
#define MAVLINK_MSG_ID_150_LEN 18

#define MAVLINK_MSG_ID_SONAR_CRC 191
#define MAVLINK_MSG_ID_150_CRC 191



#define MAVLINK_MESSAGE_INFO_SONAR { \
	"SONAR", \
	4, \
	{  { "usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_sonar_t, usec) }, \
         { "raw_value", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_sonar_t, raw_value) }, \
         { "distance", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_sonar_t, distance) }, \
         { "id", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_sonar_t, id) }, \
         } \
}


/**
 * @brief Pack a sonar message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param usec Timestamp (microseconds, synced to UNIX time or since system boot)
 * @param id The internal id of the sensor.
 * @param raw_value The raw value from the sonar sensor read from the ADC.
 * @param distance The measured distance from the sonar sensor.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sonar_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint64_t usec, uint16_t id, int32_t raw_value, float distance)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SONAR_LEN];
	_mav_put_uint64_t(buf, 0, usec);
	_mav_put_int32_t(buf, 8, raw_value);
	_mav_put_float(buf, 12, distance);
	_mav_put_uint16_t(buf, 16, id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SONAR_LEN);
#else
	mavlink_sonar_t packet;
	packet.usec = usec;
	packet.raw_value = raw_value;
	packet.distance = distance;
	packet.id = id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SONAR_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_SONAR;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SONAR_LEN, MAVLINK_MSG_ID_SONAR_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SONAR_LEN);
#endif
}

/**
 * @brief Pack a sonar message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param usec Timestamp (microseconds, synced to UNIX time or since system boot)
 * @param id The internal id of the sensor.
 * @param raw_value The raw value from the sonar sensor read from the ADC.
 * @param distance The measured distance from the sonar sensor.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sonar_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint64_t usec,uint16_t id,int32_t raw_value,float distance)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SONAR_LEN];
	_mav_put_uint64_t(buf, 0, usec);
	_mav_put_int32_t(buf, 8, raw_value);
	_mav_put_float(buf, 12, distance);
	_mav_put_uint16_t(buf, 16, id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SONAR_LEN);
#else
	mavlink_sonar_t packet;
	packet.usec = usec;
	packet.raw_value = raw_value;
	packet.distance = distance;
	packet.id = id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SONAR_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_SONAR;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SONAR_LEN, MAVLINK_MSG_ID_SONAR_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SONAR_LEN);
#endif
}

/**
 * @brief Encode a sonar struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param sonar C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sonar_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_sonar_t* sonar)
{
	return mavlink_msg_sonar_pack(system_id, component_id, msg, sonar->usec, sonar->id, sonar->raw_value, sonar->distance);
}

/**
 * @brief Encode a sonar struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param sonar C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sonar_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_sonar_t* sonar)
{
	return mavlink_msg_sonar_pack_chan(system_id, component_id, chan, msg, sonar->usec, sonar->id, sonar->raw_value, sonar->distance);
}

/**
 * @brief Send a sonar message
 * @param chan MAVLink channel to send the message
 *
 * @param usec Timestamp (microseconds, synced to UNIX time or since system boot)
 * @param id The internal id of the sensor.
 * @param raw_value The raw value from the sonar sensor read from the ADC.
 * @param distance The measured distance from the sonar sensor.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_sonar_send(mavlink_channel_t chan, uint64_t usec, uint16_t id, int32_t raw_value, float distance)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SONAR_LEN];
	_mav_put_uint64_t(buf, 0, usec);
	_mav_put_int32_t(buf, 8, raw_value);
	_mav_put_float(buf, 12, distance);
	_mav_put_uint16_t(buf, 16, id);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SONAR, buf, MAVLINK_MSG_ID_SONAR_LEN, MAVLINK_MSG_ID_SONAR_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SONAR, buf, MAVLINK_MSG_ID_SONAR_LEN);
#endif
#else
	mavlink_sonar_t packet;
	packet.usec = usec;
	packet.raw_value = raw_value;
	packet.distance = distance;
	packet.id = id;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SONAR, (const char *)&packet, MAVLINK_MSG_ID_SONAR_LEN, MAVLINK_MSG_ID_SONAR_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SONAR, (const char *)&packet, MAVLINK_MSG_ID_SONAR_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_SONAR_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_sonar_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t usec, uint16_t id, int32_t raw_value, float distance)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint64_t(buf, 0, usec);
	_mav_put_int32_t(buf, 8, raw_value);
	_mav_put_float(buf, 12, distance);
	_mav_put_uint16_t(buf, 16, id);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SONAR, buf, MAVLINK_MSG_ID_SONAR_LEN, MAVLINK_MSG_ID_SONAR_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SONAR, buf, MAVLINK_MSG_ID_SONAR_LEN);
#endif
#else
	mavlink_sonar_t *packet = (mavlink_sonar_t *)msgbuf;
	packet->usec = usec;
	packet->raw_value = raw_value;
	packet->distance = distance;
	packet->id = id;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SONAR, (const char *)packet, MAVLINK_MSG_ID_SONAR_LEN, MAVLINK_MSG_ID_SONAR_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SONAR, (const char *)packet, MAVLINK_MSG_ID_SONAR_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE SONAR UNPACKING


/**
 * @brief Get field usec from sonar message
 *
 * @return Timestamp (microseconds, synced to UNIX time or since system boot)
 */
static inline uint64_t mavlink_msg_sonar_get_usec(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field id from sonar message
 *
 * @return The internal id of the sensor.
 */
static inline uint16_t mavlink_msg_sonar_get_id(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  16);
}

/**
 * @brief Get field raw_value from sonar message
 *
 * @return The raw value from the sonar sensor read from the ADC.
 */
static inline int32_t mavlink_msg_sonar_get_raw_value(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field distance from sonar message
 *
 * @return The measured distance from the sonar sensor.
 */
static inline float mavlink_msg_sonar_get_distance(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Decode a sonar message into a struct
 *
 * @param msg The message to decode
 * @param sonar C-struct to decode the message contents into
 */
static inline void mavlink_msg_sonar_decode(const mavlink_message_t* msg, mavlink_sonar_t* sonar)
{
#if MAVLINK_NEED_BYTE_SWAP
	sonar->usec = mavlink_msg_sonar_get_usec(msg);
	sonar->raw_value = mavlink_msg_sonar_get_raw_value(msg);
	sonar->distance = mavlink_msg_sonar_get_distance(msg);
	sonar->id = mavlink_msg_sonar_get_id(msg);
#else
	memcpy(sonar, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_SONAR_LEN);
#endif
}
