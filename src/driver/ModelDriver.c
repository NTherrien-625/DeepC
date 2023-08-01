#include "../../include/Model.h"

int main(int argc, char** argv) {

    Model* model = malloc_Model();
    free_Model(model);
    
    return 0;
}