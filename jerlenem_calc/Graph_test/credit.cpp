#include "./../src/credit.h"

#include <stdio.h>

#include <iostream>

#include "ui_credit.h"
// using namespace std;

Data_d general_credit_syntax_check1(s21_credit_into_t *credit_input);
s21_credit_out_t *calculate_credit1(s21_credit_into_t *credit_input);

Credit::Credit(QWidget *parent) : QMainWindow(parent), ui(new Ui::Credit) {
  ui->setupUi(this);
}

Credit::~Credit() { delete ui; }

// void Credit::on_buttonBox_2_accepted()
//{
//     this->close();
//     emit firstWindow();
// }

void Credit::on_back_to_main_clicked() {
  this->close();
  emit firstWindow();
}

void Credit::on_pushButton_result_credit_clicked() {
  //    double Sum = 0, procently;
  //    int period;
  s21_credit_into_t *credit = new s21_credit_into_t;
  credit->total_credit_sum = 0;
  credit->credit_period = 0;
  credit->rate_of_exchange = 0;
  credit->total_credit_sum = ui->sum_credit->text().toDouble();
  credit->credit_period = ui->period->text().toInt();
  credit->rate_of_exchange = ui->procently->text().toDouble();
  std::string type_credit = ui->type_credit->currentText().toStdString();
  //      const char *str = type_credit.c_str();
  //     ui->test1->setText(QString::numder(credit->total_credit_sum));
  ui->monthly_payment->setText(QString::number(credit->rate_of_exchange));
  //     ui->monthly_payment->setText(QString::type_credit);
  credit->type = Annuity;
  if (ui->type_credit->currentIndex() == 0)
    credit->type = Annuity;
  else
    credit->type = Differentiated;
  s21_credit_out_t *credit_out = calculate_credit1(credit);
  double mon_pay = credit_out->monthly_payment;
  ui->monthly_payment->setText(QString::number(mon_pay));
  ui->overpayment->setText(QString::number(credit_out->overpayment));
  ui->total_payout->setText(QString::number(credit_out->total_payout));
  //          std::cout<<mon_pay.toStd + "/n";
  delete (credit);
  delete (credit_out);
}

Data_d general_credit_syntax_check1(s21_credit_into_t *credit_input) {
  int f_result = ERROR;
  if (credit_input->credit_period > 0 && credit_input->rate_of_exchange > 0 &&
      credit_input->total_credit_sum > 0 &&
      (credit_input->type == Annuity || credit_input->type == Differentiated))
    f_result = OK;
  //    char str1[255] = "", str2[255] = "", str3[255] = "";
  //    std::sprintf(str1, "%lf", credit_input->total_credit_sum);
  //    std::sprintf(str2, "%lf", credit_input->rate_of_exchange);
  //    std::sprintf(str3, "%d", credit_input->credit_period);
  //    for (size_t i = 0; i < strlen(str1); i++) {
  //        if (!this_is_digit(str1[i])) {
  //            f_result = ERROR;
  //            break;
  //        }
  //    }
  //    if (f_result == OK) {
  //        for (size_t i = 0; i < strlen(str2); i++) {
  //            if (!this_is_digit(str2[i])) {
  //                f_result = ERROR;
  //                break;
  //            }
  //        }
  //    }
  //    if (f_result == OK) {
  //        for (size_t i = 0; i < strlen(str3); i++) {
  //            if (!this_is_digit(str3[i])) {
  //                f_result = ERROR;
  //                break;
  //            }
  //        }
  //    }
  return f_result;
}

s21_credit_out_t *calculate_credit1(s21_credit_into_t *credit_input) {
  s21_credit_out_t *credit_output = new s21_credit_out_t;
  credit_output->f_result = general_credit_syntax_check1(credit_input);
  if (credit_output->f_result) {
    printf("Test completed successfully!\n");
    if (credit_input->type == Annuity) {
      Data_lf procently = credit_input->rate_of_exchange / (100 * 12);
      credit_output->monthly_payment = std::round(
          credit_input->total_credit_sum *
          (procently / (1 - pow(1 + procently, -credit_input->credit_period))));
      credit_output->total_payout =
          credit_output->monthly_payment * credit_input->credit_period;
      credit_output->overpayment =
          credit_output->total_payout - credit_input->total_credit_sum;
    } else if (credit_input->type == Differentiated) {
      credit_output->total_payout = 0.0;
      Data_lf monthly_payment =
          credit_input->total_credit_sum / credit_input->credit_period;
      for (int i = 0; i < credit_input->credit_period; i++) {
        credit_output->total_payout +=
            monthly_payment +
            (credit_input->total_credit_sum - monthly_payment * i) *
                (credit_input->rate_of_exchange / 100) / 12;
      }
      credit_output->monthly_payment =
          std::round(credit_output->total_payout / credit_input->credit_period);
      /// tonitaga-jerlenem! не забудьте реализовать постепенное снижение цены
      /// начальный процент 5% от total_credit_sum к концу срока 4.2013%
      credit_output->overpayment =
          credit_output->total_payout - credit_input->total_credit_sum;
    }
  } else {
    printf("Syntax error!\n");
    credit_output->f_result = ERROR;
  }
  return credit_output;
}
