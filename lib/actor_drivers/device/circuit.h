#ifndef INC_DEV_CIRCUIT
#define INC_DEV_CIRCUIT

#ifdef __cplusplus
extern "C" {
#endif

#include "input/sensor.h"
#include "actor.h"
#include "module/adc.h"

/* Start of autogenerated OD types */
/* 0x4000: Device Circuit 1
   A relay that turns circuit on and off (pwm optional 

Can be paired with Hall Sensor to measure current for taking metrics via ADC. Applying current limit will turn relay into a circuit breaker. */
typedef struct device_circuit_properties {
    uint8_t parameter_count;
    uint8_t port;
    uint8_t pin; // Relay GPIO port (1 for A, 2 for B, etc), required 
    uint16_t limit_current; // Relay GPIO pin, required 
    uint16_t limit_voltage; // Relay will turn off if measured current surpasses this limit 
    uint16_t psu_index; // Currently there is no way to enforce voltage limit 
    uint16_t sensor_index; // PSU circuit is turned on when one of their dependends is turned on 
    uint8_t phase; // Hall sensor measures current and allows circuit to become a circuit breaker 
    uint16_t duty_cycle; // Phase x 
    uint16_t current;
    uint16_t voltage; // Current  x 
    uint8_t consumers;
} device_circuit_properties_t;
/* End of autogenerated OD types */

struct device_circuit {
    actor_t *actor;
    device_circuit_properties_t *properties;
    device_circuit_t *psu;
    input_sensor_t *current_sensor;
    module_adc_t *adc;;
};

extern actor_class_t device_circuit_class;

void device_circuit_set_state(device_circuit_t *circuit, bool state);
bool device_circuit_get_state(device_circuit_t *circuit);

/* Start of autogenerated OD accessors */
typedef enum device_circuit_properties_indecies {
  DEVICE_CIRCUIT_PORT = 0x01,
  DEVICE_CIRCUIT_PIN = 0x02,
  DEVICE_CIRCUIT_LIMIT_CURRENT = 0x03,
  DEVICE_CIRCUIT_LIMIT_VOLTAGE = 0x04,
  DEVICE_CIRCUIT_PSU_INDEX = 0x05,
  DEVICE_CIRCUIT_SENSOR_INDEX = 0x06,
  DEVICE_CIRCUIT_PHASE = 0x07,
  DEVICE_CIRCUIT_DUTY_CYCLE = 0x08,
  DEVICE_CIRCUIT_CURRENT = 0x09,
  DEVICE_CIRCUIT_VOLTAGE = 0x0A,
  DEVICE_CIRCUIT_CONSUMERS = 0x0B
} device_circuit_properties_indecies_t;

/* 0x40XX07: Hall sensor measures current and allows circuit to become a circuit breaker */
static inline void device_circuit_set_phase(device_circuit_t *circuit, uint8_t value) { 
    actor_set_property_numeric(circuit->actor, DEVICE_CIRCUIT_PHASE, (uint32_t)(value), sizeof(uint8_t));
}
static inline uint8_t device_circuit_get_phase(device_circuit_t *circuit) {
    return *((uint8_t *) actor_get_property_pointer(circuit->actor, DEVICE_CIRCUIT_PHASE));
}
/* 0x40XX08: Phase x */
static inline void device_circuit_set_duty_cycle(device_circuit_t *circuit, uint16_t value) { 
    actor_set_property_numeric(circuit->actor, DEVICE_CIRCUIT_DUTY_CYCLE, (uint32_t)(value), sizeof(uint16_t));
}
static inline uint16_t device_circuit_get_duty_cycle(device_circuit_t *circuit) {
    return *((uint16_t *) actor_get_property_pointer(circuit->actor, DEVICE_CIRCUIT_DUTY_CYCLE));
}
/* 0x40XX09: null */
static inline void device_circuit_set_current(device_circuit_t *circuit, uint16_t value) { 
    actor_set_property_numeric(circuit->actor, DEVICE_CIRCUIT_CURRENT, (uint32_t)(value), sizeof(uint16_t));
}
static inline uint16_t device_circuit_get_current(device_circuit_t *circuit) {
    return *((uint16_t *) actor_get_property_pointer(circuit->actor, DEVICE_CIRCUIT_CURRENT));
}
/* 0x40XX0A: Current  x */
static inline void device_circuit_set_voltage(device_circuit_t *circuit, uint16_t value) { 
    actor_set_property_numeric(circuit->actor, DEVICE_CIRCUIT_VOLTAGE, (uint32_t)(value), sizeof(uint16_t));
}
static inline uint16_t device_circuit_get_voltage(device_circuit_t *circuit) {
    return *((uint16_t *) actor_get_property_pointer(circuit->actor, DEVICE_CIRCUIT_VOLTAGE));
}
/* 0x40XX0B: null */
static inline void device_circuit_set_consumers(device_circuit_t *circuit, uint8_t value) { 
    actor_set_property_numeric(circuit->actor, DEVICE_CIRCUIT_CONSUMERS, (uint32_t)(value), sizeof(uint8_t));
}
static inline uint8_t device_circuit_get_consumers(device_circuit_t *circuit) {
    return *((uint8_t *) actor_get_property_pointer(circuit->actor, DEVICE_CIRCUIT_CONSUMERS));
}
/* End of autogenerated OD accessors */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* objectAccessOD_H */