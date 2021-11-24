#include <stdio.h>
#include "../include/skater.h"

void skater_jump(Skater * skater)
{
    skater->vy = skater->vy + 1;
}

void skater_move(Skater * skater, signed short dx, signed short dy)
{
    // TODO: handle overflow
    skater->x = skater->x + dx;
    skater->y = skater->y + dy;
}

void skater_populate_rectange(Skater * skater, Rectangle * rect){
    rect->x_w = skater->x - skater->half_width;
    rect->x_e = skater->x + skater->half_width;
    rect->y_n = skater->y - skater->half_height;
    rect->y_s = skater->y + skater->half_height;
}