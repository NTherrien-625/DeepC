#include <stdlib.h>
#include "Matrix.h"

Matrixf* malloc_Matrixf(unsigned int r, unsigned int c) {
    // Allocate memory for the matrix
    Matrixf* new_mat = (Matrixf*) malloc(sizeof(Matrixf) + r * c * sizeof(float));

    // Assign the rows and columns
    new_mat->rows = r;
    new_mat->columns = c;

    // Initialize to 0
    for (unsigned int i = 0; i < r; ++i) {
        for (unsigned int j = 0; j < c; ++j) {
            new_mat->data[i * c + j] = 0;
        }
    }

    return new_mat;
}

void free_Matrixf(Matrixf* mat) {
    // Freeing is easy since the data is a float[] not a float*
    free(mat);

    return;
}
