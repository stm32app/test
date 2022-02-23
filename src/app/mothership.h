#ifndef INC_APP_MOTHERSHIP
#define INC_APP_MOTHERSHIP

#ifdef __cplusplus
extern "C" {
#endif

#include "core/app.h"
/* Start of autogenerated OD types */
typedef struct {
    uint8_t parameter_count;
    uint32_t timer_index; // Index of a timer used for generic medium-precision scheduling (1us) 
    uint32_t storage_index;
    uint32_t mcu_index; // Main MCU actor index 
    uint32_t canopen_index; // Main CANopen actor 
    uint8_t phase;
} app_mothership_properties_t;
/* End of autogenerated OD types */

typedef struct app_mothership {
    actor_t *actor;
    app_mothership_properties_t *properties;
    size_t actor_count;
    OD_t *dictionary;
    system_mcu_t *mcu;
    system_canopen_t *canopen;
    system_database_t *database;
    module_timer_t *timer;
    app_buffer_t *buffers;

    app_thread_t *input;           /* Thread with queue of events that need immediate response*/
    app_thread_t *catchup;         /* Allow actors that were busy to catch up with input events  */
    app_thread_t *high_priority;   /* Logic that is scheduled by actors themselves */
    app_thread_t *medium_priority; /* A queue of events that concerns medium_priorityting  outside */
    app_thread_t *low_priority;    /* Logic that runs periodically that is not very important */
    app_thread_t *bg_priority;     /* A background thread of sorts for work that can be done in free time */

    app_job_t job;
    bool_t initialized;
    bool_t sdram;
} app_mothership_t;


extern actor_class_t app_mothership_class;

size_t app_mothership_enumerate_actors(app_t *app, OD_t *od, actor_t *destination);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif