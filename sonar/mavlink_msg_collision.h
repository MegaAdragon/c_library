// MESSAGE COLLISION PACKING

#define MAVLINK_MSG_ID_COLLISION 151

typedef struct __mavlink_collision_t
{
 uint64_t usec; /*< Timestamp (microseconds, synced to UNIX time or since system boot)*/
 float front; /*< collision value in front of the drone.*/
} mavlink_collision_t;

#define MAVLINK_MSG_ID_COLLISION_LEN 12
#define MAVLINK_MSG_ID_151_LEN 12

#define MAVLINK_MSG_ID_COLLISION_CRC 223
#define MAVLINK_MSG_ID_151_CRC 223



#define MAVLINK_MESSAGE_INFO_COLLISION { \
	"COLLISION", \
	2, \
	{  { "usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_collision_t, usec) }, \
         { "front", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_collision_t, front) }, \
         } \
}


/**
 * @brief Pack a collision message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param usec Timestamp (microseconds, synced to UNIX time or since system boot)
 * @param front collision value in front of the drone.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_collision_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint64_t usec, float front)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_COLLISION_LEN];
	_mav_put_uint64_t(buf, 0, usec);
	_mav_put_float(buf, 8, front);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_COLLISION_LEN);
#else
	mavlink_collision_t packet;
	packet.usec = usec;
	packet.front = front;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_COLLISION_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_COLLISION;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_COLLISION_LEN, MAVLINK_MSG_ID_COLLISION_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_COLLISION_LEN);
#endif
}

/**
 * @brief Pack a collision message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param usec Timestamp (microseconds, synced to UNIX time or since system boot)
 * @param front collision value in front of the drone.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_collision_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint64_t usec,float front)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_COLLISION_LEN];
	_mav_put_uint64_t(buf, 0, usec);
	_mav_put_float(buf, 8, front);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_COLLISION_LEN);
#else
	mavlink_collision_t packet;
	packet.usec = usec;
	packet.front = front;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_COLLISION_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_COLLISION;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_COLLISION_LEN, MAVLINK_MSG_ID_COLLISION_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_COLLISION_LEN);
#endif
}

/**
 * @brief Encode a collision struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param collision C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_collision_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_collision_t* collision)
{
	return mavlink_msg_collision_pack(system_id, component_id, msg, collision->usec, collision->front);
}

/**
 * @brief Encode a collision struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param collision C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_collision_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_collision_t* collision)
{
	return mavlink_msg_collision_pack_chan(system_id, component_id, chan, msg, collision->usec, collision->front);
}

/**
 * @brief Send a collision message
 * @param chan MAVLink channel to send the message
 *
 * @param usec Timestamp (microseconds, synced to UNIX time or since system boot)
 * @param front collision value in front of the drone.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_collision_send(mavlink_channel_t chan, uint64_t usec, float front)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_COLLISION_LEN];
	_mav_put_uint64_t(buf, 0, usec);
	_mav_put_float(buf, 8, front);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COLLISION, buf, MAVLINK_MSG_ID_COLLISION_LEN, MAVLINK_MSG_ID_COLLISION_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COLLISION, buf, MAVLINK_MSG_ID_COLLISION_LEN);
#endif
#else
	mavlink_collision_t packet;
	packet.usec = usec;
	packet.front = front;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COLLISION, (const char *)&packet, MAVLINK_MSG_ID_COLLISION_LEN, MAVLINK_MSG_ID_COLLISION_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COLLISION, (const char *)&packet, MAVLINK_MSG_ID_COLLISION_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_COLLISION_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_collision_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t usec, float front)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint64_t(buf, 0, usec);
	_mav_put_float(buf, 8, front);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COLLISION, buf, MAVLINK_MSG_ID_COLLISION_LEN, MAVLINK_MSG_ID_COLLISION_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COLLISION, buf, MAVLINK_MSG_ID_COLLISION_LEN);
#endif
#else
	mavlink_collision_t *packet = (mavlink_collision_t *)msgbuf;
	packet->usec = usec;
	packet->front = front;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COLLISION, (const char *)packet, MAVLINK_MSG_ID_COLLISION_LEN, MAVLINK_MSG_ID_COLLISION_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COLLISION, (const char *)packet, MAVLINK_MSG_ID_COLLISION_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE COLLISION UNPACKING


/**
 * @brief Get field usec from collision message
 *
 * @return Timestamp (microseconds, synced to UNIX time or since system boot)
 */
static inline uint64_t mavlink_msg_collision_get_usec(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field front from collision message
 *
 * @return collision value in front of the drone.
 */
static inline float mavlink_msg_collision_get_front(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Decode a collision message into a struct
 *
 * @param msg The message to decode
 * @param collision C-struct to decode the message contents into
 */
static inline void mavlink_msg_collision_decode(const mavlink_message_t* msg, mavlink_collision_t* collision)
{
#if MAVLINK_NEED_BYTE_SWAP
	collision->usec = mavlink_msg_collision_get_usec(msg);
	collision->front = mavlink_msg_collision_get_front(msg);
#else
	memcpy(collision, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_COLLISION_LEN);
#endif
}
