#ifndef ReLU_H
#define ReLU_H

#include "Activation.h"

typedef struct ReLU {
    // Access to the base structure
    Activation* base;
} ReLU;

Activation* malloc_ReLU(void);

Tensord* activate_ReLU(Activation* A, Tensord* x);

void free_ReLU(Activation* A);

#endif
