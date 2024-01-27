#ifndef SRC_GREP_S21_GREP_H_
#define SRC_GREP_S21_GREP_H_

#include <stdio.h>
#include <getopt.h>
#include <regex.h>
#include <string.h>
#include <stdlib.h>

typedef struct flags {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
} flg_t;

int parser(int argc, char**argv, flg_t *flg, char *pattern);
void grepping(int argc, char**argv, flg_t *flg, char *pattern);
void preparing_file(flg_t *flg, char *file, int file_count, char *pattern);
void output(flg_t *flg, FILE *fp, regex_t reg, char *file, int file_count);

#endif  // SRC_GREP_S21_GREP_H_
