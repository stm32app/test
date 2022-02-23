#ifndef INC_TYPES
#define INC_TYPES

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include "definitions/enums.h"
#include "definitions/dictionary.h"

typedef bool bool_t;

// Global variable is only used for interrupts

typedef struct app app_t;                         /* Generic application object, acts as a global root */
typedef struct app_thread app_thread_t;           /* A FreeRTOS thread that handles multiple actors*/
typedef struct app_threads app_threads_t;         /* List of built in threads in order corresponding to actor ticks*/
typedef struct app_event app_event_t;             /* Data sent between actors placed into a bus */
typedef enum app_event_status app_event_status_t; /* Status of event interaction with actor */
typedef enum app_event_type app_event_type_t;     /* Possible types of messages */
typedef struct actor actor_t;                     /* Generic object container correspondig to Object Dictionary entry */
typedef struct actor_worker actor_worker_t;           /* A actor callback running within specific app thread*/
typedef struct actor_workers actor_workers_t;         /* List of actor tick handlers in order corresponding to app threads */
typedef struct actor_class actor_class_t;         /* Method list to essentially subclass actors */
typedef enum actor_type actor_type_t;             /* List of actor groups found in Object Dictionary*/
typedef enum actor_phase actor_phase_t;           /* All phases that actor can be in*/
typedef enum app_signal app_signal_t;             /* Things that actor tell each other */
typedef struct app_job app_job_t;               /* State machine dealing with high_priority commands*/
typedef enum app_job_signal app_job_signal_t;   /* Commands to advance step machine*/
typedef struct actor_blank actor_blank_t; /* Example blank actor */
typedef struct app_buffer app_buffer_t; /* Growable owned buffer */
typedef struct app_double_buffer app_double_buffer_t; /* Typical read operation for peripheral*/
typedef app_job_signal_t (*actor_on_job_complete_t)(app_job_t *job);
typedef app_signal_t (*actor_on_event_report_t)(void *object, app_event_t *event);
typedef app_signal_t (*actor_on_worker_t)(void *object, app_event_t *event, actor_worker_t *tick, app_thread_t *thread);
typedef app_signal_t (*actor_on_phase_t)(void *object, actor_phase_t phase);
typedef app_signal_t (*actor_on_value_t)(void *object, actor_t *actor, void *value, void *argument);
typedef app_signal_t (*actor_on_link_t)(void *object, actor_t *actor, void *argument);
typedef app_signal_t (*actor_on_signal_t)(void *object, actor_t *actor, app_signal_t signal, void *argument);
typedef app_signal_t (*actor_on_buffer_allocation_t)(void *object, app_buffer_t *buffer, uint32_t size);
typedef actor_worker_t *(*on_worker_assignment_t)(void *object, app_thread_t *thread);

typedef app_signal_t (*app_method_t)(void *object);


typedef struct app_generic_device_t app_generic_device_t; // unknown polymorphic object type

#endif