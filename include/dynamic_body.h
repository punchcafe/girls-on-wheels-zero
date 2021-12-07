#ifndef DYNAMIC_BODY_DEFINITION_H
#define DYNAMIC_BODY_DEFINITION_H

#include "./dynamic_body_type.h"


typedef struct DynamicBody 
{
    unsigned int x, y;
    int v_x, v_y;
    int f_x, f_y;
    unsigned int width, height;
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

void dynamic_body_process_collision(DynamicBody * self, DynamicBody * other, unsigned short interval);

// what is pragma?

#endif