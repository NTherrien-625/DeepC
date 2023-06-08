#include <stdio.h>
#include <stdlib.h>
#include "../Layers/Linear.h"

int main(int argc, char** argv) {
    // Malloc and Free test
    Linear* mem_safe_layer = malloc_Linear(3, 256);
    mem_safe_layer->base->free_Layer(mem_safe_layer);

    // Forward pass test
    Linear* forward_layer = malloc_Linear(3, 256);
    Matrixf* x = malloc_Matrixf(1, 256);
    Matrixf* y = forward_layer->base->forward(forward_layer, x);
    forward_layer->base->free_Layer(forward_layer);
    free_Matrixf(x);
    free_Matrixf(y);

    return 0;
}