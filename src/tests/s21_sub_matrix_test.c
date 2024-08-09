#include "../s21_matrix.h"
#include "s21_matrix_test.h"
START_TEST(test_s21_sub_matrix_1) {
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
  matrix_t B = {0};
  s21_create_matrix(3, 3, &B);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[0][2] = 3;
  B.matrix[1][0] = 4;
  B.matrix[1][1] = 5;
  B.matrix[1][2] = 6;
  B.matrix[2][0] = 7;
  B.matrix[2][1] = 8;
  B.matrix[2][2] = 9;
  matrix_t expected = {0};
  s21_create_matrix(3, 3, &expected);
  expected.matrix[0][0] = 0;
  expected.matrix[0][1] = 0;
  expected.matrix[0][2] = 0;
  expected.matrix[1][0] = 0;
  expected.matrix[1][1] = 0;
  expected.matrix[1][2] = 0;
  expected.matrix[2][0] = 0;
  expected.matrix[2][1] = 0;
  expected.matrix[2][2] = 0;
  matrix_t result = {0};
  int status = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(status, RESULT_OK);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], expected.matrix[i][j], EPS);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sub_matrix_2) {
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
  A.matrix[2][2] = 8;
  matrix_t B = {0};
  s21_create_matrix(3, 3, &B);
  B.matrix[0][0] = 1.123456;
  B.matrix[0][1] = 2;
  B.matrix[0][2] = 3;
  B.matrix[1][0] = 4;
  B.matrix[1][1] = 5;
  B.matrix[1][2] = 6;
  B.matrix[2][0] = 7;
  B.matrix[2][1] = 8;
  B.matrix[2][2] = 9;
  matrix_t expected = {0};
  s21_create_matrix(3, 3, &expected);
  expected.matrix[0][0] = 0;
  expected.matrix[0][1] = 0;
  expected.matrix[0][2] = 0;
  expected.matrix[1][0] = 0;
  expected.matrix[1][1] = 0;
  expected.matrix[1][2] = 0;
  expected.matrix[2][0] = 0;
  expected.matrix[2][1] = 0;
  expected.matrix[2][2] = -1;
  matrix_t result = {0};
  int status = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(status, RESULT_OK);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], expected.matrix[i][j], EPS);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sub_matrix_3) {
  matrix_t A = {0};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = -1.123456;
  A.matrix[0][1] = 22;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9.09;
  matrix_t B = {0};
  s21_create_matrix(3, 3, &B);
  B.matrix[0][0] = 1.123456;
  B.matrix[0][1] = 2;
  B.matrix[0][2] = 3.3333;
  B.matrix[1][0] = 4;
  B.matrix[1][1] = -55;
  B.matrix[1][2] = 6;
  B.matrix[2][0] = 7;
  B.matrix[2][1] = 8;
  B.matrix[2][2] = 9;
  matrix_t expected = {0};
  s21_create_matrix(3, 3, &expected);
  expected.matrix[0][0] = -2.246912;
  expected.matrix[0][1] = 20;
  expected.matrix[0][2] = -0.3333;
  expected.matrix[1][0] = 0;
  expected.matrix[1][1] = 60;
  expected.matrix[1][2] = 0;
  expected.matrix[2][0] = 0;
  expected.matrix[2][1] = 0;
  expected.matrix[2][2] = 0.09;
  matrix_t result = {0};
  int status = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(status, RESULT_OK);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], expected.matrix[i][j], EPS);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sub_matrix_4) {
  matrix_t A = {0};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = -1.123456;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9.09;
  matrix_t B = {0};
  matrix_t result = {0};
  int status = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(status, RESULT_INCORRECT);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_sub_matrix_5) {
  matrix_t A = {0};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = -1.123456;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9.09;
  matrix_t B = {0};
  s21_create_matrix(2, 3, &B);
  B.matrix[0][0] = 1.123456;
  B.matrix[0][1] = 2;
  B.matrix[0][2] = 3.3333;
  B.matrix[1][0] = 4;
  B.matrix[1][1] = -55;
  B.matrix[1][2] = 6;
  matrix_t result = {0};
  int status = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(status, RESULT_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

TCase *tcase_s21_sub_matrix(void) {
  TCase *tcase = tcase_create("s21_sub_matrix");
  tcase_add_test(tcase, test_s21_sub_matrix_1);
  tcase_add_test(tcase, test_s21_sub_matrix_2);
  tcase_add_test(tcase, test_s21_sub_matrix_3);
  tcase_add_test(tcase, test_s21_sub_matrix_4);
  tcase_add_test(tcase, test_s21_sub_matrix_5);
  return tcase;
}