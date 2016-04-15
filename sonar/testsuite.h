/** @file
 *	@brief MAVLink comm protocol testsuite generated from sonar.xml
 *	@see http://qgroundcontrol.org/mavlink/
 */
#ifndef SONAR_TESTSUITE_H
#define SONAR_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_common(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_sonar(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_common(system_id, component_id, last_msg);
	mavlink_test_sonar(system_id, component_id, last_msg);
}
#endif

#include "../common/testsuite.h"


static void mavlink_test_sonar(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_sonar_t packet_in = {
		93372036854775807ULL,963497880,101.0,18067
    };
	mavlink_sonar_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.usec = packet_in.usec;
        	packet1.raw_value = packet_in.raw_value;
        	packet1.distance = packet_in.distance;
        	packet1.id = packet_in.id;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_sonar_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_sonar_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_sonar_pack(system_id, component_id, &msg , packet1.usec , packet1.id , packet1.raw_value , packet1.distance );
	mavlink_msg_sonar_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_sonar_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.usec , packet1.id , packet1.raw_value , packet1.distance );
	mavlink_msg_sonar_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_sonar_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_sonar_send(MAVLINK_COMM_1 , packet1.usec , packet1.id , packet1.raw_value , packet1.distance );
	mavlink_msg_sonar_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_collision(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_collision_t packet_in = {
		93372036854775807ULL,73.0
    };
	mavlink_collision_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.usec = packet_in.usec;
        	packet1.front = packet_in.front;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_collision_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_collision_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_collision_pack(system_id, component_id, &msg , packet1.usec , packet1.front );
	mavlink_msg_collision_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_collision_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.usec , packet1.front );
	mavlink_msg_collision_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_collision_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_collision_send(MAVLINK_COMM_1 , packet1.usec , packet1.front );
	mavlink_msg_collision_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_sonar(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_sonar(system_id, component_id, last_msg);
	mavlink_test_collision(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // SONAR_TESTSUITE_H
