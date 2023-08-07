#ifndef MODEL_H
#define MODEL_H

#include "Layer.h"
#include "Activation.h"

typedef struct Model {

    // Model members
    Layer** layers;
    Activation** activations;
    unsigned int num_layers;
    unsigned int num_activations;

    // Optimization members
    double alpha;
    double (*loss)(Tensord*, Tensord*);

} Model;

Model* malloc_Model(double lr, double (*loss)(Tensord*, Tensord*));

void free_Model(Model* M);

void insert_Layer(Model* M, Layer* L);

void insert_Activation(Model* M, Activation* A);

Tensord* forward_Model(Model* M, Tensord* x);

#endif
