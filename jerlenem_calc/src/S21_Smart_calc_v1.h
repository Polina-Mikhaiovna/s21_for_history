#ifndef SRC_S21_Smart_calc_H
#define SRC_S21_Smart_calc_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef double Data_lf;
typedef int Data_d;
#define CORRECT 0
#define INCORRECT 1

#define CAPITALIZATION_ON 1
#define CAPITALIZATION_OFF 0

typedef enum { Annuity, Differentiated } credit_type_t;

typedef struct {
  double monthly_payment;
  double total_payout;
  double overpayment;
} credit;

/**
 *  @param s21_deposit_into_t - структура входных данных депозитного
 * калькулятора
 *  @param deposit_amount                        сумма вклада
 *  @param placement_period                      срок размещения
 *  @param rate_of_exchange                      процентная ставка
 *  @param tax_rate                              налоговая ставка
 *  @param repayment_period                      периодичность выплат
 *  @param capitalization                        капитализация процентов [1 -
 * YES, 0 - NO]
 *  @param partial_withdrawal_list               список пополнений
 *  @param list_of_interest_capitalisation       список частичных снятий
 */
typedef struct {
  Data_lf deposit_amount;
  Data_d placement_period;
  Data_lf rate_of_exchange;
  Data_lf tax_rate;
  Data_d repayment_period;
  Data_d capitalization;
  Data_lf partial_withdrawal_list[255];
  Data_lf list_of_interest_capitalisation[255];
} s21_deposit_into_t;

/**
 *  @param s21_deposit_out_t - структура для возвращения ответа депозитного
 * калькулятора
 *  @param all_percent       начисленные проценты
 *  @param sum_tax           сумма налога
 *  @param total_sum         сумма на вкладе к концу срока
 *  @param f_result - доп переменная для отслеживания успешности калькулирования
 */
typedef struct {
  Data_lf all_percent;
  Data_lf sum_tax;
  Data_lf total_sum;
  Data_d f_result;
  Data_lf amount_profit;
} s21_deposit_out_t;

/*     Main functions     */
s21_deposit_out_t *calculate_deposit(s21_deposit_into_t *deposit_input);
// Data_d                  general_deposit_syntax_check(s21_deposit_into_t
// *deposit_input);
void deposit_tax(s21_deposit_out_t **deposit_output);

/**
 * @param s21_credit_out_t - структура выходных данных кредитного калькулятора
 * @param monthly_payment       ежемесячный платеж
 * @param total_payout          общая выплата
 * @param overpayment           переплата по кредиту
 * @param f_result - доп переменная для отслеживания успешности калькулирования
 */
typedef struct {
  Data_lf monthly_payment;
  Data_lf total_payout;
  Data_lf overpayment;
  Data_d f_result;
} s21_credit_out_t;

/**
 * @param s21_credit_into_t - структура выходных данных кредитного калькулятора
 * @param total_credit_sum       общая сумма кредита
 * @param credit_period          срок кредита
 * @param rate_of_exchange       процентная ставка
 * @param type тип [1 - Differentiated, 0 - Annuity] [1 - Differentiated, 0 -
 * Annuity]
 */
typedef struct {
  Data_lf total_credit_sum;
  Data_d credit_period;
  Data_lf rate_of_exchange;
  credit_type_t type;
} s21_credit_into_t;

/*     value_type_t - нужен для того чтобы       */
/*     записывать тип символа или переменной     */
/*     в структуру s21_Stack_t                   */
typedef enum {
  Number,      /*     0-9     */
  Point,       /*     '.'     */
  X,           /*     'x'     */
  Add,         /*     '+'     */
  Sub,         /*     '-'     */
  Mul,         /*     '*'     */
  Div,         /*     '/'     */
  Mod,         /*     '%'     */
  Pow,         /*     '^'     */
  Cos,         /*    cos(x)   */
  Sin,         /*    sin(x)   */
  Tan,         /*    tan(x)   */
  Acos,        /*    acos(x)  */
  Asin,        /*    asin(x)  */
  Atan,        /*    atan(x)  */
  Sqrt,        /*    sqrt(x)  */
  Ln,          /*    ln(x)    */
  Log,         /*    log(x)   */
  OpenBracket, /*     '('     */
  CloseBracket /*     ')'     */
} value_type_t;

/*     priority_t - нужен для определения       */
/*     приотритета 1 лексемы                    */
typedef enum {
  SHORT,
  MIDDLE,
  UNARY,
  HIGH,
  BRACKET,
} priority_t;

/*  структура для проверки строки   */
typedef struct symbol {
  char c;
  int count;
} symbol;

typedef struct Node {
  double value;
  priority_t priority;
  value_type_t type_t;
  struct Node *next;
} s21_Stack_t;

#define OK 1
#define ERROR 0

/*===============================================================/
/                                                                /
/              БЛОК ФУНКЦИЙ РЕАЛИЗАЦИИ S21_STACK_T               /
/                                                                /
/===============================================================*/
int prepare_expression(char *str);
int supp_check(int *err, char *str, int *length);
void first_wave(char *str, int *err);
void found_symbol(char *array, char to_found, int *flag);
void staples_smart(char *str, int *err);
void expressions(char *str, int *err);
void ind_plus(char symbol, char symbol_2, int *index);
void operators(char *str, int *err);
void only_mod(char *str, int *err);
void push_data(s21_Stack_t **list, double value, priority_t priority,
               value_type_t type_t);
s21_Stack_t *pop_data(s21_Stack_t **list);
double pop_data_lf(s21_Stack_t **list);
int pop_data_type(s21_Stack_t **list);
s21_Stack_t *peak_data(s21_Stack_t **);
priority_t peak_priority(s21_Stack_t **list);
value_type_t peak_type(s21_Stack_t **list);
int is_empty(s21_Stack_t *list);
int this_is_digit(int token);
int get_priority(int token);
void clean_str(char *str);
void check_str(s21_Stack_t **line, char *str, int *d);
double expression_to_polish_notation(char *str, double x, int *error);
void printf_stack_data_lf(s21_Stack_t *list);
void calculate_expression(s21_Stack_t **list);
double s21_arithmetic(double a, double b, value_type_t operation);
double s21_trigonometry(double a, value_type_t operation);

#endif  // !SRC_S21_Smart_calc_H
