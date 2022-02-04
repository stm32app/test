#ifndef INC_SYSTEM_CANOPEN
#define INC_SYSTEM_CANOPEN

#ifdef __cplusplus
extern "C" {
#endif

#include "core/app.h"
#include "transport/can.h"

#include <CANopen.h>
#include "OD.h"



#define NMT_CONTROL                                                                                                                        \
    CO_NMT_STARTUP_TO_OPERATIONAL                                                                                                          \
    | CO_NMT_ERR_ON_ERR_REG | CO_ERR_REG_GENERIC_ERR | CO_ERR_REG_COMMUNICATION
#define FIRST_HB_TIME 501
#define SDO_SRV_TIMEOUT_TIME 1000
#define SDO_CLI_TIMEOUT_TIME 500
#define SDO_CLI_BLOCK true
#define OD_STATUS_BITS NULL

#define CO_GET_CNT(obj) OD_CNT_##obj
#define OD_GET(entry, index) OD_ENTRY_##entry

#define app_error_report(app, errorBit, errorCode, index) CO_errorReport(app->canopen->instance->em, errorBit, errorCode, index)
#define app_error_reset(app, errorBit, errorCode, index) CO_errorReset(app->canopen->instance->em, errorBit, errorCode, index)

#define actor_error_report(actor, errorBit, errorCode) CO_errorReport(actor->app->canopen->instance->em, errorBit, errorCode, actor->index)
#define actor_error_reset(actor, errorBit, errorCode) CO_errorReset(actor->app->canopen->instance->em, errorBit, errorCode, actor->index)


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
    uint32_t bitrate; // Negotiated bitrate 
} system_canopen_properties_t;
/* End of autogenerated OD types */

struct system_canopen {
    actor_t *actor;
    system_canopen_properties_t *properties;
    indicator_led_t *green_led;
    indicator_led_t *red_led;
    transport_can_t *can;
    CO_t *instance;
} ;


extern actor_class_t system_canopen_class;


/* Start of autogenerated OD accessors */
typedef enum system_canopen_properties_properties {
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
} system_canopen_properties_properties_t;

/* 0x60XX08: null */
#define system_canopen_set_phase(canopen, value) actor_set_property_numeric(canopen->actor, (uint32_t) value, sizeof(uint8_t), SYSTEM_CANOPEN_PHASE)
#define system_canopen_get_phase(canopen) *((uint8_t *) actor_get_property_pointer(canopen->actor, &(uint8_t[sizeof(uint8_t)]{}), sizeof(uint8_t), SYSTEM_CANOPEN_PHASE)
/* 0x60XX09: Node ID */
#define system_canopen_set_node_id(canopen, value) actor_set_property_numeric(canopen->actor, (uint32_t) value, sizeof(uint8_t), SYSTEM_CANOPEN_NODE_ID)
#define system_canopen_get_node_id(canopen) *((uint8_t *) actor_get_property_pointer(canopen->actor, &(uint8_t[sizeof(uint8_t)]{}), sizeof(uint8_t), SYSTEM_CANOPEN_NODE_ID)
/* 0x60XX0A: Negotiated bitrate */
#define system_canopen_set_bitrate(canopen, value) actor_set_property_numeric(canopen->actor, (uint32_t) value, sizeof(uint32_t), SYSTEM_CANOPEN_BITRATE)
#define system_canopen_get_bitrate(canopen) *((uint32_t *) actor_get_property_pointer(canopen->actor, &(uint8_t[sizeof(uint32_t)]{}), sizeof(uint32_t), SYSTEM_CANOPEN_BITRATE)
/* End of autogenerated OD accessors */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif