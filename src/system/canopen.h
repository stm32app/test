#ifndef INC_SYSTEM_CANOPEN
#define INC_SYSTEM_CANOPEN

#ifdef __cplusplus
extern "C" {
#endif

#include "core/actor.h"

#include "OD.h"
#include <CANopen.h>


/* Start of autogenerated OD types */
/* 0x6020: System CANopen
   CANOpen framework */
typedef struct system_canopen_properties {
    uint8_t parameter_count;
    uint16_t can_index; // Values other than zero will prevent device from initializing 
    uint8_t can_fifo_index; // Values other than zero will prevent device from initializing 
    uint16_t green_led_index;
    uint16_t red_led_index;
    uint16_t first_hb_time;
    uint16_t sdo_server_timeout; // in MS 
    uint16_t sdo_client_timeout; // in MS 
    uint8_t phase;
    uint8_t node_id; // Node ID 
    uint16_t bitrate; // Negotiated bitrate 
} system_canopen_properties_t;
/* End of autogenerated OD types */

struct system_canopen {
    actor_t *actor;
    system_canopen_properties_t *properties;
    indicator_led_t *green_led;
    indicator_led_t *red_led;
    transport_can_t *can;
    CO_t *instance;
};

extern actor_class_t system_canopen_class;

/* Start of autogenerated OD accessors */
typedef enum system_canopen_properties_indecies {
  SYSTEM_CANOPEN_CAN_INDEX = 0x01,
  SYSTEM_CANOPEN_CAN_FIFO_INDEX = 0x02,
  SYSTEM_CANOPEN_GREEN_LED_INDEX = 0x03,
  SYSTEM_CANOPEN_RED_LED_INDEX = 0x04,
  SYSTEM_CANOPEN_FIRST_HB_TIME = 0x05,
  SYSTEM_CANOPEN_SDO_SERVER_TIMEOUT = 0x06,
  SYSTEM_CANOPEN_SDO_CLIENT_TIMEOUT = 0x07,
  SYSTEM_CANOPEN_PHASE = 0x08,
  SYSTEM_CANOPEN_NODE_ID = 0x09,
  SYSTEM_CANOPEN_BITRATE = 0x0A
} system_canopen_properties_indecies_t;

/* 0x60XX08: null */
static inline void system_canopen_set_phase(system_canopen_t *canopen, uint8_t value) { 
    actor_set_property_numeric(canopen->actor, SYSTEM_CANOPEN_PHASE, (uint32_t)(value), sizeof(uint8_t));
}
static inline uint8_t system_canopen_get_phase(system_canopen_t *canopen) {
    return *((uint8_t *) actor_get_property_pointer(canopen->actor, SYSTEM_CANOPEN_PHASE));
}
/* 0x60XX09: Node ID */
static inline void system_canopen_set_node_id(system_canopen_t *canopen, uint8_t value) { 
    actor_set_property_numeric(canopen->actor, SYSTEM_CANOPEN_NODE_ID, (uint32_t)(value), sizeof(uint8_t));
}
static inline uint8_t system_canopen_get_node_id(system_canopen_t *canopen) {
    return *((uint8_t *) actor_get_property_pointer(canopen->actor, SYSTEM_CANOPEN_NODE_ID));
}
/* 0x60XX0A: Negotiated bitrate */
static inline void system_canopen_set_bitrate(system_canopen_t *canopen, uint16_t value) { 
    actor_set_property_numeric(canopen->actor, SYSTEM_CANOPEN_BITRATE, (uint32_t)(value), sizeof(uint16_t));
}
static inline uint16_t system_canopen_get_bitrate(system_canopen_t *canopen) {
    return *((uint16_t *) actor_get_property_pointer(canopen->actor, SYSTEM_CANOPEN_BITRATE));
}
/* End of autogenerated OD accessors */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif