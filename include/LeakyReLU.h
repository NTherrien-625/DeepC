#ifndef LEAKYRELU_H
#define LEAKYRELU_H

#include "Activation.h"

typedef struct LeakyReLU {
    // Access to the base structure
    Activation* base;

    // LeakyReLU has a negative slope at <0 side of the ramp
    double leak;
} LeakyReLU;

Activation* malloc_LeakyReLU(double leak);

Tensord* activate_LeakyReLU(Activation* A, Tensord* x);

void free_LeakyReLU(Activation* A);

#endif
