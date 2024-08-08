#include "s21_operations.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int status = RESULT_OK;
  if (result == NULL || rows < 1 || columns < 1) {
    status = RESULT_INCORRECT;
  } else {
    result->rows = rows;
    result->columns = columns;
    result->matrix = calloc(rows, sizeof(double *));
    // LCOV_EXCL_START
    if (result->matrix == NULL) {
      status = RESULT_ERROR;
      // LCOV_EXCL_STOP
    } else {
      for (int row = 0; row < rows; row++) {
        result->matrix[row] = calloc(columns, sizeof(double));
        // LCOV_EXCL_START
        if (result->matrix[row] == NULL) {
          status = RESULT_ERROR;
          row = rows;
          s21_remove_matrix(result);
        }
        // LCOV_EXCL_STOP
      }
    }
  }
  return status;
}