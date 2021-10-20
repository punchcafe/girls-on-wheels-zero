#include "./common_types.c"

#ifndef RECTANGLE_HEADER
#define RECTANGLE_HEADER

typedef struct Rectangles {
    unsigned int anchor_x;
    unsigned int anchor_y;
    unsigned int width;
    unsigned int height;
} Rectangle;

boolean is_collision(Rectangle * rect_1, Rectangle * rect_2);

#endif