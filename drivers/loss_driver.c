#include <stdio.h>
#include "../Loss/mse.h"
#include "../Matrix.h"

int main(int argc, char** argv) {
    unsigned int n = 5;
    Matrixf* guess = malloc_Matrixf(1, n);
    Matrixf* truth = malloc_Matrixf(1, n);

    float label = 0;
    for (unsigned int i = 0; i < n; ++i) {
        truth->data[i] = label;
        guess->data[i] = label + 0.1;
        label += 1;
    }

    float loss = mse(truth, guess);
    fprintf(stdout, "Loss = %f\n", loss);

    free_Matrixf(guess);
    free_Matrixf(truth);

    return 0;
}
