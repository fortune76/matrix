#include "s21_operations.h"

int s21_matrix_is_same(matrix_t *A, matrix_t *B) {
  return (A->rows == B->rows && A->columns == B->columns);
}

int s21_matrix_is_correct(matrix_t *A) {
  return (A != NULL && A->matrix != NULL && A->rows > 0 && A->columns > 0);
}

int s21_check_for_mult(matrix_t *A, matrix_t *B) {
  return (A->columns == B->rows);
}

double s21_calc_mult_ceil(matrix_t *A, matrix_t *B, int row, int ceil) {
  double result = 0;
  for (int i = 0; i < A->columns; i++) {
    result += A->matrix[row][i] * B->matrix[i][ceil];
  }
  return result;
}

int s21_calc_arithmetic(matrix_t *A, matrix_t *B, matrix_t *result,
                        int operator) {
  int status = RESULT_OK;
  if (!s21_matrix_is_correct(A) || !s21_matrix_is_correct(B)) {
    status = RESULT_INCORRECT;
  }
  if (!status && !s21_matrix_is_same(A, B)) status = RESULT_ERROR;
  if (!status) status = s21_create_matrix(A->rows, A->columns, result);
  if (!status) {
    for (int row = 0; row < A->rows; row++) {
      for (int column = 0; column < A->columns; column++) {
        if (operator)
          result->matrix[row][column] =
              A->matrix[row][column] - B->matrix[row][column];
        else
          result->matrix[row][column] =
              A->matrix[row][column] + B->matrix[row][column];
      }
    }
  }
  return status;
}

int s21_check_square(matrix_t *A) { return (A->rows == A->columns); }

int s21_create_minor_matrix(matrix_t *A, int column, int row, matrix_t *M) {
  int status = RESULT_OK;
  status = s21_create_matrix(A->rows - 1, A->columns - 1, M);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (i != row && j != column) {
        M->matrix[i > row ? i - 1 : i][j > column ? j - 1 : j] =
            A->matrix[i][j];
      }
    }
  }
  return status;
}

double s21_calc_determinant(matrix_t *A) {
  double result = 0;
  matrix_t M;
  for (int i = 0, sign = 1; i < A->rows; i++, sign *= -1) {
    s21_create_minor_matrix(A, 0, i, &M);
    double tmp = 0;
    s21_determinant(&M, &tmp);
    result += tmp * sign * A->matrix[i][0];
    s21_remove_matrix(&M);
  }
  return result;
}