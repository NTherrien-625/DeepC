#include <stdlib.h>

#include "Tensor.h"

Tensord* malloc_Tensord(int argc, ...) {
    // Setup the argument list
    va_list args;
    va_start(args, argc);

    Tensord* new_tensor = (Tensord*) malloc(sizeof(Tensord));

    // Allocate and fill the dimension 
    unsigned int rolling_size = 1;
    new_tensor->dimensions = (unsigned int*) malloc(sizeof(unsigned int) * argc);
    for (unsigned int i = 1; i <= argc; ++i) {
        new_tensor->dimensions[i - 1] = va_arg(args, unsigned int);
        rolling_size *= new_tensor->dimensions[i - 1];
    }

    // Allocate and initialize the data array
    new_tensor->data = (double*) calloc(rolling_size, sizeof(double));

    // End the argument list
    va_end(args);

    return new_tensor;
}

void free_Tensord(Tensord* t) {
    // Free and NULL the data array
    free(t->data);
    t->data = NULL;

    // Free and NULL the dimension array
    free(t->dimensions);
    t->dimensions = NULL;

    // Free and NULL the tensor
    free(t);
    t = NULL;
}
