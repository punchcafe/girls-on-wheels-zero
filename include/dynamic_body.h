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

// potentially assume interval is one
void dynamic_body_process(DynamicBody * body, unsigned short interval);

void dynamic_body_populate_rectangle(DynamicBody * body, Rectangle * rectangle);

void dynamic_body_process_collision(DynamicBody * self, DynamicBody * other, unsigned short interval);

// what is pragma?

#endif