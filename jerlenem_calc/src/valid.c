#include "./S21_Smart_calc_v1.h"

void first_wave(char *str, int *err) {  //  Первая волна проверки
  int len = strlen(str);
  int index = 0;
  int op_staples = 0, cl_staples = 0;
  int def_symbol = 0;
  char undef_sym[33] = "0123456789*+-/()^cosintaqrlgmdx.";
  char supp[7] = "+-*/^.";
  int old_s, new_s, flag;

  found_symbol(supp, str[index], &old_s);

  while (index < len && *err == CORRECT) {
    def_symbol = 0, new_s = 0;

    if (index == 0 && str[index] != '-' && str[index] != '+') {
      found_symbol(supp, str[index], &flag);
      if (flag == 1) *err = INCORRECT;
    }

    found_symbol(undef_sym, str[index], &def_symbol);
    // index++;
    found_symbol(supp, str[index + 1], &new_s);
    // index -= 1;

    if (def_symbol != 1) {
      *err = INCORRECT; /*printf("1\n"); */
    }                   // (1)

    else if (new_s * old_s == 1) {
      *err = INCORRECT; /*printf("2\n"); */
    }                   // (2)
    else
      old_s = new_s;

    if (*err ==
        CORRECT) {  // (3) Проверка, считаем количество открыв./закрыв. скобок
      if (str[index] == '(') op_staples++;
      if (str[index] == ')') cl_staples++;
    }

    index++;
  }

  if (*err == CORRECT) {
    *err = (op_staples == cl_staples) ? CORRECT : INCORRECT; /*printf("3\n"); */
  }                                                          // (3)
}

void staples_smart(char *str, int *err) {
  int len = strlen(str);
  int flag, index = 0;
  char symbol;
  char before_staple[10] = "+-*/^nstg";
  char after_staple[7] = "+-*/^)";
  char indoor_staple[12] = "0123456789x";

  while (index < len && *err == CORRECT) {
    symbol = str[index];

    if (symbol == '(') {
      if (str[index + 1] == ')')
        *err = INCORRECT;
      else if (str[index + 2] == ')') {
        found_symbol(indoor_staple, str[index + 1], &flag);

        if (flag == 0) *err = INCORRECT;
      }

      if (index != 0 && str[index - 1] != 'd') {
        found_symbol(before_staple, str[index - 1], &flag);

        if (flag == 0) *err = INCORRECT;
      }
    } else if (symbol == ')' && *err == CORRECT && str[index + 1] != 'm') {
      if (index != 0) {
        found_symbol(after_staple, str[index + 1], &flag);

        if (flag == 0) *err = INCORRECT;
      }
    }
    if (*err == CORRECT) index++;
  }
}

void found_symbol(char *array, char to_found, int *flag) {
  char *ptr = strchr(array, to_found);
  if (ptr != NULL) {  // Нашел символ
    *flag = 1;
    ptr = NULL;
  } else {  // Не нашел символ
    *flag = 0;
  }
}

void expressions(char *str, int *err) {
  int len = strlen(str);
  char supp[7] = "+-*/^(";
  char after[13] = "(0123456789x";
  char before[13] = ")0123456789x";
  char expres_s[13] = "cosintlgqram";
  int flag;
  int index = 0;
  char symbol, symbol_2;

  while (index < len && *err == CORRECT) {
    // printf("%c\n", str[index]);

    symbol = str[index];
    symbol_2 = str[index + 1];

    found_symbol(expres_s, symbol, &flag);

    if (flag == 1) {
      if (index == 0 && str[index] == 'm') *err = INCORRECT;
      if (index != 0) {
        if (str[index] == 'm') {
          found_symbol(before, str[index - 1], &flag);
          if (flag == 1) {
            if (index + 1 < len) found_symbol(after, str[index + 3], &flag);
            if (flag == 0)
              *err = INCORRECT;
            else
              ind_plus(symbol, symbol_2, &index);
          } else
            *err = INCORRECT;
        } else {
          found_symbol(supp, str[index - 1], &flag);

          if (flag == 0)
            *err = INCORRECT;
          else
            ind_plus(symbol, symbol_2, &index);
        }

      } else {
        ind_plus(symbol, symbol_2, &index);
      }
    } else
      index++;
  }
}

void ind_plus(char symbol, char symbol_2, int *index) {
  if (symbol == 'c' || symbol == 't' || (symbol == 'l' && symbol_2 == 'o') ||
      (symbol == 's' && symbol_2 == 'i'))
    *index += 4;
  else if (symbol == 'a' || (symbol == 's' && symbol_2 == 'q'))
    *index += 5;
  else if (symbol == 'l' && symbol_2 == 'o')
    *index += 3;
  else if (symbol == 'l' && symbol_2 == 'n')
    *index += 2;
  else if (symbol == 'm')
    *index += 3;
  else
    *index += 1;
}

void operators(char *str, int *err) {
  char after_operators[18] = "(0123456789csatlx";
  char operators[6] = "+-*/^";
  char before_operators[13] = ")0123456789x";
  int len = strlen(str);
  int index = 0;
  int flag;

  while (index < len && *err == CORRECT) {
    found_symbol(operators, str[index], &flag);

    if (flag == 1) {
      if (index + 1 < len) {
        found_symbol(after_operators, str[index + 1], &flag);

        if (flag == 0) {
          *err = INCORRECT;
          printf("AFTER\n");
        }
      }

      if (index != 0 && *err == CORRECT) {
        found_symbol(before_operators, str[index - 1], &flag);

        if (flag == 0) {
          *err = INCORRECT;
          printf("%c, BEFORE\n", str[index]);
          if ((str[index] == '-' || str[index] == '+') &&
              str[index - 1] == '(') {
            *err = CORRECT;
            printf("BEFORE, str = %c, before = %c\n", str[index],
                   str[index - 1]);
            index++;
          }
        } else
          index++;
      } else if (index == 0)
        index++;

    } else
      index++;
  }
}
