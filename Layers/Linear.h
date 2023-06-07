#ifndef LINEAR_H
#define LINEAR_H

#include "../Matrix.h"
#include "Layer.h"

typedef struct Linear {
    Layer base;
    
    unsigned int input_dim;
    unsigned int output_dim;
    Matrixf* weights;
} Linear;

Linear* malloc_Linear(unsigned int in, unsigned int out);

void free_Linear(Linear* L);

Matrixf* forward_Linear(Linear* L, Matrixf* x);

#endif
