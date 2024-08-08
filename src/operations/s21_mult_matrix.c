#include "s21_operations.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = RESULT_OK;
  if (!s21_matrix_is_correct(A) || !s21_matrix_is_correct(B)) {
    status = RESULT_INCORRECT;
  }
  if (!status && !s21_check_for_mult(A, B)) status = RESULT_ERROR;
  if (!status) status = s21_create_matrix(A->rows, B->columns, result);
  if (!status) {
    for (int row = 0; row < A->rows; row++) {
      for (int ceil = 0; ceil < B->columns; ceil++) {
        result->matrix[row][ceil] = s21_calc_mult_ceil(A, B, row, ceil);
      }
    }
  }
  return status;
}