#include "../Model.h"
#include "../Layers/Linear.h"

int main(int argc, char** argv) {
    // Malloc and free test without layers
    Model* new_model = malloc_Model();
    free_Model(new_model);

    // Malloc and free test with layers
    Model* layer_model = malloc_Model();
    Linear* fc = malloc_Linear(1, 2);
    insert_Layer(fc->base, layer_model);
    free_Model(layer_model);
    
    return 0;
}
