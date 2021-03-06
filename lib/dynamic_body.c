#include "../include/dynamic_body.h"

#include <gb/gb.h>

void dynamic_body_populate_rectangle(DynamicBody * body, Rectangle * rectangle)
{
    unsigned short half_width = body->width / 2;
    unsigned short half_height = body->height / 2;
    rectangle->x_w = body->x - half_width;
    rectangle->x_e = body->x + half_width;
    rectangle->y_n = body->y - half_height;
    rectangle->y_s = body->y + half_height;
    return;
}

void _do_gravity(DynamicBody * body){
    body->f_y = 1;
}

void _do_player(DynamicBody * body){
    unsigned char input = joypad();
    if(input & J_RIGHT) {
        // TODO:  use calculated force impulse instead with interval
        body->v_x = 3;
    } else if(input & J_LEFT) {
        body->v_x = -3;
    } else {
        body->v_x = 0;
    };
    _do_gravity(body);
}

void _do_nothing(DynamicBody * body){
}

void _collision_stop_body(DynamicBody* self_body, DynamicBody* other, unsigned short interval)
{
    unsigned char input = joypad();
    self_body->f_y = 0;
    self_body->v_y = 0;
    if(input & J_A)
    {
        self_body->f_y = -10;
    }
}

void (*dynamic_body_process_strategy(DynamicBody* body, unsigned short interval))(DynamicBodyType type)
{
    if(type == PLAYER)
    {
        return &_do_player;
    } else {
        return &_do_nothing;
    }
}

void (*dynamic_body_collision_strategy(DynamicBody* self, DynamicBody* other, unsigned short interval))(DynamicBodyType self_type)
{
    return &_collision_stop_body;
}
