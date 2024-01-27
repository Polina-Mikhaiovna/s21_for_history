#include "./S21_Smart_calc_v1.h"

s21_deposit_out_t* calculate_deposit(s21_deposit_into_t* deposit_input) {
  s21_deposit_out_t* deposit_output =
      (s21_deposit_out_t*)calloc(1, sizeof(s21_deposit_out_t));
  Data_lf new_deposit_amount = deposit_input->deposit_amount;
  Data_d times_of_payment =
      deposit_input->placement_period / deposit_input->repayment_period;
  Data_lf placement_period_in_years = deposit_input->placement_period / 12.0;
  Data_lf new_rate_of_exchange = deposit_input->rate_of_exchange *
                                 placement_period_in_years / times_of_payment;

  Data_lf exchange = 1 + new_rate_of_exchange / 100;
  Data_d movie = deposit_input->placement_period / times_of_payment;
  Data_lf total_partial_withdrawal = 0.0;
  Data_lf total_interest_capitalisation = 0.0;
  for (Data_d i = 0; i < deposit_input->placement_period; i++) {
    if (deposit_input->partial_withdrawal_list[i] != 0.0) {
      new_deposit_amount += deposit_input->partial_withdrawal_list[i];
      total_partial_withdrawal += deposit_input->partial_withdrawal_list[i];
    }
    if (deposit_input->list_of_interest_capitalisation[i] != 0.0) {
      if (deposit_input->list_of_interest_capitalisation[i] >
          new_deposit_amount) {
        deposit_output->f_result = ERROR;
      } else {
        new_deposit_amount -= deposit_input->list_of_interest_capitalisation[i];
        total_interest_capitalisation +=
            deposit_input->list_of_interest_capitalisation[i];
      }
    }
    if (i % movie == 0) {
      new_deposit_amount = new_deposit_amount * exchange;
    }
  }

  if (deposit_input->capitalization == CAPITALIZATION_ON) {
    deposit_output->all_percent =
        ((new_deposit_amount - total_partial_withdrawal +
          total_interest_capitalisation) /
             deposit_input->deposit_amount -
         1) *
        100 / placement_period_in_years;
    deposit_output->total_sum = new_deposit_amount;
    deposit_output->amount_profit =
        new_deposit_amount - deposit_input->deposit_amount;
    deposit_tax(&deposit_output);
  } else {
    deposit_output->all_percent = deposit_input->rate_of_exchange;
    deposit_output->total_sum = deposit_input->deposit_amount;
    deposit_output->amount_profit =
        new_deposit_amount - deposit_input->deposit_amount;
    deposit_tax(&deposit_output);
  }

  return deposit_output;
}

/**
 *  https://clck.ru/sc6LZ
 *  @param limits - Проверка на превышение лимита на необлагаемый процентный
 * доход. Чтобы рассчитать сумму, которая не облагается налогом, нужно умножить
 * текущую ключевую ставку, установленную Центробанком РФ, на 1 миллион рублей
 *  @param result_tax - Рассчитать налог на вклад можно при помощи простой
 * формулы: (факт. доход по вкладам — освобожденный от налога процентный доход)
 * * 13% = сумма НДФЛ к уплате.
 */
void deposit_tax(s21_deposit_out_t** deposit_output) {
  double result_tax = 0;
  double profit = (*deposit_output)->amount_profit;

  double limits = 1000000 * 0.08;
  if (profit > limits) {
    result_tax = (profit - limits) * 0.13;
    (*deposit_output)->sum_tax = result_tax;
  } else
    (*deposit_output)->sum_tax = 0.0;
}

// Data_d general_deposit_syntax_check(s21_deposit_into_t *deposit_input) {
//     return OK;
// }

void push_data(s21_Stack_t** list, double value, priority_t priority,
               value_type_t type_t) {
  s21_Stack_t* stack = calloc(1, sizeof(s21_Stack_t));
  stack->value = value;
  stack->priority = priority;
  stack->type_t = type_t;
  stack->next = *list;
  *list = stack;
}

s21_Stack_t* pop_data(s21_Stack_t** list) {
  s21_Stack_t* copy_list = NULL;
  s21_Stack_t* tmp_stack = calloc(1, sizeof(s21_Stack_t));
  copy_list = *list;
  tmp_stack->value = copy_list->value;
  tmp_stack->type_t = copy_list->type_t;
  tmp_stack->priority = copy_list->priority;
  *list = (*list)->next;
  free(copy_list);
  return tmp_stack;
}

int pop_data_type(s21_Stack_t** list) {
  int type = 0;
  s21_Stack_t* copy_list = NULL;
  copy_list = *list;
  type = copy_list->type_t;
  *list = (*list)->next;
  free(copy_list);
  return type;
}

double pop_data_lf(s21_Stack_t** list) {
  double data = 0;
  s21_Stack_t* copy_list = NULL;
  copy_list = *list;
  data = copy_list->value;
  *list = (*list)->next;
  free(copy_list);
  return data;
}

priority_t peak_priority(s21_Stack_t** list) {
  int priority = -1;
  if (!is_empty(*list)) {
    s21_Stack_t* p = *list;
    priority = p->priority;
  }
  return priority;
}

value_type_t peak_type(s21_Stack_t** list) {
  int type = -1;
  if (!is_empty(*list)) {
    s21_Stack_t* p = *list;
    type = p->type_t;
  }
  return type;
}

// s21_Stack_t* peak_data(s21_Stack_t** list) {
//     s21_Stack_t* tmp_stack = calloc(1, sizeof(s21_Stack_t));
//     s21_Stack_t* copy_list = *list;
//     tmp_stack->value = copy_list->value;
//     tmp_stack->type_t = copy_list->type_t;
//     tmp_stack->priority = copy_list->priority;
//     free(copy_list);
//     return tmp_stack;
// }

int prepare_expression(char* str) {
  size_t k = 0;
  char new_str[255] = "";
  for (size_t i = 0; i < strlen(str); i++) {
    char token = str[i];
    if (token == '-') {
      if (i == 0) {
        new_str[k] = '0';
        k++;
      } else if (str[i - 1] == '(') {
        new_str[k] = '0';
        k++;
      }
    }
    new_str[k++] = token;
  }
  strcpy(str, new_str);
  int f_result = 0;
  return f_result;
}

int is_empty(s21_Stack_t* list) { return list == NULL; }
/* поиск числа */
int this_is_digit(int token) {
  return (token >= '0' && token <= '9') ? OK : ERROR;
}

/*  Идентификация символа  */
int get_priority(int token) {
  int f_result = -1;
  if (token == '*')
    f_result = Mul;
  else if (token == '/')
    f_result = Div;
  else if (token == 'x')
    f_result = X;
  else if (token == 'm')
    f_result = Mod;
  else if (token == '+')
    f_result = Add;
  else if (token == '-')
    f_result = Sub;
  else if (token == '(')
    f_result = OpenBracket;
  else if (token == ')')
    f_result = CloseBracket;
  else if (this_is_digit(token))
    f_result = Number;
  else if (token == '.')
    f_result = Point;
  else if (token == 's')
    f_result = Sin;
  else if (token == 'c')
    f_result = Cos;
  else if (token == 't')
    f_result = Tan;
  else if (token == 'a')
    f_result = Acos;
  else if (token == 'l')
    f_result = Ln;
  else if (token == '^')
    f_result = Pow;
  return f_result;
}

/*  очистка строки  */
void clean_str(char* str) {
  for (int i = 0; str[i] != '\0'; i++) str[i] = '\0';
}

void check_str(s21_Stack_t** line, char* str, int* d) {
  if (str[0] != '\0') {
    push_data(line, atof(str), 5, Number);
    *d = 0;
    clean_str(str);
  }
}

/*                  Обратная польская нотация
        list - список хранит обратную п.н.
        Support - список хранит всп. функции и знаки
        Ready - хранит последний элемент списка, нужен для сравнения */

