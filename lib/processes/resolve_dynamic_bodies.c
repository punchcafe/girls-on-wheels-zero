#include "../../include/processes/resolve_dynamic_bodies.h"
#include <stdio.h>
#include <gb/gb.h>

#define X_POS_SPEED_LIMIT 5
#define X_NEG_SPEED_LIMIT -5
#define Y_POS_SPEED_LIMIT 5
#define Y_NEG_SPEED_LIMIT -5


void do_gravity(DynamicBody * body){
    body->f_y = 1;
}

void do_player(DynamicBody * body){
    unsigned char input = joypad();
    if(input & J_RIGHT) {
        // TODO:  use calculated force impulse instead with interval
        body->v_x = 3;
    } else if(input & J_LEFT) {
        body->v_x = -3;
    } else {
        body->v_x = 0;
    };
    do_gravity(body);
}
void do_nothing(DynamicBody * body){
}

// TODO: use actual return type
void (*get_process_strategy(DynamicBody* body))(DynamicBodyType type)
{
    if(type == PLAYER)
    {
        return &do_player;
    } else {
        return &do_player;
    }
}

int clamp(int value, int max, int min)
{
    if(value < min)
    {
        return min;
    } else if (value > max) {
        return max;
    } else {
        return value;
    }
}

void apply_forces_and_velocities(DynamicBody * body_array, unsigned int number_of_bodies, unsigned int interval)
{
    for(int i = 0; i < number_of_bodies; i++)
    {
        DynamicBody * subject_body = &body_array[i];
        // add speed cap
        subject_body->v_x = clamp(subject_body->v_x + (subject_body->f_x * interval), X_POS_SPEED_LIMIT, X_NEG_SPEED_LIMIT);
        subject_body->v_y = clamp(subject_body->v_y + (subject_body->f_y * interval), Y_POS_SPEED_LIMIT, Y_NEG_SPEED_LIMIT);
        subject_body->x = subject_body->x + (subject_body->v_x * interval);
        subject_body->y = subject_body->y + (subject_body->v_y * interval);
    }
}

void resolve_dynamic_bodies(DynamicBody * body_array, unsigned int number_of_bodies, unsigned int interval)
{
    // resolve self first force first, then collisions
    for(int i = 0; i < number_of_bodies; i++)
    {
        DynamicBody * subject_body = &body_array[i];
        // reset forces
        subject_body->f_x = 0;
        subject_body->f_y = 0;
        void (*process_strategy)(DynamicBody*) = get_process_strategy(subject_body->type);
        process_strategy(subject_body);
    }
    apply_forces_and_velocities(body_array, number_of_bodies, interval);
}