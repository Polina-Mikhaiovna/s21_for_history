CC=gcc
WFLAGS=-Wall -Werror -Wextra
SRCDIR=../src
TESTDIR=../test
CAT:=s21_cat

all: $(CAT)

s21_cat: s21_cat.o
	$(CC) s21_cat.o -o $(CAT)

s21_cat.o: s21_cat.c s21_cat.h
	$(CC) -c s21_cat.c

s21_cat_valgrind: s21_cat.c s21_cat.h
	$(CC) -O0 -g s21_cat.c -o s21_cat
	valgrind --leak-check=full --track-origins=yes ./s21_cat test.txt -b -e -n -s -t

tests: $(CAT)
	sh t_cat.sh 

style:  
	cp ../../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../../materials/linters/cpplint.py --extension=c *.c
	rm -rf CPPLINT.cfg

clean:
	rm -rf *.o *.a *.exe *.out s21_cat

rebuild: clean all
