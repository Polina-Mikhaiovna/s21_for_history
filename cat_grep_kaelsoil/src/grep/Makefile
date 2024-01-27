OS := $(shell uname -s)

ifeq ($(OS), Drawin)
 CC += -D OS_MAC
endif
ifeq ($(OS), Linux)
 CC += -D OS_LINUX
endif

CC = gcc -Wall -Werror -Wextra -std=c11

all: clean s21_grep clear

s21_grep: s21_grep.o
	$(CC) -o s21_grep s21_grep.o

s21_grep.o: s21_grep.c
	$(CC) -c s21_grep.c

test: t_grep.sh
	bash t_grep.sh

test1: s21_test_grep.sh
	bash s21_test_grep.sh

s21_grep_valgrind: s21_grep.c s21_grep.h
	$(CC) -O0 -g s21_grep.c -o s21_grep
	valgrind --leak-check=full --track-origins=yes ./s21_grep -e "qui" test.txt

style:  
	cp ../../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../../materials/linters/cpplint.py --extension=c *.c
	rm -rf CPPLINT.cfg

check:
	cppcheck *.h *.c
	cp ../../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../../materials/linters/cpplint.py --extensions=c s21_grep.c
	python3 ../../materials/linters/cpplint.py --extensions=c s21_grep.h
	rm CPPLINT.cfg
	
clean:
	rm -rf *.o
	rm -rf s21_grep
	rm -rf log.txt
	rm -rf RESULT_VALGRIND.txt

clear:
	clear

