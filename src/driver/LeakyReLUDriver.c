#include <stdio.h>
#include <math.h>

#include "../../include/LeakyReLU.h"

int main(int argc, char** argv) {

    // Malloc and free test
    Activation* leaky_relu = malloc_LeakyReLU(0.01);
    leaky_relu->free_Activation(leaky_relu);

    return 0;
}