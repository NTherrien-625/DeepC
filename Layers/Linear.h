#ifndef LAYER_H
#define LAYER_H

#include "../Matrix.h"

typedef struct Linear {
    unsigned int input_dim;
    unsigned int output_dim;
    Matrixf* weights;
} Linear;

Linear* malloc_Linear(unsigned int in, unsigned int out);

void free_Linear(Linear* L);

#endif
