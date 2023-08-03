#include <assert.h>

#include "../../include/Tensor.h"

Tensord* malloc_Tensord(unsigned int argc, ...) {
    
    // Allocate space for the new Tensord
    Tensord* new_tensor = (Tensord*) malloc( sizeof(Tensord) );

    // Set the rank and dimensions
    new_tensor->rank = argc;
    new_tensor->dims = (unsigned int*) malloc( sizeof(unsigned) * argc );
    
    va_list args;
    va_start(args, argc);

    unsigned int temp;
    unsigned int rolling_size = 1;
    for (unsigned int i = 1; i <= argc; ++i) {
        temp = va_arg(args, unsigned int);
        rolling_size *= temp;
        new_tensor->dims[i - 1] = temp;
    }

    // Allocate space for the data
    new_tensor->data = (double*) malloc( sizeof(double) * rolling_size );
    
    return new_tensor;

}

void free_Tensord(Tensord* T) {
    
    // Free and NULL member variables
    free(T->data);
    T->data = NULL;
    
    free(T->dims);
    T->dims = NULL;

    T->rank = 0;

    // Free and NULL the entire Tensor
    free(T);
    T = NULL;
    
}

Tensord* mul_Tensord_r2(Tensord* lhs, Tensord* rhs) {

    // Assert the dimensions of the Tensors
    assert( (lhs->rank == 2) && (rhs->rank == 2) );
    assert(lhs->dims[1] == rhs->dims[0]);

    // Allocate space for the new Tensor
    Tensord* new_tensor = malloc_Tensord(2, lhs->dims[0], rhs->dims[1]);

    // Do the Naive algorithm
    double help_vector[ lhs->dims[1] ];
    double dot;

    // For each row in the left Tensor
    for (unsigned int i = 0; i < lhs->dims[0]; ++i) {

        // Cache off the current lhs row
        for (unsigned int k = 0; k < lhs->dims[1]; ++k) {
            help_vector[k] = lhs->data[i * lhs->dims[1] + k];
        }

        // For each column in the right Tensor
        for (unsigned int j = 0; j < rhs->dims[1]; ++j) {

            // Find the dot product and place it in [i][j]
            dot = 0;
            for (unsigned int k = 0; k < rhs->dims[0]; ++k) {
                dot += ( help_vector[k] * rhs->data[k * rhs->dims[1] + j] ); 
            }
            new_tensor->data[i * rhs->dims[1] + j] = dot;

        }

    }

    // We did it
    return new_tensor;

}

Tensord* copy_Tensord(Tensord* T) {

    // Allocate space for the new tensor
    Tensord* new_tensor = (Tensord*) malloc( sizeof(Tensord) );

    // Allocate space and initialize the rank and dimensions
    new_tensor->rank = T->rank;
    new_tensor->dims = (unsigned int*) malloc( sizeof(unsigned int) * new_tensor->rank );
    unsigned int rolling_size = 1;
    for (unsigned int i = 0; i < new_tensor->rank; ++i) {
        new_tensor->dims[i] = T->dims[i];
        rolling_size *= new_tensor->dims[i];
    }

    // Allocate space for and copy over the Tensor data
    new_tensor->data = (double*) malloc( sizeof(double) * rolling_size );
    for (unsigned int i = 0; i < rolling_size; ++i) {
        new_tensor->data[i] = T->data[i];
    }

    return new_tensor;

}
