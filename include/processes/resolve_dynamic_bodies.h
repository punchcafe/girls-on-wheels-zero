#ifndef RESOLVE_DYNAMIC_BODIES_DEFINITION_H
#define RESOLVE_DYNAMIC_BODIES_DEFINITION_H

#include "../dynamic_body.h"

void resolve_dynamic_bodies(DynamicBody * collidable_body_array, 
                            unsigned int number_of_bodies, 
                            DynamicBody * skater_body_array, 
                            unsigned int number_of_skaters, 
                            unsigned int interval);

#endif