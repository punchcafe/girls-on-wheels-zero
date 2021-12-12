#include "../include/dynamic_body.h"

void dynamic_body_process(DynamicBody * body, unsigned short interval)
{
    return;
}

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

void dynamic_body_process_collision(DynamicBody * self, DynamicBody * other, unsigned short interval)
{
    return;
}