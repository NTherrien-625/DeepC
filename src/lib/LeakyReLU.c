#include "../../include/LeakyReLU.h"

Activation* malloc_LeakyReLU(double leak) {

    // Allocate space for the LeakyReLU
    LeakyReLU* new_leaky = (LeakyReLU*) malloc( sizeof(LeakyReLU) );
    new_leaky->leak = leak;

    // Allocate space for the base activation and link them up
    new_leaky->base = (Activation*) malloc( sizeof(Activation) );
    new_leaky->base->spa = new_leaky;

    // Fill in the VTAB
    new_leaky->base->activate = activate_LeakyReLU;
    new_leaky->base->free_Activation = free_LeakyReLU;

    return new_leaky->base;

}

Tensord* activate_LeakyReLU(Activation* A, Tensord* x) {

    // We need the leak value from the LeakyReLU in the base
    LeakyReLU* leaky = A->spa;

    // Allocate space for the new tensor (we need to do it manually)
    Tensord* leaky_tensor = (Tensord*) malloc( sizeof(Tensord) );
    leaky_tensor->rank = x->rank;
    leaky_tensor->dims = (unsigned int*) malloc( sizeof(unsigned int) * leaky_tensor->rank );
    unsigned int rolling_size = 1;
    for (unsigned int i = 0; i < leaky_tensor->rank; ++i) {
        leaky_tensor->dims[i] = x->dims[i];
        rolling_size *= x->dims[i];
    }
    leaky_tensor->data = (double*) malloc( sizeof(double) * rolling_size );

    // Apply LeakyReLU to each element in it
    for (unsigned int i = 0; i < rolling_size; ++i) {
        if (x->data[i] <= 0) {
            leaky_tensor->data[i] = x->data[i] * leaky->leak;
        }
        else {
            leaky_tensor->data[i] = x->data[i];
        }
    }

    return leaky_tensor;

}

void free_LeakyReLU(Activation* A) {

    // Keep the LeakyReLU safe for freeing
    LeakyReLU* L = A->spa;

    // Free the base
    free(A);
    A = NULL;

    // Free the LeakyReLU
    free(L);
    L = NULL;

    return;

}
