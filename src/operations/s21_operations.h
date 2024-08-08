#ifndef S21_OPERATIONS_H
#define S21_OPERATIONS_H

#include <math.h>
#include <stdlib.h>

#include "../s21_matrix.h"

#define PLUS 0
#define MINUS 1

int s21_matrix_is_same(matrix_t *A, matrix_t *B);
int s21_matrix_is_correct(matrix_t *A);
int s21_check_for_mult(matrix_t *A, matrix_t *B);
int s21_calc_arithmetic(matrix_t *A, matrix_t *B, matrix_t *result,
                        int operator);
double s21_calc_mult_ceil(matrix_t *A, matrix_t *B, int row, int ceil);
int s21_check_square(matrix_t *A);
int s21_create_minor_matrix(matrix_t *A, int column, int row, matrix_t *M);
double s21_calc_determinant(matrix_t *A);

#endif