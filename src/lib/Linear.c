#include <stdlib.h>
#include <assert.h>

#include "../../include/Tensor.h"
#include "../../include/Linear.h"

Linear* malloc_Linear(unsigned int in, unsigned int out) {
    
    // Allocate space for the Linear layer
    Linear* new_linear = (Linear*) malloc( sizeof(Linear) );

    // Allocate space for the base layer and link them up
    new_linear->base = (Layer*) malloc( sizeof(Layer) );
    new_linear->base->spl = new_linear;

    // Set the base variables
    new_linear->base->weights = malloc_Tensord(2, in, out);
    new_linear->base->in = in;
    new_linear->base->out = out;

    // Fill in the VTAB
    new_linear->base->forward = forward_Linear;
    new_linear->base->free_Layer = free_Linear;

    return new_linear;

}

void free_Linear(Layer* L) {

    // Keep the Linear layer safe for freeing
    Linear* lin = L->spl;

    // Free the base
    free_Tensord(L->weights);
    free(L);
    L = NULL;

    // Free the Linear layer
    free(lin);
    lin = NULL;

    return;

}

Tensord* forward_Linear(Layer* L, Tensord* x) {

    // Assert that the input tensor is formatted correctly and compatible with the layer
    assert( (x->rank == 2) && (x->dims[0] == 1) );
    assert(x->dims[1] == L->in);

    // Simple do a rank 2 x rank 2 and return the result
    Tensord* f_tensor;
    f_tensor = mul_Tensord_r2(x, L->weights);

    return f_tensor;

}