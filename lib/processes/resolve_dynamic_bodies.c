#include "../../include/processes/resolve_dynamic_bodies.h"

// TODO: use actual return type
void (*get_process_strategy(DynamicBody*))(DynamicBodyType type)
{
    return 0x00;
}

void resolve_dynamic_bodies(DynamicBody * body_array, unsigned int number_of_bodies, unsigned int interval){
    // resolve self first force first, then collisions
    for(int i = 0; i < number_of_bodies; i++)
    {
        DynamicBody * subject_body = &body_array[i];
        void (*process_strategy)(DynamicBody*) = get_process_strategy(subject_body->type);
        process_strategy(subject_body);
    }
}