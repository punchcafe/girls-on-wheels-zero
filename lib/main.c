#include <gb/gb.h>
#include <stdio.h>
#include "../include/skater.h"
#include "../include/dynamic_body.h"
#include "../include/processes/resolve_dynamic_bodies.h"


#define SKATER_SPRITE_TABLE_POSITION 1
#define SKATER_SPRITE_POSITION 1

/*
    Note on collision bodies:
    Can keep track of skater's last position (could do all, but would be a waste)
    Hook into the "observable" idea, or just do it on the self process, before anything else.
    This will allow us to know with more certainty which side a collision has happened from.
*/

Skater skater_singleton = {50, 50, 1, 1, 0, 0};
Skater * skater_s_pointer = &skater_singleton;

DynamicBody skater_bodies [] = {{40, 0, 0, 0, 0, 0, 8, 8, 0, 0x00, 0x01, 0x00}};
DynamicBody collidable_bodies [] = { 
{40, 120, 0, 0, 0, 0, 8, 8, 1, 0x00, 0x01, 0x01},
 {70, 120, 0, 0, 0, 0, 8, 8, 1, 0x00, 0x01, 0x01},
  {100, 120, 0, 0, 0, 0, 8, 8, 1, 0x00, 0x00, 0x01},
   {130, 120, 0, 0, 0, 0, 8, 8, 1, 0x00, 0x00, 0x01},
   {40, 120, 0, 0, 0, 0, 8, 8, 1, 0x00, 0x00, 0x01},
 {70, 120, 0, 0, 0, 0, 8, 8, 1, 0x00, 0x00, 0x01},
  {100, 120, 0, 0, 0, 0, 8, 8, 1, 0x00, 0x00, 0x01},
   {130, 120, 0, 0, 0, 0, 8, 8, 1, 0x00, 0x00, 0x01},
   {40, 120, 0, 0, 0, 0, 8, 8, 1, 0x00, 0x00, 0x01},
 {70, 120, 0, 0, 0, 0, 8, 8, 1, 0x00, 0x00, 0x01},
  {100, 120, 0, 0, 0, 0, 8, 8, 1, 0x00, 0x00, 0x01},
   {130, 120, 0, 0, 0, 0, 8, 8, 1, 0x00, 0x00, 0x01},
   {40, 0, 0, 0, 0, 0, 8, 8, 0, 0x00, 0x01, 0x00}, 
{40, 120, 0, 0, 0, 0, 8, 8, 1, 0x00, 0x00, 0x01},
 {70, 120, 0, 0, 0, 0, 8, 8, 1, 0x00, 0x00, 0x01},
  {100, 120, 0, 0, 0, 0, 8, 8, 1, 0x00, 0x00, 0x01},
   {130, 120, 0, 0, 0, 0, 8, 8, 1, 0x00, 0x00, 0x01},
   {40, 120, 0, 0, 0, 0, 8, 8, 1, 0x00, 0x00, 0x01},
 {70, 120, 0, 0, 0, 0, 8, 8, 1, 0x00, 0x00, 0x01},
  {100, 120, 0, 0, 0, 0, 8, 8, 1, 0x00, 0x00, 0x01},
   {130, 120, 0, 0, 0, 0, 8, 8, 1, 0x00, 0x00, 0x01},
   {40, 120, 0, 0, 0, 0, 8, 8, 1, 0x00, 0x00, 0x01},
 {70, 120, 0, 0, 0, 0, 8, 8, 1, 0x00, 0x00, 0x01},
  {100, 120, 0, 0, 0, 0, 8, 8, 1, 0x00, 0x00, 0x01},
 {70, 120, 0, 0, 0, 0, 8, 8, 1, 0x00, 0x00, 0x01},
  {100, 120, 0, 0, 0, 0, 8, 8, 1, 0x00, 0x00, 0x01},
   {130, 120, 0, 0, 0, 0, 8, 8, 1, 0x00, 0x00, 0x01},
   {40, 120, 0, 0, 0, 0, 8, 8, 1, 0x00, 0x00, 0x01},
 {70, 120, 0, 0, 0, 0, 8, 8, 1, 0x00, 0x00, 0x01},
  {100, 120, 0, 0, 0, 0, 8, 8, 1, 0x00, 0x00, 0x01}};

extern char skater_sprite_data [];

void initialise_skater_sprite_data()
{
    set_sprite_tile(2, SKATER_SPRITE_TABLE_POSITION);
    set_sprite_tile(3, SKATER_SPRITE_TABLE_POSITION);
    set_sprite_tile(4, SKATER_SPRITE_TABLE_POSITION);
    set_sprite_tile(5, SKATER_SPRITE_TABLE_POSITION);
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
        render_skater(skater_bodies);
        move_sprite(2, collidable_bodies[1].x, collidable_bodies[1].y);
        move_sprite(3, collidable_bodies[2].x, collidable_bodies[2].y);
        move_sprite(4, collidable_bodies[3].x, collidable_bodies[3].y);
        move_sprite(5, collidable_bodies[4].x, collidable_bodies[4].y);
        resolve_dynamic_bodies(collidable_bodies, 25,skater_bodies ,1, 1);
    }
    return 0;
}