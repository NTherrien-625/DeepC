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
