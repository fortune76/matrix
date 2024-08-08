#include "s21_operations.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int status = RESULT_OK;
  if (!s21_matrix_is_correct(A)) status = RESULT_INCORRECT;
  if (!status) status = s21_create_matrix(A->columns, A->rows, result);
  if (!status) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
  }
  return status;
}