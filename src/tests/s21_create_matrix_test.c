#include "../s21_matrix.h"
#include "s21_matrix_test.h"

START_TEST(test_s21_create_matrix_1) {
  matrix_t A = {0};
  int status = s21_create_matrix(1, 1, &A);
  ck_assert_int_eq(status, RESULT_OK);
  ck_assert_int_eq(A.rows, 1);
  ck_assert_int_eq(A.columns, 1);
  ck_assert_double_eq_tol(A.matrix[0][0], 0, 1e-7);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_create_matrix_2) {
  matrix_t A = {0};
  int status = s21_create_matrix(0, 1, &A);
  ck_assert_int_eq(status, RESULT_INCORRECT);
  s21_remove_matrix(&A);
}
END_TEST

TCase *tcase_s21_create_matrix(void) {
  TCase *tcase = tcase_create("s21_create_matrix");
  tcase_add_test(tcase, test_s21_create_matrix_1);
  tcase_add_test(tcase, test_s21_create_matrix_2);
  return tcase;
}