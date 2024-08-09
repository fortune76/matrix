#include "../s21_matrix.h"
#include "s21_matrix_test.h"

START_TEST(test_s21_calc_complements_1) {
  matrix_t A = {0};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;
  matrix_t expected = {0};
  s21_create_matrix(3, 3, &expected);
  expected.matrix[0][0] = 0;
  expected.matrix[0][1] = 10;
  expected.matrix[0][2] = -20;
  expected.matrix[1][0] = 4;
  expected.matrix[1][1] = -14;
  expected.matrix[1][2] = 8;
  expected.matrix[2][0] = -8;
  expected.matrix[2][1] = -2;
  expected.matrix[2][2] = 4;
  matrix_t result = {0};
  int status = s21_calc_complements(&A, &result);
  ck_assert_int_eq(status, RESULT_OK);
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], expected.matrix[i][j], EPS);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_calc_complements_2) {
  matrix_t A = {0};
  s21_create_matrix(2, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  matrix_t result = {0};
  int status = s21_calc_complements(&A, &result);
  ck_assert_int_eq(status, RESULT_INCORRECT);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_calc_complements_3) {
  matrix_t A = {0};
  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = 4;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 1;
  A.matrix[0][3] = 4;
  A.matrix[1][0] = 54;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 123;
  A.matrix[1][3] = 8;
  A.matrix[2][0] = 5123;
  A.matrix[2][1] = 44;
  A.matrix[2][2] = 5;
  A.matrix[2][3] = 7;
  A.matrix[3][0] = 1;
  A.matrix[3][1] = 123;
  A.matrix[3][2] = 56;
  A.matrix[3][3] = 9;
  matrix_t expected = {0};
  s21_create_matrix(4, 4, &expected);
  expected.matrix[0][0] = 70252;
  expected.matrix[0][1] = 3393974;
  expected.matrix[0][2] = 4785070;
  expected.matrix[0][3] = -76165886;
  expected.matrix[1][0] = -6126;
  expected.matrix[1][1] = 1100044;
  expected.matrix[1][2] = -2287980;
  expected.matrix[1][3] = -796934;
  expected.matrix[2][0] = -55162;
  expected.matrix[2][1] = -13762;
  expected.matrix[2][2] = 20402;
  expected.matrix[2][3] = 67264;
  expected.matrix[3][0] = 17126;
  expected.matrix[3][1] = -2475546;
  expected.matrix[3][2] = -108806;
  expected.matrix[3][3] = 3104508;
  matrix_t result = {0};
  int status = s21_calc_complements(&A, &result);
  ck_assert_int_eq(status, RESULT_OK);
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], expected.matrix[i][j], EPS);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_calc_complements_4) {
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
  int status = s21_calc_complements(&A, &result);
  ck_assert_int_eq(status, RESULT_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_calc_complements_5) {
  matrix_t A = {0};
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 12.123;
  A.matrix[0][1] = 123.124;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 523;
  matrix_t expected = {0};
  s21_create_matrix(2, 2, &expected);
  expected.matrix[0][0] = 523;
  expected.matrix[0][1] = -2;
  expected.matrix[1][0] = -123.124;
  expected.matrix[1][1] = 12.123;
  matrix_t result = {0};
  int status = s21_calc_complements(&A, &result);
  ck_assert_int_eq(status, RESULT_OK);
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], expected.matrix[i][j], EPS);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}
END_TEST

TCase *tcase_s21_calc_complements(void) {
  TCase *tcase = tcase_create("s21_calc_complements");
  tcase_add_test(tcase, test_s21_calc_complements_1);
  tcase_add_test(tcase, test_s21_calc_complements_2);
  tcase_add_test(tcase, test_s21_calc_complements_3);
  tcase_add_test(tcase, test_s21_calc_complements_4);
  tcase_add_test(tcase, test_s21_calc_complements_5);
  return tcase;
}