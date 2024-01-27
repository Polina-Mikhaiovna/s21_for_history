#include "s21_cat.h"


void main(int argc, char **argv) {
    flags *flg;
    int count = 1;
    flg = malloc(sizeof(flags));
    flg->b = 0;
    flg->n = 0;
    flg->v = 0;
    flg->e = 0;
    flg->s = 0;
    flg->t = 0;

    // print_struct(flg);
    pars_flg_file(argc, argv, flg, &count);  // парсинг флагов и файлов
    check_flag(flg);
    // printf("count = %d\n", count);
    // print_struct(flg);
    // open_file_E(argc, argv, count, flg);
    open_file(argc, argv, count, flg);
    free(flg);
}

void check_flag(flags *flg) {
    if (flg->b == 1 && flg->n == 1) {
        flg->n = 0;
    }
}

void open_file(int argc, char **argv, int count, flags *flg) {
    FILE *f;
    int counter_str;
    int fin_str = 1;
    int not_empty_line;
    int duble_empty_line;
    char str[MAX_STR];
    while (count < argc) {
        counter_str = 1;
        if ((f = fopen(argv[count], "r")) != NULL) {
            if (!feof(f) && flg->b) {
                print_number_of_first_line(&fin_str, &counter_str, f);
            }
            not_empty_line = 0;
            duble_empty_line = 0;

            while (!feof(f)) {
                char* estr = fgets(str, sizeof(str), f);

                if (!not_empty_line && str[0] != '\n' && estr != NULL) {
                    not_empty_line = 1;
                    duble_empty_line = 0;
                }

                if (flg->b && str[0] != '\n' && fin_str) {
                    print_number_of_line(&counter_str, &fin_str);
                }
                if (flg->n && fin_str && !duble_empty_line) {
                    print_number_of_line(&counter_str, &fin_str);
                }

                if (str[0] == '\n' || estr == NULL) {
                    fin_str = 1;
                } else {
                    fin_str = 0;
                }
                // if (flg->v && compare_spec_sym(str[0])) {
                //     printf("^");
                //     continue;
                // }
                if (flg->v == 1) {
                    if (isprint(str[0]) == 0 && str[0] != 10 && str[0] != 9) {
                        printf("^");
                        if (str[0] == 127) {
                        str[0] -= 64;
                        } else {
                        str[0] += 64;
                        }
                    }
                }
                if (flg->t && str[0] == '\t') {
                    printf("^I");
                    continue;
                }

                if (flg->e && str[0] == '\n' && estr != NULL && !duble_empty_line) {
                    printf("$");
                }

                if (flg->s && is_empty_line(fin_str, not_empty_line) && duble_empty_line) {
                    continue;
                }
                if (flg->s && is_empty_line(fin_str, not_empty_line) && !duble_empty_line) {
                    duble_empty_line = 1;
                }

                if (fin_str) {
                    not_empty_line = 0;
                }

                if (estr != NULL) {
                    printf("%s", str);
                }
            }
            fclose(f);
            count++;
        }
    }
}

int compare_spec_sym(char str) {
    int is_spec_sym = 0;
    // if (isprint(str) == 0 && str != 10 && str != 9) {
    //     is_spec_sym = 1;
    //     if (str == 127) {
    //       str -= 64;
    //     } else {
    //       str += 64;
    //     }
    // }
    if (str == '\0' || str == '\a' || str == '\b' || str == '\v'|| str == '\f'|| str == '\r') {
        is_spec_sym = 1;
    }
    return is_spec_sym;
}

int is_empty_line(int fin_str, int not_empty_line) {
    int empty_line = 0;
    if (fin_str && !not_empty_line) {
        empty_line = 1;
    }
    return empty_line;
}

void print_number_of_first_line(int *fin_str, int *counter_str, FILE *f) {
    char str[MAX_STR];
    char* estr = fgets(str, sizeof(str), f);
    if (str[0] == '\n' || estr == NULL) {
        *fin_str = 1;
    } else {
        print_number_of_line(counter_str, fin_str);
    }
    printf("%s", str);
}

void print_number_of_line(int *counter_str, int *fin_str) {
    // printf("%6d  ", *counter_str);
    printf("%6d\t", *counter_str);
    *counter_str += 1;
    *fin_str = 0;
}

void pars_flg_file(int argc, char **argv, flags *f, int *count) {
    int res;
    static struct option long_options[] = {
        {"number-nonblank", 0, 0, 'b'},
        {"number", 0, 0, 'n'},
        {"squeeze-blank", 0, 0, 's'},
        {0, 0, 0, 0}
    };
    while ((res = getopt_long(argc, argv, "bentsETv", long_options, NULL)) != -1) {
        switch (res) {
        case 'b': f->b = 1; break;  // n->n = 0;
        case 'e': f->e = 1; f->v = 1; break;
        case 'n': f->n = 1; break;
        case 's': f->s = 1; break;
        case 't': f->t = 1; f->v = 1; break;
        case 'v': f->v = 1; break;
        case 'E': f->e = 1; break;
        case 'T': f->t = 1; break;
        default: break;
        }
        *count = *count + 1;  // заменить на глобальную переменную
    }
}

void print_struct(flags *f) {
    printf("b = %d || e = %d || n = %d || s = %d || t = %d || v = %d\n", f->b, f->e, f->n, f->s, f->t, f->v);
}
