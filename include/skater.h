
#ifndef SKATER_DEFINITION_H
#define SKATER_DEFINITION_H

#include "./rectangle.h"

typedef struct Skaters {
    // TODO: extract to composable: position
    unsigned short x;
    unsigned short y;
    // TODO: extract to composeable: area
    unsigned short half_width;
    unsigned short half_height;
    // TODO: extract to composable: vector
    short vx;
    short vy;
} Skater;

void skater_jump(Skater * skater);

void skater_move(Skater * skater, signed short dx, signed short dy);

void skater_populate_rectange(Skater * skater, Rectangle * rect);

#endif