#include <stdlib.h>

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
        M->activations[i]->free_Activation(M->activations[i]);
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
