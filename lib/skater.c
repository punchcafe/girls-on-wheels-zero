#include <stdio.h>

#ifndef SKATER_DEFINITION
#define SKATER_DEFINITION 

// TODO: extract to header

typedef struct Skaters {
    // TODO: extract to composable: position
    unsigned short x;
    unsigned short y;
    // TODO: extract to composeable: area
    unsigned short width;
    unsigned short height;
    // TODO: extract to composable: vector
    short vx;
    short vy;
} Skater;

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

// extract out of skater and have a universal method for doing this for all entities.
short _move_or_clamp(unsigned short position, unsigned short limit, signed short change)
{
    if(change > 0)
    {
        if((limit - position) > change)
        {
            return position + change;
            
        } else {
            return limit;
        }
    } else {
        if((position - limit) < change)
        {
            return position + change;
            
        } else {
            return limit;
        }
    }
    
}

#endif