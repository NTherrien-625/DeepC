#include "../../include/Linear.h"

int main(int argc, char** argv) {

    Linear* new_linear = malloc_Linear(2, 20);
    free_Linear(new_linear->base);

    return 0;
}