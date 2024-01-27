CC ?= gcc
SHELL := /bin/bash
CHECK_H  = `pkg-config --static --libs check`
DEFP = ../../s21_*/*
LIST_H = $(shell ls $(DEFP)/*.h)
INCL_HEDS = $(shell echo $(LIST_H) | sed -e 's/^/ /g' -e 's/\s/ -include/g')

all: s21_decimal_test

s21_%_test: s21_%_test.c $(DEFP)/*.a
	$(CC) $(CFLAGS) -lm -g -Og $^ $(INCL_HEDS) $(CHECK_H) -o $@
	./$@

clean:
	ls | grep -v 's21_[a-z_]*[.]c\|Makefile' | xargs $(RM)