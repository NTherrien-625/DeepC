#include "Layers/Linear.h"

int main(int argc, char** argv) {
    Linear* mem_safe_layer = malloc_Linear(3, 256);
    free_Linear(mem_safe_layer);

    return 0;
}