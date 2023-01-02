#ifndef INC_CORE_APP
#define INC_CORE_APP
/* Generic types for all apps.

Any node type can be cast to this type and get access to generic properties properties and objects */

#ifdef __cplusplus
extern "C" {
#endif

#include "301/CO_ODinterface.h"
#include <actor/accessors.h>
#include <actor/actor.h>
#include <actor/env.h>
#include <actor/thread.h>
#include <actor/types.h>

#ifdef OD_CONFIG
#include ACTOR_CONFIG_PATH(OD_CONFIG)
#endif

/* Start of autogenerated OD types */
/* 0x3000: Actor Node
   Configuration of global object */
typedef struct actor_node_properties {
    uint8_t parameter_count;
    uint32_t timer_index; // Index of a timer used for generic medium-precision scheduling (1us)
    uint32_t storage_index;
    uint32_t mcu_index;     // Main MCU device index
    uint32_t canopen_index; // Main CANopen device
    uint8_t phase;
} actor_node_properties_t;
/* End of autogenerated OD types */

/* Node is a root actor, representing a single device in CAN network*/
struct actor_node {
    actor_t *actor;
    void *properties;
    size_t actor_count;
    OD_t *dictionary;

    actor_buffer_t *buffers;         /* Pool of buffers available for taking */
    actor_buffer_t *jobs;            /* Pool of reusable jobs*/
    actor_buffer_t *mutexes;         /* Pool of reusable mutexes */
    
    actor_thread_t *input;           /* Thread with queue of events that need immediate response*/
    actor_thread_t *catchup;         /* Allow actors that were busy to catch up with input events  */
    actor_thread_t *high_priority;   /* Logic that is scheduled by actors themselves */
    actor_thread_t *medium_priority; /* A queue of events that concerns medium_priorityting  outside */
    actor_thread_t *low_priority;    /* Logic that runs periodically that is not very important */
    actor_thread_t *bg_priority;     /* A background thread of sorts for work that can be done in free time */

    actor_t *mcu;
#if ACTOR_NODE_USE_CANOPEN
    actor_t *canopen;
#endif
#if ACTOR_NODE_USE_DATABASE
    actor_t *database;
#endif
    actor_t *timer;
};

/* Initialize array of all actors found in OD that can be initialized */
int actor_node_allocate(actor_node_t **node, OD_t *od, size_t (*enumerator)(actor_node_t *node, OD_t *od, actor_t *actors));
/* Destruct all actors and release memory */
int actor_node_deallocate(actor_node_t **node);
/* Transition all actors to given state */
void actor_node_actors_set_phase(actor_node_t *node, actor_phase_t phase);

/* Count or initialize all actors in OD of given type. When destination argument is NULL, 
only return count of devices, so the buffer of a proper size can be allocated. 
Thus it does not produce any side effects */
size_t actor_node_type_enumerate(actor_node_t *node, OD_t *od, actor_interface_t *actor_interface, actor_t *destination, size_t offset);

/* Find actor by index in the global list of registered actors */
actor_t *actor_node_find(actor_node_t *node, uint16_t index);
/* Find actor by type in the global list of registered actors */
actor_t *actor_node_find_by_type(actor_node_t *node, uint16_t type);
/* Return actor from a global array by its numerical index */
actor_t *actor_node_find_by_number(actor_node_t *node, uint8_t number);
/* Get numeric index of a actor in a global array */
uint8_t actor_node_find_number(actor_node_t *node, actor_t *actor);

/* Create buffer that will hold other buffers in the node */
actor_buffer_t *actor_buffer_pool_allocate(actor_node_t *node);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif