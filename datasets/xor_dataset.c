#include <stdlib.h>
#include <time.h>
#include "Matrix.h"

Matrixf** get_xor_points(unsigned int num_points) {
    Matrixf** points = (Matrixf**) malloc(sizeof(Matrixf*) * num_points);

    srand(time(NULL));

    float min_x, max_x, min_y, max_y;
    Matrixf* new_point;

    for (unsigned int i = 0; i < num_points; ++i) {
        // (+, +) case
        if ((i % 4) == 0) {
            min_x = 0;
            max_x = 1;
            min_y = 0;
            max_y = 1;
        }

        // (-, +) case
        if ((i % 4) == 1) {
            min_x = -1;
            max_x = 0;
            min_y = 0;
            max_y = 1;
        }

        // (-, -) case
        if ((i % 4) == 2) {
            min_x = -1;
            max_x = 0;
            min_y = -1;
            max_y = 0;
        }

        // (+, -) case
        if ((i % 4) == 3) {
            min_x = 0;
            max_x = 1;
            min_y = -1;
            max_y = 0;
        }

        new_point = malloc_Matrixf(1, 2);
        new_point->data[0] = min_x + ((float)rand() / RAND_MAX) * (max_x - min_x);
        new_point->data[1] = min_y + ((float)rand() / RAND_MAX) * (max_y - min_y);
        points[i] = new_point;
    }

    return points;
}

float* get_xor_lables(unsigned int num_points) {
    float* labels = (float*) malloc(sizeof(float) * num_points);

    for (unsigned int i = 0; i < num_points; ++i) {
        // Positive (Blue) case
        if (((i % 4) == 1) || ((i % 4) == 3)) {
            labels[i] = 1;
        }

        // Negative (Red) case
        else {
            labels[i] = 0;
        }
    }

    return labels;
}
