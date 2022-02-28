#ifndef INC_DEV_BLANK
#define INC_DEV_BLANK

#ifdef __cplusplus
extern "C" {
#endif

#include "actor.h"

/* Start of autogenerated OD types */
typedef struct {
    uint8_t phase;
} actor_blank_properties_t;
/* End of autogenerated OD types */

struct actor_blank {
    actor_t *actor;
    actor_blank_properties_t *properties;
};


extern actor_class_t actor_blank_class;

/* Start of autogenerated OD accessors */
/* End of autogenerated OD accessors */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif