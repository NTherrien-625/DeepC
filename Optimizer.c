#include <stdlib.h>
#include "Optimizer.h"

Optimizer* malloc_Optimizer(float lr, float (*func)(Matrixf*, Matrixf*)) {
    // Allocate memory for the optimizer
    Optimizer* new_optim = (Optimizer*) malloc(sizeof(Optimizer));

    // Set the optimizer variables
    new_optim->alpha = lr;
    new_optim->loss = func;

    return new_optim;
}

void free_Optimizer(Optimizer* O) {
    // Just free it lol
    free(O);
    O = NULL;

    return;
}
