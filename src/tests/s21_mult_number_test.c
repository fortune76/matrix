#include "../s21_matrix.h"
#include "s21_matrix_test.h"
START_TEST(test_s21_mult_number_1) {
  matrix_t A = {0};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;
  matrix_t expected = {0};
  s21_create_matrix(3, 3, &expected);
  expected.matrix[0][0] = 10;
  expected.matrix[0][1] = 20;
  expected.matrix[0][2] = 30;
  expected.matrix[1][0] = 40;
  expected.matrix[1][1] = 50;
  expected.matrix[1][2] = 60;
  expected.matrix[2][0] = 70;
  expected.matrix[2][1] = 80;
  expected.matrix[2][2] = 90;
  matrix_t result = {0};
  int status = s21_mult_number(&A, 10, &result);
  ck_assert_int_eq(status, RESULT_OK);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], expected.matrix[i][j], 1e-7);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_number_2) {
  matrix_t A = {0};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1.123456;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;
  matrix_t expected = {0};
  s21_create_matrix(3, 3, &expected);
  expected.matrix[0][0] = 24.7722048;
  expected.matrix[0][1] = 44.1;
  expected.matrix[0][2] = 66.15;
  expected.matrix[1][0] = 88.2;
  expected.matrix[1][1] = 110.25;
  expected.matrix[1][2] = 132.3;
  expected.matrix[2][0] = 154.35;
  expected.matrix[2][1] = 176.4;
  expected.matrix[2][2] = 198.45;
  matrix_t result = {0};
  int status = s21_mult_number(&A, 22.05, &result);
  ck_assert_int_eq(status, RESULT_OK);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], expected.matrix[i][j], 1e-7);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_number_3) {
  matrix_t A = {0};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 11.3;
  A.matrix[0][1] = 254.12;
  A.matrix[0][2] = -38.9;
  A.matrix[1][0] = -66;
  A.matrix[1][1] = 69.69;
  A.matrix[1][2] = 321;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 8.008;
  A.matrix[2][2] = 123.456;
  matrix_t expected = {0};
  s21_create_matrix(3, 3, &expected);
  expected.matrix[0][0] = 1.3899;
  expected.matrix[0][1] = 31.25676;
  expected.matrix[0][2] = -4.7847;
  expected.matrix[1][0] = -8.118;
  expected.matrix[1][1] = 8.57187;
  expected.matrix[1][2] = 39.483;
  expected.matrix[2][0] = 0;
  expected.matrix[2][1] = 0.984984;
  expected.matrix[2][2] = 15.185088;
  matrix_t result = {0};
  int status = s21_mult_number(&A, 0.123, &result);
  ck_assert_int_eq(status, RESULT_OK);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], expected.matrix[i][j], 1e-7);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_number_4) {
  matrix_t A = {0};
  matrix_t result = {0};
  int status = s21_mult_number(&A, 123, &result);
  ck_assert_int_eq(status, RESULT_INCORRECT);
  s21_remove_matrix(&A);
}
END_TEST

TCase *tcase_s21_mult_number(void) {
  TCase *tcase = tcase_create("s21_mult_number");
  tcase_add_test(tcase, test_s21_mult_number_1);
  tcase_add_test(tcase, test_s21_mult_number_2);
  tcase_add_test(tcase, test_s21_mult_number_3);
  tcase_add_test(tcase, test_s21_mult_number_4);
  return tcase;
}