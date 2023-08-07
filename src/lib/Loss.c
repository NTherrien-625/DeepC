#include <assert.h>

#include "../../include/Loss.h"

double mse_loss(Tensord* y, Tensord* y_hat) {

    // Assert that the tensors are the same shape
    assert(y->rank == y_hat->rank);
    unsigned int rolling_size = 1;
    for (unsigned int i = 0; i < y->rank; ++i) {
        assert(y->dims[i] == y_hat->dims[i]);
        rolling_size *= y->dims[i];
    }

    // Compute the rolling loss over each pair (y, y_hat) or elements
    double rolling_loss = 0;
    for (unsigned int i = 0; i < rolling_size; ++i) {
        rolling_loss += ( (y->data[i] * y_hat->data[i]) * (y->data[i] * y_hat->data[i]) );
    }

    return rolling_loss;

}
