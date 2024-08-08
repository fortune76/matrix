#include "s21_operations.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int status = RESULT_OK;
  if (!s21_matrix_is_correct(A) || !s21_check_square(A)) {
    status = RESULT_INCORRECT;
  }
  double det = 0;
  if (!status) {
    status = s21_determinant(A, &det);
    if (!det) status = RESULT_ERROR;
  }
  matrix_t complemented;
  if (!status) {
    status = s21_calc_complements(A, &complemented);
  }
  if (!status) {
    status = s21_transpose(&complemented, result);
  }
  if (!status) {
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] *= 1.00 / det;
      }
    }
    s21_remove_matrix(&complemented);
  }
  return status;
}