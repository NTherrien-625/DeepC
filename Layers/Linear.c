#include <stdlib.h>
#include "../Matrix.h"
#include "Linear.h"

Linear* malloc_Linear(unsigned int in, unsigned int out) {
    Linear* new_layer = (Linear*) malloc(sizeof(Linear));
    new_layer->weights = malloc_Matrixf(in, out);

    return new_layer;
}

void free_Linear(Linear* L) {
    free_Matrixf(L->weights);
    free(L);
    L = NULL;

    return;
}
