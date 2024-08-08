CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11
LIBFLAGS=-lcheck -lm -lsubunit -lrt -lpthread

OPERATIONS_DIR=operations/

ALL_CFILES=$(wildcard $(OPERATIONS_DIR)s21_*.c)

OBJ_LIBRARY := $(patsubst %.c, %.o, $(ALL_CFILES))

TEST_DIR=tests/
TEST_CFILES=$(wildcard $(TEST_DIR)*_test.c)
TEST_OFILES=$(TEST_CFILES:.c=.o)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

all: clean s21_matrix.a

s21_matrix.a: $(OBJ_LIBRARY)
	ar rcs $@ $(OBJ_LIBRARY)
	ranlib $@
	rm -f */*.o *.o

test: clean $(TEST_CFILES) s21_matrix.a
	$(CC) $(CFLAGS) $(TEST_CFILES) s21_matrix.a -o test.out $(LIBFLAGS)
	./test.out

clean:
	rm -f */*.o */*.out *.a *.o *.out
	rm -f *.gcno *.gcov *.gcda
	rm -f */*.gcno */*.gcov */*.gcda
	rm -f *.info
	rm -fr ./report

gcov_report: CFLAGS += -coverage
gcov_report: clean test
	gcov -f $(ALL_CFILES)
	mkdir report
	./test.out
	lcov --directory . --capture --output-file ./report/coverage.info
	lcov --remove ./report/coverage.info '*/tests/*' -o ./report/coverage.info
	genhtml ./report/coverage.info --output-directory ./report
	rm -f *.gcno *.gcov *.gcda
	rm -f */*.gcno */*.gcov */*.gcda
	rm -f .info

check:
	clang-format --style=Google */*.c -i
	clang-format --style=Google *.h */*.h -i
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h */*.c */*.h

.PHONY: all clean s21_matrix.a test gcov_report