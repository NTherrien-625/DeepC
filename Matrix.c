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

Matrixf* mul_Matrixf(Matrixf* lhs, Matrixf* rhs) {
    // Return NULL if the matrices are not compatible for multiplication
    if (lhs->columns != rhs->rows) {
        return NULL;
    }

    // The resulting matrix is lhs->rows x rhs->columns
    Matrixf* new_mat = malloc_Matrixf(lhs->rows, rhs->columns);

    // Helper vector for finding the dot product
    float helper[lhs->columns];

    // Helper variable to store the dot product
    float dot = 0;

    // Using the naive algorithm
    for (unsigned int i = 0; i < lhs->rows; ++i) {

        // Fill in the helper vector
        for (unsigned int k = 0; k < lhs->columns; ++k) {
            helper[k] = lhs->data[i * lhs->columns + k];
        }

        for (unsigned int j = 0; j < rhs->columns; ++j) {
            // Find the dot product and assign
            dot = 0;
            for (unsigned int k = 0; k < lhs->columns; ++k) {
                dot += helper[k] * rhs->data[j * rhs->columns + k];
            }
            new_mat->data[i * rhs->columns + j] = dot;
        }
    }

    return new_mat;
}
