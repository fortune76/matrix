#include "s21_operations.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  return s21_calc_arithmetic(A, B, result, MINUS);
}