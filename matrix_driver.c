#include "Matrix.h"

int main(int argc, char** argv) {
    Matrixf* mem_safe_mat = malloc_Matrixf(2, 2);
    free_Matrixf(mem_safe_mat);

    return 0;
}
