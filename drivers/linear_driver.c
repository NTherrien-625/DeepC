#include <stdio.h>
#include <stdlib.h>
#include "../Layers/Linear.h"

int main(int argc, char** argv) {
    Linear* mem_safe_layer = malloc_Linear(3, 256);
    mem_safe_layer->base->free_Layer(mem_safe_layer);

    Linear* forward_layer = malloc_Linear(3, 256);
    Matrixf* x = malloc_Matrixf(1, 256);
    Matrixf* y = forward_layer->base->forward(forward_layer, x);

    free_Linear(forward_layer);
    free_Matrixf(x);
    free_Matrixf(y);

    Linear* pointer_test = malloc_Linear(10, 10);
    pointer_test->base->free_Layer(pointer_test);

    return 0;
}