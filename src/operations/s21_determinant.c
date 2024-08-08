#include "s21_operations.h"

int s21_determinant(matrix_t *A, double *result) {
  int status = RESULT_OK;
  if (!s21_matrix_is_correct(A) || !s21_check_square(A)) {
    status = RESULT_INCORRECT;
  }
  if (!status) {
    int matrix_size = A->columns;
    if (matrix_size < 2) {
      *result = A->matrix[0][0];
    } else if (matrix_size == 2) {
      *result =
          A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
    } else {
      *result += s21_calc_determinant(A);
    }
  }
  return status;
}