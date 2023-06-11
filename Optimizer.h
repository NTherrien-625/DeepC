#ifndef OPTIMIZER_H
#define OPTIMIZER_H

#include "Matrix.h"

typedef struct Optimizer {
    // The learning rate
    float alpha;

    // The loss function
    float (*loss)(Matrixf*, Matrixf*);
} Optimizer;

Optimizer* malloc_Optimizer(float lr, float (*func)(Matrixf*, Matrixf*));

void free_Optimizer(Optimizer* O);

#endif
