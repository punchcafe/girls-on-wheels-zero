#include <gb/gb.h>
#include <stdio.h>
#include "../include/skater.h"
#include "../include/dynamic_body.h"
#include "../include/processes/resolve_dynamic_bodies.h"


#define SKATER_SPRITE_TABLE_POSITION 1
#define SKATER_SPRITE_POSITION 1

Skater skater_singleton = {50, 50, 1, 1, 0, 0};
Skater * skater_s_pointer = &skater_singleton;

DynamicBody bodies [] = {{40, 0, 0, 0, 0, 0, 2, 2, 1, 0x00, 0x01, 0x00}};

extern char skater_sprite_data [];

void initialise_skater_sprite_data()
{
    set_sprite_data(SKATER_SPRITE_TABLE_POSITION,1,skater_sprite_data);
}

void render_skater(DynamicBody * skater)
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
        wait_vbl_done();

        /*
        unsigned char input = joypad();
        if(input & J_UP) {
            skater_jump(skater_s_pointer);
        } else if(input & J_RIGHT) {
            skater_move(skater_s_pointer, 1, 0);
        } else if(input & J_DOWN) {
        } else if(input & J_LEFT) {
            skater_move(skater_s_pointer, -1, 0);
        };
        */
        render_skater(bodies);
        resolve_dynamic_bodies(bodies, 1, 1);
        delay(20);
    }
    return 0;
}