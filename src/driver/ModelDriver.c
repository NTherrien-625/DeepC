#include <stdio.h>

#include "../../include/Model.h"
#include "../../include/Linear.h"
#include "../../include/ReLU.h"
#include "../../include/LeakyReLU.h"

int main(int argc, char** argv) {

    // Malloc and free empty model test
    Model* model = malloc_Model();
    free_Model(model);

    // Malloc and free model with layers test
    model = malloc_Model();
    Layer* linear = malloc_Linear(2, 20);
    Layer* linear_2 = malloc_Linear(20, 1);

    insert_Layer(model, linear);
    insert_Layer(model, linear_2);

    free_Model(model);

    // Malloc and free model with activations test
    model = malloc_Model();

    Activation* relu = malloc_ReLU();
    Activation* leaky = malloc_LeakyReLU(0.01);

    insert_Activation(model, relu);
    insert_Activation(model, leaky);

    free_Model(model);

    return 0;
}