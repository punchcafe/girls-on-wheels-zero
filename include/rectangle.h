#ifndef RECTANGLE_DEFINITION_H
#define RECTANGLE_DEFINITION_H

typedef struct Rectangle {
    unsigned short x1;
    unsigned short x2;
    unsigned short y1;
    unsigned short y2;
} Rectangle;

unsigned char rectangle_do_rectangles_collide(Rectangle *, Rectangle *); 

#endif