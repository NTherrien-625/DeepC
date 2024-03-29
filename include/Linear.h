#ifndef LINEAR_H
#define LINEAR_H

#include "Layer.h"

typedef struct Linear {
    // Access to the base structure
    Layer* base;
} Linear;

Layer* malloc_Linear(unsigned int in, unsigned int out);

void free_Linear(Layer* L);

Tensord* forward_Linear(Layer* L, Tensord* x);

#endif
