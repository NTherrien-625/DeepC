#include <stdlib.h>
#include <stdio.h>
#include "../Matrix.h"
#include "Linear.h"

Linear* malloc_Linear(unsigned int in, unsigned int out) {
    // Allocate memory for the layer
    Linear* new_layer = (Linear*) malloc(sizeof(Linear));
    Matrixf* new_weights = malloc_Matrixf(in, out);
    new_layer->weights = new_weights;

    // Set the input and output dimensions
    new_layer->input_dim = in;
    new_layer->output_dim = out;

    return new_layer;
}

void free_Linear(Linear* L) {
    free_Matrixf(L->weights);
    free(L);
    L = NULL;

    return;
}

Matrixf* forward_Linear(Linear* L, Matrixf* x) {
    if ((x->columns != L->input_dim) && (x->rows != 1)) {
        return NULL;
    }

    Matrixf* forward_mat = mul_Matrixf(x, L->weights);

    return forward_mat;
}
