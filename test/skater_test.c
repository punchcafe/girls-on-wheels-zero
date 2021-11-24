#include "../lib/rectangle.c"
#include "../lib/skater.c"

int can_load_skater_position_into_rectangle()
{
    Skater skater = {5, 6, 2, 3, 0, 0};
    Rectangle rect;

    skater_populate_rectange(&skater, &rect);
    return rect.x_w == 3 && rect.x_e == 7 && rect.y_n == 3 && rect.y_s == 9;
}

int main()
{
    return !(can_load_skater_position_into_rectangle());
}