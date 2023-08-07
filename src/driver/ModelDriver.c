#include <stdio.h>

#include "../../include/Model.h"
#include "../../include/Linear.h"
#include "../../include/ReLU.h"
#include "../../include/LeakyReLU.h"
#include "../../include/Tensor.h"
#include "../../include/Loss.h"

int main(int argc, char** argv) {

    // Malloc and free empty model test
    Model* model = malloc_Model(0.01, mse_loss);
    free_Model(model);

    // Malloc and free model with layers test
    model = malloc_Model(0.01, mse_loss);
    Layer* linear = malloc_Linear(2, 20);
    Layer* linear_2 = malloc_Linear(20, 1);

    insert_Layer(model, linear);
    insert_Layer(model, linear_2);

    free_Model(model);

    // Malloc and free model with activations test
    model = malloc_Model(0.01, mse_loss);
    Activation* relu = malloc_ReLU();
    Activation* leaky = malloc_LeakyReLU(0.01);

    insert_Activation(model, relu);
    insert_Activation(model, leaky);

    free_Model(model);

    // Malloc and free actual model
    model = malloc_Model(0.01, mse_loss);
    linear = malloc_Linear(2, 20);
    linear_2 = malloc_Linear(20, 1);
    relu = malloc_ReLU();

    insert_Layer(model, linear);
    insert_Layer(model, linear_2);
    insert_Activation(model, relu);
    insert_Activation(model, NULL);

    free_Model(model);

    // Forward model test
    unsigned int in_1 = 2;
    unsigned int out_1 = 20;
    unsigned int out_2 = 1;

    model = malloc_Model(0.01, mse_loss);
    linear = malloc_Linear(in_1, out_1);
    linear_2 = malloc_Linear(out_1, out_2);
    relu = malloc_ReLU();

    insert_Layer(model, linear);
    insert_Layer(model, linear_2);
    insert_Activation(model, relu);
    insert_Activation(model, NULL);

    Tensord* x = malloc_Tensord(2, 1, in_1);
    
    Tensord* y = forward_Model(model, x);

    free_Model(model);
    free_Tensord(x);
    free_Tensord(y);

    return 0;
}
