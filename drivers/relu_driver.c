#include <stdio.h>
#include "../Activation/relu.h"
#include "../Matrix.h"

int main(int argc, char** argv) {
    unsigned int rows = 2;
    unsigned int columns = 2;

    Matrixf* relu_mat = malloc_Matrixf(rows, columns);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            relu_mat->data[i * columns + j] = -1 * (i + j);
        }
    }

    fprintf(stdout, "Initial matrix\n");
    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < columns; ++j) {
            fprintf(stdout, "%f ", relu_mat->data[i * columns + j]);
        }
        fprintf(stdout, "\n");
    }

    Matrixf* temp = relu_Matrixf(relu_mat);
    free_Matrixf(relu_mat);
    relu_mat = temp;

    fprintf(stdout, "Final matrix\n");
    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < columns; ++j) {
            fprintf(stdout, "%f ", relu_mat->data[i * columns + j]);
        }
        fprintf(stdout, "\n");
    }

    free_Matrixf(relu_mat);
    
    return 0;
}
