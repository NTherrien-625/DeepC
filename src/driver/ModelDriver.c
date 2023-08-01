#include "../../include/Model.h"
#include "../../include/Linear.h"

int main(int argc, char** argv) {

    // Malloc and free empty model test
    Model* model = malloc_Model();
    free_Model(model);

    // Malloc and free with layers test
    model = malloc_Model();
    Layer* linear = malloc_Linear(2, 20);
    Layer* linear_2 = malloc_Linear(20, 1);

    insert_Layer(model, linear);
    insert_Layer(model, linear_2);
    
    free_Model(model);

    return 0;
}