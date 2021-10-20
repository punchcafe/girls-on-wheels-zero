#ifndef SKATER_HEADER
#define SKATER_HEADER

typedef struct Skaters {
    unsigned int x;
    unsigned int y;
} Skater;

void skater_jump(Skater * skater);

void skater_move(Skater * skater, unsigned int x, unsigned int y);

#endif