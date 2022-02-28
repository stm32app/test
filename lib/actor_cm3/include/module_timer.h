#ifndef INC_MODULE_TIMER
#define INC_MODULE_TIMER

#ifdef __cplusplus
extern "C" {
#endif

#define TIMER_UNITS 10

#include <actor_env.h>
#include "actor.h"
#include "actor_types.h"

/* Start of autogenerated OD types */
/* 0x6100: Module Timer 1
   TIM1 timer */
typedef struct module_timer_properties {
    uint8_t parameter_count;
    uint8_t prescaler;
    uint8_t initial_subscriptions_count; // How many subscriptions can timer hold at once 
    uint32_t period; // Counter overflow value (usually max value, 16 or 32bit depending on counter) 
    uint32_t frequency; // How many times a second should timer fire 
    uint8_t phase;
} module_timer_properties_t;
/* End of autogenerated OD types */

typedef struct module_timer_subscription {
    actor_t *actor;
    uint32_t time;
    void *argument;
} module_timer_subscription_t;


struct module_timer {
    actor_t *actor;
    module_timer_properties_t *properties;

    uint32_t current_time; // timestamp that gets updated on every interrupt/timer subscription
    uint32_t next_time;    // next subscription time (-1 if there arent any)
    uint32_t next_tick;   // scheduled interval (usually equals to timer period)

    uint32_t address;
    uint16_t reset;
    uint16_t clock;
    uint32_t peripheral_clock;
    uint8_t irq;
    uint8_t source;

    #ifdef DEBUG
        uint32_t debug_stopper;
    #endif
    
    module_timer_subscription_t *subscriptions;
};


extern actor_class_t module_timer_class;

// set/update alarm timeout in microseconds from now (per actor/argument pair), start timer if needed
actor_signal_t module_timer_timeout(module_timer_t *timer, actor_t *actor, void *argument, uint32_t timeout);

// clear alarm for given actor/argument pair, deschedule ticks and stop timer if needed
actor_signal_t module_timer_clear(module_timer_t *timer, actor_t *actor, void *argument);

/* Start of autogenerated OD accessors */
typedef enum module_timer_properties_indecies {
  MODULE_TIMER_PRESCALER = 0x01,
  MODULE_TIMER_INITIAL_SUBSCRIPTIONS_COUNT = 0x02,
  MODULE_TIMER_PERIOD = 0x03,
  MODULE_TIMER_FREQUENCY = 0x04,
  MODULE_TIMER_PHASE = 0x05
} module_timer_properties_indecies_t;

/* 0x61XX05: null */
static inline void module_timer_set_phase(module_timer_t *timer, uint8_t value) { 
    actor_set_property_numeric(timer->actor, MODULE_TIMER_PHASE, (uint32_t)(value), sizeof(uint8_t));
}
static inline uint8_t module_timer_get_phase(module_timer_t *timer) {
    return *((uint8_t *) actor_get_property_pointer(timer->actor, MODULE_TIMER_PHASE));
}
/* End of autogenerated OD accessors */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif