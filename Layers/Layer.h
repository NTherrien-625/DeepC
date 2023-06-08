#ifndef LAYER_H
#define LAYER_H

#include "../Matrix.h"

typedef struct Layer {
    // The forward pass of the Layer
    Matrixf* (*forward)(struct Layer, Matrixf*);

    // The free of the layer
    void (*free_Layer)(void*);
} Layer;

#endif
