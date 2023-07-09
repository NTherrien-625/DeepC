#ifndef TENSOR_H
#define TENSOR_H

#include <stdarg.h>

typedef struct Tensord {
    double* data;
    unsigned int* dimensions;
} Tensord;

Tensord* malloc_Tensord(int argc, ...);

void free_Tensord(Tensord* t);

#endif
