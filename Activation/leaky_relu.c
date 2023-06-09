#include "../Matrix.h"
#include "leaky_relu.h"

Matrixf* leakyRelu_Matrixf(Matrixf* mat, float ns) {
    // Allocate the resulting matrix
    Matrixf* new_mat = malloc_Matrixf(mat->rows, mat->columns);

    // Copy data over
    for (unsigned int i = 0; i < new_mat->rows; ++i) {
        for (unsigned int j = 0; j < new_mat->columns; ++j) {
            new_mat->data[i * new_mat->columns + j] = mat->data[i * new_mat->columns + j];
        }
    }

    // Apply leaky relu
    for (unsigned int i = 0; i < new_mat->rows; ++i) {
        for (unsigned int j = 0; j < new_mat->columns; ++j) {
            if (new_mat->data[i * new_mat->columns + j] <= 0) {
                new_mat->data[i * new_mat->columns + j] = mat->data[i * new_mat->columns + j] * ns;
            }
        }
    }

    return new_mat;
}