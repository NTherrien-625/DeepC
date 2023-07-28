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
    new_linear->base->weights = malloc_Tensord(in, out);
    new_linear->base->in = in;
    new_linear->base->out = out;

    // Fill in the VTAB

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
