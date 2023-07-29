#include <stdio.h>
#include <math.h>

#include "../../include/LeakyReLU.h"

int main(int argc, char** argv) {

    // Malloc and free test
    Activation* leaky_relu = malloc_LeakyReLU(0.01);
    leaky_relu->free_Activation(leaky_relu);

    // Activation test
    leaky_relu = malloc_LeakyReLU(0.01);
    
    Tensord* x = malloc_Tensord(1, 10);
    for (unsigned int i = 0; i < 10; ++i) {
        x->data[i] = ( pow(-1, i) * i );
    }

    for (unsigned int i = 0; i < 10; ++i) {
        fprintf(stdout, "%f\t", x->data[i]);
    }
    fprintf(stdout, "\n");

    Tensord* l = leaky_relu->activate(leaky_relu, x);

    for (unsigned int i = 0; i < 10; ++i) {
        fprintf(stdout, "%f\t", l->data[i]);
    }
    fprintf(stdout, "\n");

    leaky_relu->free_Activation(leaky_relu);
    free_Tensord(x);
    free_Tensord(l);

    return 0;
}