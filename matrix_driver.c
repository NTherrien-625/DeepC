#include <stdio.h>
#include "Matrix.h"

int main(int argc, char** argv) {
    Matrixf* mem_safe_mat = malloc_Matrixf(2, 2);
    free_Matrixf(mem_safe_mat);

    unsigned int lhs_rows = 2;
    unsigned int lhs_columns = 3;
    unsigned int rhs_rows = 3;
    unsigned int rhs_columns = 1;

    Matrixf* lhs = malloc_Matrixf(lhs_rows, lhs_columns);
    for (unsigned int i = 0; i < lhs_rows; ++i) {
        for (unsigned int j = 0; j < lhs_columns; ++j) {
            lhs->data[i * lhs_columns + j] = i + j;
        }
    }
    for (unsigned int i = 0; i < lhs_rows; ++i) {
        for (unsigned int j = 0; j < lhs_columns; ++j) {
            fprintf(stdout, "%f ", lhs->data[i * lhs_columns + j]);
        }
        fprintf(stdout, "\n");
    }
    fprintf(stdout, "\n");

    Matrixf* rhs = malloc_Matrixf(rhs_rows, rhs_columns);
    for (unsigned int i = 0; i < rhs_rows; ++i) {
        for (unsigned int j = 0; j < rhs_columns; ++j) {
            rhs->data[i * rhs_columns + j] = 2 * (i + j);
        }
    }
    for (unsigned int i = 0; i < rhs_rows; ++i) {
        for (unsigned int j = 0; j < rhs_columns; ++j) {
            fprintf(stdout, "%f ", rhs->data[i * rhs_columns + j]);
        }
        fprintf(stdout, "\n");
    }
    fprintf(stdout, "\n");

    Matrixf* mul_mat = mul_Matrixf(lhs, rhs);
    for (unsigned int i = 0; i < mul_mat->rows; ++i) {
        for (unsigned int j = 0; j < mul_mat->columns; ++j) {
            fprintf(stdout, "%f ", mul_mat->data[i * mul_mat->columns + j]);
        }
        fprintf(stdout, "\n");
    }

    free_Matrixf(lhs);
    free_Matrixf(rhs);
    free_Matrixf(mul_mat);

    return 0;
}
