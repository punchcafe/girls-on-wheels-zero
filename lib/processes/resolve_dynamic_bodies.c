#include "../../include/processes/resolve_dynamic_bodies.h"
#include "../../include/rectangle.h"
#include <stdio.h>
#include <gb/gb.h>

#define X_POS_SPEED_LIMIT 5
#define X_NEG_SPEED_LIMIT -5
#define Y_POS_SPEED_LIMIT 5
#define Y_NEG_SPEED_LIMIT -5

Rectangle self_collision_rectangle;
Rectangle other_collision_rectangle;

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
        void (*process_strategy)(DynamicBody*) = dynamic_body_process_strategy(subject_body->type);
        process_strategy(subject_body);
    }

    for(int i = 0; i < number_of_bodies; i++)
    {
        DynamicBody * self_body = &body_array[i];
        if(self_body->self_collides)
        {
            // TODO: check if we can skip to i = j
            for(int j = 0; j < number_of_bodies; j++)
            {
                if(i == j)
                {
                    continue;
                }
                DynamicBody * other_body = &body_array[j];
                if(other_body->collides_others)
                {
                    dynamic_body_populate_rectangle(self_body, &self_collision_rectangle);
                    dynamic_body_populate_rectangle(other_body, &other_collision_rectangle);
                    if(rectangle_do_rectangles_collide(&self_collision_rectangle, &other_collision_rectangle))
                    {
                        void (*collision_strategy)(DynamicBody*, DynamicBody*, unsigned int) = dynamic_body_collision_strategy(self_body->type);
                        collision_strategy(self_body, other_body, 1);
                    }
                }
            }
        }
    }
    apply_forces_and_velocities(body_array, number_of_bodies, interval);
}