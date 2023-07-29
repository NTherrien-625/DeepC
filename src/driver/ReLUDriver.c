#include <stdio.h>
#include <math.h>

#include "../../include/ReLU.h"

int main(int argc, char** argv) {

    // Malloc and free test
    Activation* relu = malloc_ReLU();
    relu->free_Activation(relu);

    // Activation test
    relu = malloc_ReLU();
    Tensord* x = malloc_Tensord(1, 10);
    for (unsigned int i = 0; i < 10; ++i) {
        x->data[i] = ( pow(-1, i) * i );
    }

    for (unsigned int i = 0; i < 10; ++i) {
        fprintf(stdout, "%f\t", x->data[i]);
    }
    fprintf(stdout, "\n");

    Tensord* r = relu->activate(relu, x);

    for (unsigned int i = 0; i < 10; ++i) {
        fprintf(stdout, "%f\t", r->data[i]);
    }
    fprintf(stdout, "\n");

    relu->free_Activation(relu);
    free_Tensord(x);
    free_Tensord(r);

    return 0;
}
