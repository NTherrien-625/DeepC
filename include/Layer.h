#ifndef LAYER_H
#define LAYER_H

#include "Tensor.h"

typedef struct Layer {
    // We need to loop back around to the specialized layer for freeing
    void* spl;

    // Base struct member variables
    Tensord* weights;
    unsigned int in;
    unsigned int out;

    // Artificial VTAB
    Tensord* (*forward)(struct Layer*, Tensord*);
    void (*free_Layer)(struct Layer*);
} Layer;

#endif
