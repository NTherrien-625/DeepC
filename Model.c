#include <stdlib.h>
#include "Model.h"

Model* malloc_Model() {
    // Allocate memory for the model
    Model* new_model = (Model*) malloc(sizeof(Model));

    // The layer and activation arrays start empty
    new_model->layers = NULL;
    new_model->activation = NULL;

    // The depth starts as 0
    new_model->depth = 0;

    return new_model;
}

void free_Model(Model* M) {
    // Free each of the layers in the layer array
    for (unsigned int i = 0; i < M->depth; ++i) {
        M->layers[i]->free_Layer(M->layers[i]);
    }

    // Free the layer pointer array
    free(M->layers);

    // Free the function pointer array
    free(M->activation);

    // Free the model
    free(M);

    // NULL out the model
    M = NULL;

    return;
}

void insert_Layer(Layer* L, Model* M) {
    // Reallocate the layer* array with room for the new layer and activation function to procede it
    M->layers = (Layer**) realloc(M->layers, sizeof(Layer*) * (M->depth + 1));
    M->activation = (Matrixf* (**)(Matrixf*)) realloc(M->activation, sizeof(Matrixf* (*)(Matrixf*)) * (M->depth + 1));

    // Insert the new layer
    M->layers[M->depth] = L;

    // Increment the depth
    M->depth += 1;

    return;
}

void insert_activation(Matrixf* (*func)(Matrixf*), Model* M) {
    // Insert the new activation function
    M->activation[M->depth - 1] = func;

    return;
}

Matrixf* forward_Model(Matrixf* x, Model* M) {
    // The intermediate matrix that will store the final result
    Matrixf* return_mat = x;

    // The temporary matrix used for swapping and freeing
    Matrixf* temp;

    // Go through each layer and activation function
    for (unsigned int i = 0; i < M->depth; ++i) {
        // Forward
        return_mat = M->layers[i]->forward(M->layers[i], return_mat);

        // Store the forward matrix for freeing
        temp = return_mat;

        // Activate
        if (M->activation[i] != NULL) {
            return_mat = M->activation[i](temp);
        }

        // Free the forward matrix
        free(temp);
    }

    return return_mat;
}
