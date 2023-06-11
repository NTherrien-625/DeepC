#ifndef LAYER_H
#define LAYER_H

#include "../Matrix.h"

typedef struct Layer {
    // The address of its specialized Layer
    void* layer;

    // The weights of the specialized layer
    void* weights;
    unsigned int num_weights;

    // The forward pass of the specialized Layer
    Matrixf* (*forward)(struct Layer*, Matrixf*);

    // The free of the specialized Layer
    void (*free_Layer)(struct Layer*);
} Layer;

#endif
