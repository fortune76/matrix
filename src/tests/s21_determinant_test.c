#include "../s21_matrix.h"
#include "s21_matrix_test.h"

START_TEST(test_s21_determinant_matrix_1) {
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
  double result = 0;
  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, RESULT_OK);
  ck_assert_double_eq_tol(result, 0, 1e-7);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_matrix_2) {
  matrix_t A = {0};
  s21_create_matrix(2, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  double result = 0;
  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, RESULT_INCORRECT);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_matrix_3) {
  matrix_t A = {0};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 123;
  A.matrix[0][1] = 554;
  A.matrix[0][2] = 7.7;
  A.matrix[1][0] = 66;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = -0.12;
  A.matrix[2][0] = 123;
  A.matrix[2][1] = 550.5567;
  A.matrix[2][2] = 0.54;
  double result = 0;
  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, RESULT_OK);
  ck_assert_double_eq_tol(result, 257355.491832, 1e-7);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_matrix_4) {
  matrix_t A = {0};
  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 5.54;
  A.matrix[0][2] = 7.7;
  A.matrix[0][3] = 0.125;
  A.matrix[1][0] = 5;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = -0.12;
  A.matrix[1][3] = 7.71;
  A.matrix[2][0] = 12.33;
  A.matrix[2][1] = 5.5567;
  A.matrix[2][2] = 0.54;
  A.matrix[2][3] = -6;
  A.matrix[3][0] = 90;
  A.matrix[3][1] = 0.344;
  A.matrix[3][2] = 120.4;
  A.matrix[3][3] = 3;
  double result = 0;
  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, RESULT_OK);
  ck_assert_double_eq_tol(result, -116373.4068860, 1e-7);
  s21_remove_matrix(&A);
}
END_TEST

TCase *tcase_s21_determinant_matrix(void) {
  TCase *tcase = tcase_create("s21_determinant_matrix");
  tcase_add_test(tcase, test_s21_determinant_matrix_1);
  tcase_add_test(tcase, test_s21_determinant_matrix_2);
  tcase_add_test(tcase, test_s21_determinant_matrix_3);
  tcase_add_test(tcase, test_s21_determinant_matrix_4);
  return tcase;
}