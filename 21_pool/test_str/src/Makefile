BPATH=../materials/build/
CC=gcc
CFLAGS=-std=c11 -Wall -Werror -Wextra
SOURCES=s21_string.c s21_sprintf.c s21_sscanf.c
OBJECTS=$(SOURCES:.c=.o)
TEST_FILES = s21_test.c test_string.c test_sprintf.c test_sscanf.c s21_string.a
PFLAGS=-fprofile-arcs -ftest-coverage
GCOVFLAGS=--coverage
LCOVPATH=../datasets/lcov/1.15/libexec/bin/
HTML=$(LCOVPATH)lcov -t "test" -o rep.info -c -d .; $(LCOVPATH)genhtml -o report rep.info
OS := $(shell uname)

ifeq ($(OS), Linux)
LINUX_LIBS=-lcheck
else
LINUX_LIBS=-lcheck -lsubunit -lm -lrt -lpthread -D_GNU_SOURCE
endif

all: clean gcov_report

s21_string.a: clean
	$(CC) $(CFLAGS) -c $(PFLAGS) $(SOURCES)
	ar rcs s21_string.a $(OBJECTS)
	ranlib s21_string.a

test: clean s21_string.a
	$(CC) $(CFLAGS) $(GCOVFLAGS) $(PFLAGS) $(TEST_FILES) $(SOURCES) -o $(BPATH)test $(LINUX_LIBS)
	$(BPATH)test

gcov_report: clean test
	$(HTML)
	open ./report/index.html

clean:
	rm -rf *.o *.a *.so *.gcda *.gcno *.gch rep.info *.html *.css $(BPATH)test report

rebuild: clean all