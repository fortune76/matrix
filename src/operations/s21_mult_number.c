#include "s21_operations.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int status = RESULT_OK;
  if (!s21_matrix_is_correct(A)) status = RESULT_INCORRECT;
  if (!status) status = s21_create_matrix(A->rows, A->columns, result);
  if (!status) {
    for (int row = 0; row < A->rows; row++) {
      for (int column = 0; column < A->columns; column++) {
        result->matrix[row][column] = A->matrix[row][column] * number;
      }
    }
  }
  return status;
}