#include <stdlib.h>
#include <assert.h>

#include "../../include/Model.h"

Model* malloc_Model(void) {

    // Allocate space for the new model
    Model* new_model = (Model*) malloc( sizeof(Model) );
    
    // The model starts empty, don't allocate space for the layers and activations
    new_model->layers = NULL;
    new_model->activations = NULL;
    new_model->num_layers = 0;
    new_model->num_activations = 0;

    return new_model;

}

void free_Model(Model* M) {

    // Free all the layers
    for (unsigned int i = 0; i < M->num_layers; ++i) {
        M->layers[i]->free_Layer(M->layers[i]);
    }
    M->num_layers = 0;

    free(M->layers);
    M->layers = NULL;

    // Free all the activation functions
    for (unsigned int i = 0; i < M->num_activations; ++i) {
        if (M->activations[i] != NULL) {
            M->activations[i]->free_Activation(M->activations[i]);
        }
    }
    M->num_activations = 0;

    free(M->activations);
    M->activations = 0;

    // Free the whole model
    free(M);
    M = NULL;

}

void insert_Layer(Model* M, Layer* L) {

    // Reallocate the layer array to hold space for the new one
    M->num_layers += 1;
    M->layers = (Layer**) realloc( M->layers, sizeof(Layer*) * M->num_layers );

    // Insert the new layer
    M->layers[M->num_layers - 1] = L;

    return;

}

void insert_Activation(Model* M, Activation* A) {

    // Reallocate the activation array to hold space for the new one
    M->num_activations += 1;
    M->activations = (Activation**) realloc( M->activations, sizeof(Activation*) * M->num_activations );

    // Insert the new activation
    M->activations[M->num_activations - 1] = A;

    return;

}

Tensord* forward_Model(Model* M, Tensord* x) {

    // Assert that there is a layer for each activation
    assert( M->num_layers == M->num_activations );

    // x needs to be kept safe, it is a dataset instance, copy x into a temporary tensor
    Tensord* temp_one = copy_Tensord(x);

    // Another helper pointer
    Tensord* temp_two;

    // For each layer and activation
    for (unsigned int i = 0; i < M->num_layers; ++i) {
        
        // Pass the data through the layer
        temp_two = M->layers[i]->forward(M->layers[i], temp_one);
        free_Tensord(temp_one);

        // Pass the data through the activation
        if (M->activations[i] != NULL) {
            temp_one = M->activations[i]->activate(M->activations[i], temp_two);
        }

        // NULL activation means it just passes through, no fuss
        else {
            temp_one = copy_Tensord(temp_two);
        }

        free_Tensord(temp_two);

    }

    return temp_one;

}
