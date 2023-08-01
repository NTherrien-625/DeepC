#ifndef MODEL_H
#define MODEL_H

#include "Layer.h"
#include "Activation.h"

typedef struct Model {
    Layer** layers;
    Activation** activations;

    unsigned int num_layers;
    unsigned int num_activations;
} Model;

Model* malloc_Model(void);

void free_Model(Model* M);

void insert_Layer(Model* M, Layer* L);

#endif
