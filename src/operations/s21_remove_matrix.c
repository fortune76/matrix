#include "s21_operations.h"

void s21_remove_matrix(matrix_t *A) {
  if (A != NULL) {
    for (int row = 0; row < A->rows; row++) {
      if (A->matrix[row] != NULL) {
        free(A->matrix[row]);
      }
    }
    free(A->matrix);
    A->matrix = NULL;
    A->rows = 0;
    A->columns = 0;
  }
}