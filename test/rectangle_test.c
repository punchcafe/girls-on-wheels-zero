#include "../lib/rectangle.c"

int rectangle_collision_works()
{
    Rectangle rect1 = {0,1,0,1};
    Rectangle rect2 = {0,1,0,1};
    return rectangle_do_rectangles_collide(&rect1, &rect2) == 0x00;
}

int main() 
{
    return !rectangle_collision_works();
}