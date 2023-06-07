#include <stdio.h>
#include "../Layers/Linear.h"

int main(int argc, char** argv) {
    Linear* mem_safe_layer = malloc_Linear(3, 256);
    free_Linear(mem_safe_layer);

    Linear* forward_layer = malloc_Linear(3, 256);
    Matrixf* x = malloc_Matrixf(1, 256);
    Matrixf* y = forward_Linear(forward_layer, x);

    free_Linear(forward_layer);
    free_Matrixf(x);
    free_Matrixf(y);

    Linear* pointer_test = malloc_Linear(2, 2);
    fprintf(stdout, "Pointer to the Linear layer = %p\n", pointer_test);
    fprintf(stdout, "Pointer to the base of the Linear layer = %p\n", &(pointer_test->base));
    free_Linear(pointer_test);

    return 0;
}