#include "../s21_matrix.h"
#include "s21_matrix_test.h"
START_TEST(test_s21_mult_matrix_1) {
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
  expected.matrix[0][0] = 30;
  expected.matrix[0][1] = 36;
  expected.matrix[0][2] = 42;
  expected.matrix[1][0] = 66;
  expected.matrix[1][1] = 81;
  expected.matrix[1][2] = 96;
  expected.matrix[2][0] = 102;
  expected.matrix[2][1] = 126;
  expected.matrix[2][2] = 150;
  matrix_t result = {0};
  int status = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(status, RESULT_OK);
  for (int i = 0; i < expected.rows; i++) {
    for (int j = 0; j < expected.columns; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], expected.matrix[i][j], EPS);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_matrix_2) {
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
  matrix_t B = {0};
  s21_create_matrix(3, 3, &B);
  B.matrix[0][0] = 6.6;
  B.matrix[0][1] = 123.03;
  B.matrix[0][2] = 2.3;
  B.matrix[1][0] = 44.4;
  B.matrix[1][1] = 0;
  B.matrix[1][2] = 9.0909;
  B.matrix[2][0] = 34.3434;
  B.matrix[2][1] = 0.0002;
  B.matrix[2][2] = 300;
  matrix_t expected = {0};
  s21_create_matrix(3, 3, &expected);
  expected.matrix[0][0] = 10021.54974;
  expected.matrix[0][1] = 1390.23122;
  expected.matrix[0][2] = -9333.830492;
  expected.matrix[1][0] = 13682.8674;
  expected.matrix[1][1] = -8119.9158;
  expected.matrix[1][2] = 96781.744821;
  expected.matrix[2][0] = 4595.4539904;
  expected.matrix[2][1] = 0.0246912;
  expected.matrix[2][2] = 37109.5999272;
  matrix_t result = {0};
  int status = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(status, RESULT_OK);
  for (int i = 0; i < expected.rows; i++) {
    for (int j = 0; j < expected.columns; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], expected.matrix[i][j], EPS);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_matrix_3) {
  matrix_t A = {0};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = -4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 2;
  A.matrix[2][1] = 3;
  A.matrix[2][2] = 11;
  matrix_t B = {0};
  s21_create_matrix(3, 2, &B);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 5;
  B.matrix[2][0] = 12;
  B.matrix[2][1] = 3;
  matrix_t expected = {0};
  s21_create_matrix(3, 2, &expected);
  expected.matrix[0][0] = 43;
  expected.matrix[0][1] = 21;
  expected.matrix[1][0] = 83;
  expected.matrix[1][1] = 35;
  expected.matrix[2][0] = 143;
  expected.matrix[2][1] = 52;
  matrix_t result = {0};
  int status = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(status, RESULT_OK);
  for (int i = 0; i < expected.rows; i++) {
    for (int j = 0; j < expected.columns; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], expected.matrix[i][j], EPS);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_matrix_4) {
  matrix_t A = {0};
  s21_create_matrix(2, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 4;
  matrix_t B = {0};
  s21_create_matrix(3, 2, &B);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 5;
  B.matrix[2][0] = 12;
  B.matrix[2][1] = 3;
  matrix_t expected = {0};
  s21_create_matrix(2, 2, &expected);
  expected.matrix[0][0] = 43;
  expected.matrix[0][1] = 21;
  expected.matrix[1][0] = 67;
  expected.matrix[1][1] = 45;
  matrix_t result = {0};
  int status = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(status, RESULT_OK);
  for (int i = 0; i < expected.rows; i++) {
    for (int j = 0; j < expected.columns; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], expected.matrix[i][j], EPS);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_matrix_5) {
  matrix_t A = {0};
  s21_create_matrix(2, 3, &A);
  A.matrix[0][0] = 1.001;
  A.matrix[0][1] = 232.123;
  A.matrix[0][2] = -353.1123;
  A.matrix[1][0] = 400.0123;
  A.matrix[1][1] = -523.78;
  A.matrix[1][2] = 4.5;
  matrix_t B = {0};
  s21_create_matrix(3, 2, &B);
  B.matrix[0][0] = 1.8789;
  B.matrix[0][1] = 2.123;
  B.matrix[1][0] = 3.445;
  B.matrix[1][1] = 5.444111;
  B.matrix[2][0] = 12.45;
  B.matrix[2][1] = 312.1;
  matrix_t expected = {0};
  s21_create_matrix(2, 2, &expected);
  expected.matrix[0][0] = -3594.7036211;
  expected.matrix[0][1] = -108940.5203293;
  expected.matrix[1][0] = -996.8139895;
  expected.matrix[1][1] = -597.8403467;
  matrix_t result = {0};
  int status = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(status, RESULT_OK);
  for (int i = 0; i < expected.rows; i++) {
    for (int j = 0; j < expected.columns; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], expected.matrix[i][j], EPS);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_matrix_6) {
  matrix_t A = {0};
  s21_create_matrix(2, 3, &A);
  A.matrix[0][0] = 1.001;
  A.matrix[0][1] = 232.123;
  A.matrix[0][2] = -353.1123;
  A.matrix[1][0] = 400.0123;
  A.matrix[1][1] = -523.78;
  A.matrix[1][2] = 4.5;
  matrix_t B = {0};
  matrix_t result = {0};
  int status = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(status, RESULT_INCORRECT);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_mult_matrix_7) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  int status = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(status, RESULT_INCORRECT);
  s21_remove_matrix(&A);
}
END_TEST

TCase *tcase_s21_mult_matrix(void) {
  TCase *tcase = tcase_create("s21_mult_matrix");
  tcase_add_test(tcase, test_s21_mult_matrix_1);
  tcase_add_test(tcase, test_s21_mult_matrix_2);
  tcase_add_test(tcase, test_s21_mult_matrix_3);
  tcase_add_test(tcase, test_s21_mult_matrix_4);
  tcase_add_test(tcase, test_s21_mult_matrix_5);
  tcase_add_test(tcase, test_s21_mult_matrix_6);
  tcase_add_test(tcase, test_s21_mult_matrix_7);
  return tcase;
}