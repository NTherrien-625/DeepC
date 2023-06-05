#ifndef MATRIX_H
#define MATRIX_H

typedef struct Matrixf {
    unsigned int rows;
    unsigned int columns;
    float data[];
} Matrixf;

Matrixf* malloc_Matrixf(unsigned int r, unsigned int c);

void free_Matrixf(Matrixf* mat);

Matrixf* mul_Matrixf(Matrixf* lhs, Matrixf* rhs);

#endif
