#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "../../include/Linear.h"

double rand_norm() {
    srand(0);
    double rv = (double)rand() / RAND_MAX;
    return ((2 * rv) - 1);
}

int main(int argc, char** argv) {

    // Malloc and free test
    Layer* new_linear = malloc_Linear(2, 20);
    new_linear->free_Layer(new_linear);
    
    // Forward pass test
    unsigned int in = 2;
    unsigned int out = 20;

    Layer* f_linear = malloc_Linear(in, out);

    Tensord* x = malloc_Tensord(2, 1, in);

    for (unsigned int i = 0; i < in; ++i) {
        for (unsigned int j = 0; j < out; ++j) {
            f_linear->weights->data[i * out + j] = rand_norm();
        }
    }

    for (unsigned int i = 0; i < 1; ++i) {
        for (unsigned int j = 0; j < in; ++j) {
            x->data[i * in + j] = rand_norm();
        }
    }

    Tensord* f_tensor = f_linear->forward(f_linear, x);

    for (unsigned int i = 0; i < 1; ++i) {
        for (unsigned int j = 0; j < out; ++j) {
            fprintf(stdout, "%f ", f_tensor->data[i * out + j]);
        }
        fprintf(stdout, "\n");
    }

    free_Tensord(f_tensor);
    free_Tensord(x);
    f_linear->free_Layer(f_linear);

    return 0;
}