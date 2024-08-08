#include "s21_operations.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int status = RESULT_OK;
  if (!s21_matrix_is_correct(A) || !s21_check_square(A) || A->rows == 1) {
    status = RESULT_INCORRECT;
  }
  if (!status) {
    status = s21_create_matrix(A->rows, A->columns, result);
  }
  if (!status) {
    double det = 0;
    s21_determinant(A, &det);
    ;
    if (det == 0) status = RESULT_ERROR;
  }
  if (!status) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        matrix_t M;
        status = s21_create_minor_matrix(A, j, i, &M);
        s21_determinant(&M, &result->matrix[i][j]);
        result->matrix[i][j] = (i + j) % 2 == 0 ? result->matrix[i][j]
                                                : result->matrix[i][j] * (-1);
        s21_remove_matrix(&M);
      }
    }
  }

  return status;
}