#include "s21_grep.h"

int main(int argc, char *argv[]) {
    int res;
    char pattern[99999] = {0};
    flg_t *flg;
    flg = malloc(sizeof(flg_t));
    flg->l = 0;
    flg->c = 0;
    flg->h = 0;
    flg->v = 0;
    flg->s = 0;
    flg->n = 0;
    flg->e = 0;
    flg->i = 0;
    // memset(&flg, 0, sizeof(flg));  // инициализирование флагов
    res = parser(argc, argv, flg, pattern);  // парсинг всех флагов
    if (argc >= 3 && res != 1) {  // пров на корр-ть кол переменных в грепе
        grepping(argc, argv, flg, pattern);  // начало обработки
    }
    free(flg);
    return res;
}

int parser(int argc, char**argv, flg_t *flg, char *pattern) {
    int c = 0, res = 0;
    while ((c = getopt(argc, argv, "e:ivclnhs")) != -1) {
        switch (c) {
            case 'e' : { flg->e = 1; sprintf(pattern, "%s", optarg); break; }
            case 'i' : { flg->i = 1; break; }
            case 'v' : { flg->v = 1; break; }
            case 'c' : { flg->c = 1; break; }
            case 'l' : { flg->l = 1; break; }
            case 'n' : { flg->n = 1; break; }
            case 'h' : { flg->h = 1; break; }
            case 's' : { flg->s = 1; break; }
            default : {
                res = 1;
                if (!flg->s) printf("./21_grep: invalid option -- %c\n", c);
                break;
            }
        }
    }
    return res;
}

void grepping(int argc, char**argv, flg_t *flg, char *pattern) {
    char patternL[99999] = {0};
    int file_flag = 0;

    if (!flg->e) {
        sprintf(patternL, "%s", argv[optind++]);
    } else {
        sprintf(patternL, "%s", pattern);
    }

    if (argc - optind > 1) file_flag = 1;  // если файлов больше, чем 1

    for (int i = optind; i < argc; ++i) {  // обработка каждого файла
        preparing_file(flg, argv[i], file_flag, patternL);
    }
}

void preparing_file(flg_t *flg, char *file, int file_flag, char *pattern) {
    int cflags = (flg->i) ? REG_ICASE | REG_EXTENDED : REG_EXTENDED;
    regex_t reg;
    FILE *fp = fopen(file, "r");

    if (fp != NULL) {
        regcomp(&reg, pattern, cflags);
        output(flg, fp, reg, file, file_flag);
        regfree(&reg);
        fclose(fp);
    } else if (!flg->s) {
        printf("./s21_grep: %s: No such file or directory\n", file);
    }
}

void output(flg_t *flg, FILE *fp, regex_t reg, char *file, int file_flag) {
    char text[99999] = {0};
    regmatch_t pmatch[1];
    int line_matchs = 0, nline = 1;
    int status, k = 0;

    while (fgets(text, 99999 - 1, fp) != NULL) {
        status = regexec(&reg, text, 1, pmatch, 0);
        int match = 0;

        if (file_flag && status == 0
         && !flg->l && !flg->c && !flg->h) {  // если кол f>1
            printf("%s:", file);  // выводим название кажого файла
        }

        if ((status == 0 && !flg->v)
         || (status == REG_NOMATCH && flg->v)) match = 1;

        if (match && !flg->l && !flg->c && flg->n) printf("%d:", nline);
        if (match && !flg->l && !flg->c) {
            printf("%s", text);
            k = 1;
        }
        if ( k == 1 && match == 1
         && strchr(text, '\n') == NULL) printf("%c", '\n');

        nline++;
        line_matchs += match;
    }

    if (flg->l && line_matchs > 0 && !flg->h) printf("%s\n", file);
    if (flg->c && !flg->l && file_flag) {
        printf("%s:", file);
        printf("%d\n", line_matchs);
    } else if (flg->c && !flg->l) {
        printf("%d\n", line_matchs);
    }
}
