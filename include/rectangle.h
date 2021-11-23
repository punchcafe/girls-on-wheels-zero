#ifndef RECTANGLE_DEFINITION_H
#define RECTANGLE_DEFINITION_H

typedef struct Rectangle {
    // change to compass points to avoid odd rectangles
    unsigned short x_w;
    unsigned short x_e;
    unsigned short y_n;
    unsigned short y_s;
} Rectangle;

unsigned char rectangle_do_rectangles_collide(Rectangle *, Rectangle *); 

#endif