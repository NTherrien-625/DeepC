#ifndef TENSOR_H
#define TENSOR_H

#include <stdlib.h>
#include <stdarg.h>

typedef struct Tensord {
    double* data;
    unsigned int rank;
    unsigned int* dims;
} Tensord;

Tensord* malloc_Tensord(unsigned int argc, ...);

void free_Tensord(Tensord* T);

#endif
