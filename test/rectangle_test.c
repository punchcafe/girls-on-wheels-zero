#include "../lib/rectangle.c"

int detect_right_side_rectangle_collision()
{
    Rectangle rect1 = {0,3,0,3};
    Rectangle rect2 = {2,4,0,3};
    return rectangle_do_rectangles_collide(&rect1, &rect2) > 0x00;
}

int detect_left_side_rectangle_collision()
{
    Rectangle rect1 = {2,4,0,3};
    Rectangle rect2 = {0,3,0,3};
    return rectangle_do_rectangles_collide(&rect1, &rect2) > 0x00;
}

int detect_top_side_rectangle_collision()
{
    Rectangle rect1 = {5,10,0,5};
    Rectangle rect2 = {6,10,3,6};
    return rectangle_do_rectangles_collide(&rect1, &rect2) > 0x00;
}

int detect_bottom_side_rectangle_collision()
{
    Rectangle rect2 = {5,10,0,5};
    Rectangle rect1 = {6,10,3,6};
    return rectangle_do_rectangles_collide(&rect1, &rect2) > 0x00;
}

int detect_nw_corner_rectangle_collision()
{
    Rectangle rect1 = {5,10,5,9};
    Rectangle rect2 = {0,6,0,6};
    return rectangle_do_rectangles_collide(&rect1, &rect2) > 0x00;
}

int detect_no_rectangle_collision()
{
    Rectangle rect1 = {5,10,5,9};
    Rectangle rect2 = {11,16,10,11};
    return rectangle_do_rectangles_collide(&rect1, &rect2) == 0x00;
}

int main() 
{
    return !(
        detect_right_side_rectangle_collision() 
        && detect_left_side_rectangle_collision()
        && detect_top_side_rectangle_collision()
        && detect_bottom_side_rectangle_collision()
        && detect_nw_corner_rectangle_collision()
        && detect_no_rectangle_collision()
        );
}