  CC ?= clang
SHELL := /bin/bash
CHECK_H  = `pkg-config --static --libs check`
DEFP = ../../s21_*/*
LIST_H = $(shell ls $(DEFP)/*.h)
RM=rm -rf

ifeq ($(shell uname -s), Darwin)
INCL_HEDS = $(shell echo $(LIST_H) | sed -e 's/^/ /g' -e 's/ / -include/g')
else
INCL_HEDS = $(shell echo $(LIST_H) | sed -e 's/^/ /g' -e 's/\s/ -include/g')
endif

all: s21_decimal_test

s21_%_test.c: s21_checkmk.*
#	checkmk $^ > $@
	checkmk s21_checkmk.* > $@

#s21_%_test: s21_%_test.c $(DEFP)/*.a
#	$(CC) $(CFLAGS) -Ofast $^ $(INCL_HEDS) $(CHECK_H) -o a.exe
#	./a.exe

s21_%_test: s21_%_test.c $(DEFP)/*.a
#	cp ../../s21_*/*/*.{a,h} .
	$(CC) $(CFLAGS) $< ../../s21_*/*/*.a $(CHECK_H) -o a.exe
	./a.exe

clean:
	ls | grep -v 's21_[a-z_]*[.]ts\|Makefile' | xargs $(RM)








ECHO=echo -e
ifeq ($(shell uname -s), Darwin)
ECHO=echo
endif

check:
	@$(ECHO) "\033[0;32m"
#	cp ../../materials/linters/CPPLINT.cfg . && python3 ../../materials/linters/cpplint.py --extensions=c *.? liba/*.?
	-cpplint --extensions=h,c --recursive ../../
	@$(ECHO) "\033[0;34m"
	cppcheck -q --enable=all --inconclusive --std=c11 --suppress=missingIncludeSystem ../../ --suppress=unusedFunction
#	@$(ECHO) "\033[0;35m"
ifeq ($(shell uname -s), Darwin)
	bash -c "grep -e 'leaks for' <(CK_FORK=no leaks -q --atExit -- ./a.exe)"
else
	@CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt ./a.exe
	@tail -n 1 RESULT_VALGRIND.txt
endif
