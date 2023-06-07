#include <stdlib.h>
#include "Model.h"

Model* malloc_Model() {
    Model* new_model = (Model*) malloc(sizeof(Model));
    new_model->layers = NULL;
    new_model->activation = NULL;

    return new_model;
}

void free_Model(Model* M) {
    free(M);
    M = NULL;

    return;
}