double expression_to_polish_notation(char* str, double x, int* error) {
  double result = 0;
  s21_Stack_t* list = NULL;
  s21_Stack_t* Support = NULL;
  s21_Stack_t* Ready = NULL;
  int index_cur_str = 0, priority = -1;
  char currect_string[255] = {"\n"};
  int len = strlen(str);
  *error = prepare_expression(str);
  first_wave(str, error);
  staples_smart(str, error);
  expressions(str, error);
  operators(str, error);
  if (*error == 0) {
    for (int i = 0; i < len; i++) {
      priority = get_priority(str[i]);
      switch (priority) {
        case Number:
          clean_str(currect_string);
          while (priority == 0 || priority == 1) {
            currect_string[index_cur_str++] = str[i++];
            priority = get_priority(str[i]);
          }
          --i;
          check_str(&list, currect_string, &index_cur_str);
          break;
        case Add:
          push_data(&Ready, 0, SHORT, Add);
          break;
        case Sub:
          push_data(&Ready, 0, SHORT, Sub);
          break;
        case X:
          push_data(&list, x, 5, Number);
          break;
        case Mul:
          push_data(&Ready, 0, MIDDLE, Mul);
          break;
        case Div:
          push_data(&Ready, 0, MIDDLE, Div);
          break;
        case Mod:
          push_data(&Ready, 0, MIDDLE, Mod), i += 2;
          break;
        case Pow:
          push_data(&Ready, 0, HIGH, Pow);
          break;
        case Cos:
          push_data(&Ready, 0, HIGH, Cos);
          i += 2;
          break;
        case Sin:
          if (strncmp(str + i, "sin", 3) == 0) {
            push_data(&Ready, 0, HIGH, Sin);
            i += 2;
          } else if (strncmp(str + i, "sqrt", 4) == 0) {
            push_data(&Ready, 0, HIGH, Sqrt);
            i += 3;
          }
          break;
        case Tan:
          push_data(&Ready, 0, HIGH, Tan);
          i += 2;
          break;
        case Acos:
          if (strncmp(str + i, "acos", 4) == 0) {
            push_data(&Ready, 0, HIGH, Acos);
          } else if (strncmp(str + i, "asin", 4) == 0) {
            push_data(&Ready, 0, HIGH, Asin);
          } else if (strncmp(str + i, "atan", 4) == 0) {
            push_data(&Ready, 0, HIGH, Atan);
            i += 3;
          }
          break;
        case Ln:
          if (strncmp(str + i, "ln", 2) == 0) {
            push_data(&Ready, 0, HIGH, Ln), i++;
            ;
          } else if (strncmp(str + i, "log", 3) == 0) {
            push_data(&Ready, 0, HIGH, Log), i += 2;
          }
          break;
        case OpenBracket:
          push_data(&Ready, 0, BRACKET, OpenBracket);
          break;
        case CloseBracket:
          push_data(&Ready, 0, BRACKET, CloseBracket);
          break;
        default:
          break;
      }

      /*               Заполнение списка по приоритетам
              если предыдущий элемент списка > или = по приоритетам
              текуйщего элемента списка, то он записывается в выходную строку
         (list), иначе текуйщий элемента списка записывается в стек (Support) */
      if (peak_type(&Ready) == OpenBracket) {
        s21_Stack_t* tmp = pop_data(&Ready);
        push_data(&Support, tmp->value, tmp->priority, tmp->type_t);
        free(tmp);
      } else if (is_empty(Support) && !is_empty(Ready)) {
        s21_Stack_t* tmp = pop_data(&Ready);
        push_data(&Support, tmp->value, tmp->priority, tmp->type_t);
        free(tmp);
      } else if (peak_type(&Ready) == CloseBracket) {
        s21_Stack_t* tmp = pop_data(&Ready);
        free(tmp);
        while (peak_type(&Support) != OpenBracket) {
          s21_Stack_t* tmp1 = pop_data(&Support);
          push_data(&list, tmp1->value, tmp1->priority, tmp1->type_t);
          free(tmp1);
          calculate_expression(&list);
        }
        if (peak_type(&Support) == OpenBracket) {
          s21_Stack_t* tmp = pop_data(&Support);
          free(tmp);
        }

        /*          если приоритет текущущего эл. > предыдущего то положить в
         * стек*/
      } else if (!is_empty(Support) && !is_empty(Ready)) {
        if (peak_priority(&Ready) > peak_priority(&Support)) {
          s21_Stack_t* tmp = pop_data(&Ready);
          push_data(&Support, tmp->value, tmp->priority, tmp->type_t);
          free(tmp);
        } else if (peak_priority(&Ready) <= peak_priority(&Support)) {
          /*          достаем значения из стека в выходную строку, пока:
                          1: приоритет текущущего эл. стека < или = предыдущего
                          2: стек не пустой
                          3: не равен скобке                                  */
          while ((peak_priority(&Ready) <= peak_priority(&Support)) &&
                 !is_empty(Support) && peak_priority(&Support) != BRACKET) {
            calculate_expression(&list);
            s21_Stack_t* tmp1 = pop_data(&Support);
            push_data(&list, tmp1->value, tmp1->priority, tmp1->type_t);
            free(tmp1);
            calculate_expression(&list);
          }

          /*          текущее значение положить в стек         */
          s21_Stack_t* tmp2 = pop_data(&Ready);
          push_data(&Support, tmp2->value, tmp2->priority, tmp2->type_t);
          free(tmp2);
        }
      }
    }
    /*  если в стеке еще остались значения то
        переладываем их выходнйю строку */
    if (!is_empty(Support)) {
      while (!is_empty(Support)) {
        s21_Stack_t* tmp = pop_data(&Support);
        push_data(&list, tmp->value, tmp->priority, tmp->type_t);
        free(tmp);
        if (peak_priority(&list) == BRACKET) {
          s21_Stack_t* tmp = pop_data(&list);
          free(tmp);
        }
        calculate_expression(&list);
      }
    }
    if (!is_empty(list)) {
      result = pop_data_lf(&list);
    }
  } else {
    str = "error";
  }
  return result;
}

