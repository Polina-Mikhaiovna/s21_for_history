CC=gcc -std=c11
CFLAGS=-Wall -Wextra -Werror -g
TST_LIBS=-pkg-config --static --libs check
GCOV_LIBS=--coverage
BUILD_PATH=./
SOURCES=s21_decimal.c
H=s21_decimal.h
LIBO=s21_decimal.o
LIBA=s21_decimal.a
EXE=test
OS=$(shell uname)

all: clean s21_decimal.a test gcov_report

s21_decimal.a: clean
	$(CC) $(CFLAGS) -c $(SOURCES) -o $(BUILD_PATH)$(LIBO)
	ar rcs $(LIBA) $(LIBO)
	ranlib $(LIBA)

test: s21_decimal.a
	$(CC) $(CFLAGS) test.c -L. $(LIBA) $(TST_LIBS) -o $(EXE)
	$(BUILD_PATH)$(EXE)

gcov_report: s21_decimal.a
	$(CC) $(CFLAGS) $(GCOV_LIBS) test.c $(SOURCES) $(LIBA) -L. $(LIBA) $(TST_LIBS) -o $(BUILD_PATH)$(EXE)
	$(BUILD_PATH)$(EXE)
	../datasets/lcov/1.15/libexec/bin/lcov -t "test" -c -d $(BUILD_PATH) --output-file $(BUILD_PATH)coverage.info
	genhtml $(BUILD_PATH)coverage.info --output-directory $(BUILD_PATH)report/
	open report/index.html

check:
	@echo
	@echo ===STYLE TEST===
	@echo
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extension=c *.c *.h
	rm -rf CPPLINT.cfg
ifeq ($(OS), Linux)
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./test
else
	leaks --atExit -- test
endif

clean:
	rm -rf *.a *.o *.info *.gcda *.gcno *.gcov report/ $(EXE)

rebuild: clean all

