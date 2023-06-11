#include <stdio.h>
#include <stdlib.h>
#include "../Model.h"
#include "../Layers/Linear.h"
#include "../Activation/relu.h"
#include "../Matrix.h"
#include "../datasets/xor_dataset.h"
#include "../Optimizer.h"
#include "../Loss/mse.h"

int main(int argc, char** argv) {
    // Malloc and free test without layers
    Model* new_model = malloc_Model();
    free_Model(new_model);

    // Malloc and free test with layers
    Model* layer_model = malloc_Model();
    Linear* fc = malloc_Linear(1, 2);
    insert_Layer(fc->base, layer_model);
    free_Model(layer_model);

    // Malloc and free test with layers and activations
    Model* activation_model = malloc_Model();
    fc = malloc_Linear(1, 2);
    insert_Layer(fc->base, activation_model);
    insert_activation(relu_Matrixf, activation_model);
    free_Model(activation_model);

    // Forward pass test
    Model* forward_model = malloc_Model();
    fc = malloc_Linear(1, 2);
    insert_Layer(fc->base, forward_model);
    insert_activation(relu_Matrixf, forward_model);

    unsigned int input_rows = 1;
    unsigned int input_columns = 1;
    Matrixf* input_mat = malloc_Matrixf(input_rows, input_columns);
    for (unsigned int i = 0; i < input_rows; ++i) {
        for (unsigned int j = 0; j < input_columns; ++j) {
            input_mat->data[i * input_columns + j] = 0.5;
        }
    }
    for (unsigned int i = 0; i < input_rows; ++i) {
        for (unsigned int j = 0; j < input_columns; ++j) {
            fprintf(stdout, "%f ", input_mat->data[i * input_columns + j]);
        }
        fprintf(stdout, "\n");
    }
    fprintf(stdout, "\n");

    Matrixf* output_mat = forward_Model(input_mat, forward_model);

    unsigned int output_rows = output_mat->rows;
    unsigned int output_columns = output_mat->columns;
    for (unsigned int i = 0; i < output_rows; ++i) {
        for (unsigned int j = 0; j < output_columns; ++j) {
            fprintf(stdout, "%f ", output_mat->data[i * output_columns + j]);
        }
        fprintf(stdout, "\n");
    }
    fprintf(stdout, "\n");

    free_Matrixf(input_mat);
    free_Matrixf(output_mat);
    free_Model(forward_model);

    // Backwards pass test (try to learn XOR)
    Model* xor_model = malloc_Model();
    Linear* input_layer = malloc_Linear(2, 2);
    Linear* output_layer = malloc_Linear(2, 1);
    insert_Layer(input_layer->base, xor_model);
    insert_Layer(output_layer->base, xor_model);
    insert_activation(relu_Matrixf, xor_model);
    insert_activation(relu_Matrixf, xor_model);
    Optimizer* optimizer = malloc_Optimizer(0.01, mse);

    // The training data
    unsigned int training_instances = 100;
    Matrixf** data = get_xor_points(training_instances);
    float* labels = get_xor_labels(training_instances);

    // The training loop
    unsigned int epochs = 1;
    float rolling_loss;
    Matrixf* forward_mat;
    Matrixf* label_mat = malloc_Matrixf(1, 1);
    for (unsigned int i = 0; i < epochs; ++i) {

        // Do a forward pass and find the total loss
        rolling_loss = 0;
        for (unsigned int j = 0; j < training_instances; ++j) {
            forward_mat = forward_Model(data[j], xor_model);
            label_mat->data[0] = labels[j];
            rolling_loss += optimizer->loss(label_mat, forward_mat);
            free_Matrixf(forward_mat);
        }

        fprintf(stdout, "Epoch %u : %f\n", i, rolling_loss);

        // Do a backward pass and adjust the weights
        for (unsigned int j = 0; j < training_instances; ++j) {
            label_mat->data[0] = labels[j];
            backward_Model(data[j], label_mat, optimizer, xor_model);
        }
    }

    free_Matrixf(label_mat);
    free(labels);
    for (unsigned int i = 0; i < training_instances; ++i) {
        free_Matrixf(data[i]);
    }
    free(data);
    free_Optimizer(optimizer);
    free_Model(xor_model);
    
    return 0;
}
