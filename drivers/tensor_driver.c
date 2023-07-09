#include "../Tensor.h"

int main(int argc, char** argv) {
    Tensord* new_tensor = malloc_Tensord(3, 10, 2, 2);
    free_Tensord(new_tensor);

    return 0;
}
