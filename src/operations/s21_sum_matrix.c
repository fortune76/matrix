#include "s21_operations.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  return s21_calc_arithmetic(A, B, result, PLUS);
}