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