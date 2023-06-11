#include "mse.h"

float mse(Matrixf* y, Matrixf* y_hat) {
    // MSE expects two 1xn matrices
    if ((y->rows != 1) || (y_hat->rows != 1) || (y->columns != y_hat->columns)) {
        return 0;
    }

    // Compute MSE
    float rolling_error = 0;
    for (unsigned int i = 0; i < y->columns; ++i) {
        rolling_error += ((y->data[i] - y_hat->data[i]) * (y->data[i] - y_hat->data[i]));
    }

    return (rolling_error / y->columns);
}
