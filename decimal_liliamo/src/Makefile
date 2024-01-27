.PHONY: all libs check clean
FOLDER = `grep -o "tests/.*/" .vscode/launch.json`
CC = gcc
RM+=-r

all: s21_decimal.a
test: libs run

libs:
	for folders in $(wildcard s21_*/*/) ; do \
		cd $$folders && CFLAGS="$(CFLAGS)" CC=$(CC) $(MAKE) && cd -; \
	done

s21_%.a: libs
#	cp s21_*/liliammo/*{.a,.h} .
	cp s21_decimal/liliammo/s21_decimal.a ./
	cp s21_decimal/liliammo/s21_decimal.h ./

run:
	cd $(FOLDER) && CK_VERBOSITY=verbose CFLAGS="$(CFLAGS)" CC=$(CC) $(MAKE)

check:
	cd $(FOLDER) && $(MAKE) check

gcov_report:
	CFLAGS="-g --coverage -fprofile-arcs -ftest-coverage" $(MAKE) libs run
	lcov -o lcov.genhtml -c -d . --no-external
	genhtml -o report lcov.genhtml

clean:
	ls | grep -v '.vscode\|tests\|s21_[a-z_]*\|Makefile' | xargs $(RM)
	ls | grep 's21_[a-z_]*[.].*' | xargs $(RM)
	for folders in $(wildcard s21_*/*/) ; do \
		cd $$folders && $(MAKE) clean && cd -; \
	done
	cd $(FOLDER) && $(MAKE) clean
