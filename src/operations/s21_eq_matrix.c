#include "s21_operations.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int status = SUCCESS;
  if (!s21_matrix_is_correct(A) || !s21_matrix_is_correct(B) ||
      !s21_matrix_is_same(A, B)) {
    status = FAILURE;
  } else {
    for (int row = 0; row < A->rows; row++) {
      for (int column = 0; column < A->columns; column++) {
        if (fabs(A->matrix[row][column] - B->matrix[row][column]) >= EPS) {
          status = FAILURE;
          row = A->rows;
          column = A->columns;
        }
      }
    }
  }
  return status;
}
