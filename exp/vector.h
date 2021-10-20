#ifndef VECTOR_H_DEFINITION
#define VECTOR_H_DEFINITION

typedef struct Vector2D {
    int x;
    int y;
} Vector2;

typedef struct Vector3D {
    int x;
    int y;
    int z;
} Vector3;

void add_vector(Vector2 * source, Vector2 ext);

#endif