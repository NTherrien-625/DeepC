#ifndef ACTIVATION_H
#define ACTIVATION_H

#include "Tensor.h"

typedef struct Activation {
    // We need to loop back around to the specialized activation for freeing
    void* spa;

    // Artificial VTAB
    Tensord* (*activate)(struct Activation*, Tensord*);
    void (*free_Activation)(struct Activation*);
} Activation;

#endif
