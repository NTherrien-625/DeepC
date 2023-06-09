#include <stdio.h>
#include "../Model.h"
#include "../Layers/Linear.h"
#include "../Activation/relu.h"
#include "../Matrix.h"

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
    
    return 0;
}
