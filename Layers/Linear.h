#ifndef LINEAR_H
#define LINEAR_H

#include "../Matrix.h"
#include "Layer.h"

typedef struct Linear {
    unsigned int input_dim;
    unsigned int output_dim;
    Matrixf* weights;

    Layer* base;
} Linear;

Linear* malloc_Linear(unsigned int in, unsigned int out);

void free_Linear(void* L);

Matrixf* forward_Linear(void* L, Matrixf* x);

#endif
