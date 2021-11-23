#include "../include/rectangle.h"
unsigned char rectangle_do_rectangles_collide(Rectangle * rect1, Rectangle * rect2)
{
    int x_w_inside_x_range = (rect1->x_w >= rect2->x_w) && (rect1->x_w <= rect2->x_e);
    int x_e_inside_x_range = (rect1->x_e >= rect2->x_w) && (rect1->x_e <= rect2->x_e);
    int y_n_inside_y_range = (rect1->y_n >= rect2->y_n) && (rect1->y_n <= rect2->y_s);
    int y_s_inside_y_range = (rect1->y_s >= rect2->y_n) && (rect1->y_s <= rect2->y_s);
    return (x_w_inside_x_range || x_e_inside_x_range) && (y_n_inside_y_range || y_s_inside_y_range);
}