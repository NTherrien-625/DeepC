#include "../../include/ReLU.h"

Activation* malloc_ReLU(void) {
    
    // Allocate space for the ReLU
    ReLU* new_ReLU = (ReLU*) malloc( sizeof(ReLU) );

    // Allocate space for the base activation and link them up
    new_ReLU->base = (Activation*) malloc( sizeof(Activation) );
    new_ReLU->base->spa = new_ReLU;

    // Fill in the VTAB
    new_ReLU->base->activate = activate_ReLU;
    new_ReLU->base->free_Activation = free_ReLU;

    return new_ReLU->base;

}

Tensord* activate_ReLU(Activation* A, Tensord* x) {
    
    // Allocate space for the new tensor (we need to do it manually)
    Tensord* relu_tensor = (Tensord*) malloc( sizeof(Tensord) );
    relu_tensor->rank = x->rank;
    relu_tensor->dims = (unsigned int*) malloc ( sizeof(unsigned int) * relu_tensor->rank );
    unsigned int rolling_size = 1;
    for (unsigned int i = 0; i < relu_tensor->rank; ++i) {
        relu_tensor->dims[i] = x->dims[i];
        rolling_size *= x->dims[i];
    }
    relu_tensor->data = (double*) malloc( sizeof(double) * rolling_size );

    // Apply relu to each element in it
    for (unsigned int i = 0; i < rolling_size; ++i) {
        if (x->data[i] <= 0) {
            relu_tensor->data[i] = 0;
        }
        else {
            relu_tensor->data[i] = x->data[i];
        }
    }

    return relu_tensor;

}

void free_ReLU(Activation* A) {

    // Keep the ReLU safe for freeing
    ReLU* R = A->spa;

    // Free the base
    free(A);
    A = NULL;

    // Free the ReLU
    free(R);
    R = NULL;

    return;

}