#include "Layers/Linear.h"

int main(int argc, char** argv) {
    Linear* mem_safe_layer = malloc_Linear(3, 256);
    free_Linear(mem_safe_layer);

    Linear* forward_layer = malloc_Linear(3, 256);
    Matrixf* x = malloc_Matrixf(1, 256);
    Matrixf* y = forward_Linear(forward_layer, x);

    free_Linear(forward_layer);
    free_Matrixf(x);
    free_Matrixf(y);

    return 0;
}