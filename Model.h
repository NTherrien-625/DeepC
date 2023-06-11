#ifndef MODEL_H
#define MODEL_H

#include "Layers/Layer.h"
#include "Matrix.h"
#include "Optimizer.h"

typedef struct Model {
    Layer** layers;
    Matrixf* (**activation)(Matrixf*);
    unsigned int depth;
} Model;

Model* malloc_Model();

void free_Model(Model* M);

void insert_Layer(Layer* L, Model* M);

void insert_activation(Matrixf* (*func)(Matrixf*), Model* M);

Matrixf* forward_Model(Matrixf* x, Model* M);

void backward_Model(Matrixf* x, Matrixf* y, Optimizer* O, Model* M);

#endif
