#include <stdlib.h>
#include <stdio.h>
#include "../Matrix.h"
#include "Linear.h"

Linear* malloc_Linear(unsigned int in, unsigned int out) {
    // Allocate memory for the layer
    Linear* new_layer = (Linear*) malloc(sizeof(Linear));
    new_layer->weights = malloc_Matrixf(in, out);
    new_layer->base = (Layer*) malloc(sizeof(Layer));

    // Assign the forward pass and free functions to the base layers
    new_layer->base->forward = forward_Linear;
    new_layer->base->free_Layer = free_Linear;

    // Set the input and output dimension
    new_layer->input_dim = in;
    new_layer->output_dim = out;

    return new_layer;
}

void free_Linear(void* L) {
    Linear* linear = (Linear*) (L);

    free_Matrixf(linear->weights);
    free(linear->base);
    free(linear);

    return;
}

Matrixf* forward_Linear(void* L, Matrixf* x) {
    Linear* linear = (Linear*) (L);

    if ((x->columns != linear->input_dim) && (x->rows != 1)) {
        return NULL;
    }

    Matrixf* forward_mat = mul_Matrixf(x, linear->weights);

    return forward_mat;
}
