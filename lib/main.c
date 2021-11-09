#include <gb/gb.h>
#include <stdio.h>
#include "../include/skater.h"


#define SKATER_SPRITE_TABLE_POSITION 1
#define SKATER_SPRITE_POSITION 1

Skater skater_singleton = {50, 50, 1, 1, 0, 0};
Skater * skater_s_pointer = &skater_singleton;

extern char skater_sprite_data [];

void initialise_skater_sprite_data()
{
    set_sprite_data(SKATER_SPRITE_TABLE_POSITION,1,skater_sprite_data);
}

void render_skater(Skater * skater)
{
    set_sprite_tile(SKATER_SPRITE_POSITION, SKATER_SPRITE_TABLE_POSITION);
    move_sprite(SKATER_SPRITE_POSITION, skater->x, skater->y);
}

int main()
{
    initialise_skater_sprite_data();
    SHOW_SPRITES;
    while(1)
    {
        unsigned char input = joypad();
        if(input & J_UP) {
            skater_jump(skater_s_pointer);
        } else if(input & J_RIGHT) {
            skater_move(skater_s_pointer, 2, 0);
        } else if(input & J_DOWN) {
        } else if(input & J_LEFT) {
            skater_move(skater_s_pointer, -2, 0);
        };
        delay(50);
        render_skater(skater_s_pointer);
    }
    return 0;
}