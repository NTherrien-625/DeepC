#include "../Model.h"

int main(int argc, char** argv) {
    Model* new_model = malloc_Model();
    free_Model(new_model);
    
    return 0;
}
