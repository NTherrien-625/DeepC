#ifndef LINEAR_H
#define LINEAR_H

#include "../Matrix.h"
#include "Layer.h"

typedef struct Linear {
    // Base class for every layer
    Layer* base;
    
    // Linear layer parameters
    unsigned int input_dim;
    unsigned int output_dim;
} Linear;

Linear* malloc_Linear(unsigned int in, unsigned int out);

void free_Linear(Layer* L);

Matrixf* forward_Linear(Layer* L, Matrixf* x);

#endif
