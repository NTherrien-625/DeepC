#include <stdio.h>

#include "../../include/Tensor.h"

int main(int argc, char** argv) {

    // Malloc and free test
    Tensord* new_tensor = malloc_Tensord(3, 5, 5, 5);
    free_Tensord(new_tensor);

    // Rank 2 x Rank 2 test
    unsigned int m = 2;
    unsigned int n = 2;
    Tensord* left = malloc_Tensord(2, m, n);
    Tensord* right = malloc_Tensord(2, m, n);

    for (unsigned int i = 0; i < m; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            left->data[i * n + j] = (i + j);
            right->data[i * n + j] = 2 * (i + j);
        }
    }

    Tensord* mul = mul_Tensord_r2(left, right);

    for (unsigned int i = 0; i < m; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            fprintf(stdout, "%f\t", mul->data[i * n + j]);
        }
        fprintf(stdout, "\n");
    }

    free_Tensord(left);
    free_Tensord(right);
    free_Tensord(mul);

    return 0;
}