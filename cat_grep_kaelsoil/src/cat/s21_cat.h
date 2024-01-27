#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <ctype.h>

#ifndef SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_
#define MAX_STR 2

typedef struct flag {
    int b;
    int e;
    int n;
    int s;
    int t;
    int v;
}flags;

void open_file(int argc, char **argv, int count, flags *flg);
void pars_flg_file(int argc, char **argv, flags *f, int *count);
void check_flag(flags *flg);
void print_struct(flags *f);
void open_file_N(int argc, char **argv, int count, flags *flg);
void open_file_E(int argc, char **argv, int count, flags *flg);
void print_number_of_line(int *counter_str, int *fin_str);
void print_number_of_first_line(int *fin_str, int *counter_str, FILE *f);
int is_empty_line(int fin_str, int not_empty_line);
int compare_spec_sym(char str);
#endif  // SRC_CAT_S21_CAT_H_
