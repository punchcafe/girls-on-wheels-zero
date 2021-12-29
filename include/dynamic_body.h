#ifndef DYNAMIC_BODY_DEFINITION_H
#define DYNAMIC_BODY_DEFINITION_H

#include "./dynamic_body_type.h"
#include "./rectangle.h"

typedef struct DynamicBody 
{
    unsigned int x, y;
    int v_x, v_y;
    int f_x, f_y;
    unsigned int width, height;
    /* 
      having skater here would allow us to track skaters last position, as part of it's process,
      without having to do it for all dynamic types. Could also be more generic, and have MOVING_BODY, or something
      but that is unlikely to be useful, and would probably require allowing for multiple subtypes.
    */
    DynamicBodyType type;
    void * type_body;
    // use this to skip things for which collisions don't affect them, i.e. blocks
    // consider making this part of the type somehow, maybe a type_spec
    unsigned short self_collides;
    // whether this can collide with others, i.e. whether others should check against for collision
    unsigned short collides_others;
} DynamicBody;

// TODO: make generic by having a config struct which is handled generically. Need to figure out 
// how to avoid having to modify the Type enum to do this first though.
void (*dynamic_body_process_strategy(DynamicBody* body, unsigned short interval))(DynamicBodyType type);

void (*dynamic_body_collision_strategy(DynamicBody* self, DynamicBody* other, unsigned short interval))(DynamicBodyType self_type);

void dynamic_body_populate_rectangle(DynamicBody * body, Rectangle * rectangle);

// what is pragma?

#endif