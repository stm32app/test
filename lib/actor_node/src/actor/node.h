#ifndef INC_CORE_APP
#define INC_CORE_APP
/* Generic types for all apps.

Any node type can be cast to this type and get access to generic properties properties and objects */

#ifdef __cplusplus
extern "C" {
#endif

// #include <FreeRTOS.h>
#include <actor/types.h>
#include <actor.h>
#include <actor/types.h>
#include <actor/env.h>

/* Start of autogenerated OD types */
/* 0x3000: Core App
   Configuration of global object */
typedef struct actor_properties {
    uint8_t parameter_count;
    uint32_t timer_index; // Index of a timer used for generic medium-precision scheduling (1us) 
    uint32_t storage_index;
    uint32_t mcu_index; // Main MCU device index 
    uint32_t canopen_index; // Main CANopen device 
    uint8_t phase;
} actor_properties_t;
/* End of autogenerated OD types */

struct actor_node {
    actor_t *actor;
    actor_properties_t *properties;
    size_t actor_count;
    OD_t *dictionary;
    void *mcu;
#if ACTOR_USE_CANOPEN
    void *canopen;
#endif
#if ACTOR_USE_DATABASE
    void *database;
#endif
    void *timer;
    actor_buffer_t *buffers;
    actor_buffer_t *jobs;

    actor_thread_t *input;           /* Thread with queue of events that need immediate response*/
    actor_thread_t *catchup;         /* Allow actors that were busy to catch up with input events  */
    actor_thread_t *high_priority;   /* Logic that is scheduled by actors themselves */
    actor_thread_t *medium_priority; /* A queue of events that concerns medium_priorityting  outside */
    actor_thread_t *low_priority;    /* Logic that runs periodically that is not very important */
    actor_thread_t *bg_priority;     /* A background thread of sorts for work that can be done in free time */
};

// Initialize array of all actors found in OD that can be initialized
int actor_node_allocate(actor_node_t **node, OD_t *od, size_t (*enumerator)(actor_node_t *node, OD_t *od, actor_t *actors));
// Destruct all actors and release memory
int actor_node_deallocate(actor_node_t **node);
// Transition all actors to given state
void actor_node_set_phase(actor_node_t *node, actor_phase_t phase);

size_t actor_node_type_enumerate(actor_node_t *node, OD_t *od, actor_class_t *class, actor_t *destination, size_t offset);

/* Find actor by index in the global list of registered actors */
actor_t *actor_node_find(actor_node_t *node, uint16_t index);
/* Find actor by type in the global list of registered actors */
actor_t *actor_node_find_by_type(actor_node_t *node, uint16_t type);
/* Return actor from a global array by its index */
actor_t *actor_node_find_by_number(actor_node_t *node, uint8_t number);
/* Get numeric index of a actor in a global array */
uint8_t actor_node_find_number(actor_node_t *node, actor_t *actor);

/* Create buffer that will hold other buffers in the node */
actor_buffer_t *actor_buffer_pool_allocate(actor_node_t *node);



typedef enum actor_properties_properties {
    CORE_ACTOR_TIMER_INDEX = 0x1,
    CORE_ACTOR_STORAGE_INDEX = 0x2,
    CORE_ACTOR_MCU_INDEX = 0x3,
    CORE_ACTOR_CANOPEN_INDEX = 0x4,
    CORE_ACTOR_PHASE = 0x5
} actor_properties_properties_t;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif