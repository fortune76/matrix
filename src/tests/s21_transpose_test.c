#include "../s21_matrix.h"
#include "s21_matrix_test.h"

START_TEST(test_s21_transpose_1) {
  matrix_t A = {0};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 5.54;
  A.matrix[0][2] = 7.7;
  A.matrix[1][0] = 5;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = -0.12;
  A.matrix[2][0] = 12.33;
  A.matrix[2][1] = 5.5567;
  A.matrix[2][2] = 0.54;
  matrix_t expected = {0};
  s21_create_matrix(3, 3, &expected);
  expected.matrix[0][0] = 1;
  expected.matrix[0][1] = 5;
  expected.matrix[0][2] = 12.33;
  expected.matrix[1][0] = 5.54;
  expected.matrix[1][1] = 3;
  expected.matrix[1][2] = 5.5567;
  expected.matrix[2][0] = 7.7;
  expected.matrix[2][1] = -0.12;
  expected.matrix[2][2] = 0.54;
  matrix_t result = {0};
  int status = s21_transpose(&A, &result);
  ck_assert_int_eq(status, RESULT_OK);
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], expected.matrix[i][j], 1e-7);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_transpose_2) {
  matrix_t A = {0};
  s21_create_matrix(3, 2, &A);
  A.matrix[0][0] = 5;
  A.matrix[0][1] = 6;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 3;
  A.matrix[2][0] = 4;
  A.matrix[2][1] = 5;
  matrix_t expected = {0};
  s21_create_matrix(2, 3, &expected);
  expected.matrix[0][0] = 5;
  expected.matrix[0][1] = 2;
  expected.matrix[0][2] = 4;
  expected.matrix[1][0] = 6;
  expected.matrix[1][1] = 3;
  expected.matrix[1][2] = 5;
  matrix_t result = {0};
  int status = s21_transpose(&A, &result);
  ck_assert_int_eq(status, RESULT_OK);
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], expected.matrix[i][j], 1e-7);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_transpose_3) {
  matrix_t A = {0};
  matrix_t result = {0};
  int status = s21_transpose(&A, &result);
  ck_assert_int_eq(status, RESULT_INCORRECT);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

TCase *tcase_s21_transpose(void) {
  TCase *tcase = tcase_create("s21_transpose");
  tcase_add_test(tcase, test_s21_transpose_1);
  tcase_add_test(tcase, test_s21_transpose_2);
  tcase_add_test(tcase, test_s21_transpose_3);
  return tcase;
}