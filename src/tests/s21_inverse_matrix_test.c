#include "../s21_matrix.h"
#include "s21_matrix_test.h"

START_TEST(test_s21_inverse_matrix_1) {
  matrix_t A = {0};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;
  matrix_t expected = {0};
  s21_create_matrix(3, 3, &expected);
  expected.matrix[0][0] = 1;
  expected.matrix[0][1] = -1;
  expected.matrix[0][2] = 1;
  expected.matrix[1][0] = -38;
  expected.matrix[1][1] = 41;
  expected.matrix[1][2] = -34;
  expected.matrix[2][0] = 27;
  expected.matrix[2][1] = -29;
  expected.matrix[2][2] = 24;
  matrix_t result = {0};
  int status = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(status, RESULT_OK);
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      ck_assert_double_eq_tol(expected.matrix[i][j], result.matrix[i][j], 1e-7);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_inverse_matrix_2) {
  matrix_t A = {0};
  matrix_t result = {0};
  int status = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(status, RESULT_INCORRECT);
}
END_TEST

START_TEST(test_s21_inverse_matrix_3) {
  matrix_t A = {0};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 5.54;
  A.matrix[0][1] = -546.12;
  A.matrix[0][2] = 1.0065;
  A.matrix[1][0] = 6.96;
  A.matrix[1][1] = 0.88;
  A.matrix[1][2] = 32.489;
  A.matrix[2][0] = 9.08;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 189;
  matrix_t expected = {0};
  s21_create_matrix(3, 3, &expected);
  expected.matrix[0][0] = 0.0002980;
  expected.matrix[0][1] = 0.1849112;
  expected.matrix[0][2] = -0.0317877;
  expected.matrix[1][0] = -0.0018281;
  expected.matrix[1][1] = 0.0018594;
  expected.matrix[1][2] = -0.0003099;
  expected.matrix[2][0] = -0.0000143;
  expected.matrix[2][1] = -0.0088836;
  expected.matrix[2][2] = 0.0068182;
  matrix_t result = {0};
  int status = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(status, RESULT_OK);
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      ck_assert_double_eq_tol(expected.matrix[i][j], result.matrix[i][j], 1e-7);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_inverse_matrix_4) {
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
  matrix_t result = {0};
  int status = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(status, RESULT_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

TCase *tcase_s21_inverse_matrix(void) {
  TCase *tcase = tcase_create("s21_inverse_matrix");
  tcase_add_test(tcase, test_s21_inverse_matrix_1);
  tcase_add_test(tcase, test_s21_inverse_matrix_2);
  tcase_add_test(tcase, test_s21_inverse_matrix_3);
  tcase_add_test(tcase, test_s21_inverse_matrix_4);
  return tcase;
}