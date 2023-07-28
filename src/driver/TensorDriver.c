#include <stdio.h>

#include "../../include/Tensor.h"

int main(int argc, char** argv) {

    // Malloc and free test
    Tensord* new_tensor = malloc_Tensord(3, 5, 5, 5);
    free_Tensord(new_tensor);

    // Rank 2 x Rank 2 test
    Tensord* left = malloc_Tensord(2, 2, 2);
    Tensord* right = malloc_Tensord(2, 2, 2);

    for (unsigned int i = 0; i < 2; ++i) {
        for (unsigned int j = 0; j < 2; ++j) {
            left->data[i * 2 + j] = (i + j);
            right->data[i * 2 + j] = 2 * (i + j);
        }
    }

    Tensord* mul = mul_Tensord_r2(left, right);

    for (unsigned int i = 0; i < 2; ++i) {
        for (unsigned int j = 0; j < 2; ++j) {
            fprintf(stdout, "%f\t", mul->data[i * 2 + j]);
        }
        fprintf(stdout, "\n");
    }

    free_Tensord(left);
    free_Tensord(right);
    free_Tensord(mul);

    return 0;
}