/*  вычисление польской нотации */
void calculate_expression(s21_Stack_t** list) {
  value_type_t operation = 0;
  double a = 0, b = 0, result = 0;
  operation = peak_type(list);
  if (operation > 0) {
    if (operation < 9) {
      operation = pop_data_type(list);
      if (peak_type(list) == 0) a = pop_data_lf(list);
      if (peak_type(list) == 0) b = pop_data_lf(list);
      result = s21_arithmetic(b, a, operation);
    } else if (operation >= 9 && operation <= 17) {
      operation = pop_data_type(list);
      if (peak_type(list) == 0) a = pop_data_lf(list);
      result = s21_trigonometry(a, operation);
    }
    push_data(list, result, 0, Number);
  }
}

double s21_arithmetic(double a, double b, value_type_t operation) {
  double res = 0;
  switch (operation) {
    case Add:
      res = a + b;
      break;
    case Sub:
      res = a - b;
      break;
    case Div:
      res = a / b;
      break;
    case Mul:
      res = a * b;
      break;
    case Pow:
      res = pow(a, b);
      break;
    case Mod:
      res = fmod(a, b);
      break;
    default:
      break;
  }
  return res;
}

double s21_trigonometry(double a, value_type_t operation) {
  double res = 0;
  switch (operation) {
    case Sin:
      res = sin(a);
      break;
    case Cos:
      res = cos(a);
      break;
    case Tan:
      res = tan(a);
      break;
    case Asin:
      res = asin(a);
      break;
    case Acos:
      res = acos(a);
      break;
    case Atan:
      res = atan(a);
      break;
    case Sqrt:
      res = sqrt(a);
      break;
    case Ln:
      res = log(a);
      break;
    case Log:
      res = log10(a);
      break;
    default:
      break;
  }
  return res;
}
