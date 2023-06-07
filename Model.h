#ifndef MODEL_H
#define MODEL_H

#include "Layers/Layer.h"
#include "Matrix.h"

typedef struct Model {
    Layer* layers;
    Matrixf* (**activation)(Matrixf*);
    int depth;
} Model;

Model* malloc_Model();

void free_Model(Model* M);

#endif
