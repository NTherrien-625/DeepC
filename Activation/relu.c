#include "../Matrix.h"
#include "relu.h"

Matrixf* relu_Matrixf(Matrixf* mat) {
    // Allocate the resulting matrix
    Matrixf* new_mat = malloc_Matrixf(mat->rows, mat->columns);

    // Apply relu
    for (unsigned int i = 0; i < new_mat->rows; ++i) {
        for (unsigned int j = 0; j < new_mat->columns; ++j) {
            if (new_mat->data[i * new_mat->columns + j] <= 0) {
                new_mat->data[i * new_mat->columns + j] = 0;
            }
        }
    }

    return new_mat;
}
