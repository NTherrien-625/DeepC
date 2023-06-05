#include <stdlib.h>
#include <stdio.h>
#include "Matrix.h"

Matrixf* malloc_Matrixf(unsigned int r, unsigned int c) {
    // Allocate memory for the matrix
    Matrixf* new_mat = (Matrixf*) calloc(1, sizeof(Matrixf));
    new_mat->data = (float*) calloc(r * c, sizeof(float));

    // Assign the rows and columns
    new_mat->rows = r;
    new_mat->columns = c;

    return new_mat;
}

void free_Matrixf(Matrixf* mat) {
    free(mat->data);
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

    // Helper variables
    float helper[lhs->columns];
    float dot = 0;

    // Using the naive algorithm
    for (unsigned int i = 0; i < lhs->rows; ++i) {
        // Fill in the helper vector
        for (unsigned int k = 0; k < lhs->columns; ++k) {
            helper[k] = lhs->data[i * lhs->columns + k];
        }
        for (unsigned int j = 0; j < rhs->columns; ++j) {
            // Find the dot product
            dot = 0;
            for (unsigned int k = 0; k < lhs->columns; ++k) {
                dot += helper[k] * rhs->data[k * rhs->columns + j];
            }
            // Assign it to the new matrix
            new_mat->data[i * rhs->columns + j] = dot;
        }
    }

    return new_mat;
}
