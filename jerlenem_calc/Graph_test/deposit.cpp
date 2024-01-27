#include "./../src/deposit.h"

#include "ui_deposit.h"

Deposit::Deposit(QWidget *parent) : QDialog(parent), ui(new Ui::Deposit) {
  ui->setupUi(this);
  ui->comboBox_rate_of_payment->addItem("Раз в месяц");
  ui->comboBox_rate_of_payment->addItem("Раз в три месяца");
  ui->comboBox_rate_of_payment->addItem("Раз в полгода");
  ui->comboBox_rate_of_payment->addItem("Раз в год");
  ui->pop_time->addItem("Разовое");
  ui->pop_time->addItem("Раз в месяц");
  ui->pop_time->addItem("Раз в три месяца");
  ui->pop_time->addItem("Раз в год");
  ui->withdrawal_time->addItem("Разовое");
  ui->withdrawal_time->addItem("Раз в месяц");
  ui->withdrawal_time->addItem("Раз в три месяца");
  ui->withdrawal_time->addItem("Раз в год");
  ui->comboBox_time->addItem("месяцев");
  ui->comboBox_time->addItem("лет");
  ui->pop_time->setVisible(0);
  ui->pop_num->setVisible(0);
  ui->withdrawal_time->setVisible(0);
  ui->withdrawal->setVisible(0);
  ui->checkBox->animateClick();
}

Deposit::~Deposit() { delete ui; }

// void Deposit::on_buttonBox_accepted()
//{
//     this->close();
//     emit firstWindow();
// }

void Deposit::on_back_to_main_clicked() {
  this->close();
  emit firstWindow();
}

// void Deposit::on_pushButton_add_money_clicked()
//{
//     ui->pop_time->setVisible(1);
//     ui->pop_num->setVisible(1);
// }

// void Deposit::on_pushButton_sub_money_clicked()
//{
//     ui->withdrawal_time->setVisible(1);
//     ui->withdrawal->setVisible(1);
// }

void Deposit::on_pushButton_calculate_deposit_clicked() {
  //        setlocale(LC_NUMERIC, "C");
  s21_deposit_into_t *deposit_input =
      (s21_deposit_into_t *)calloc(1, sizeof(s21_deposit_into_t));
  s21_deposit_out_t *deposit_output = nullptr;

  deposit_input->deposit_amount = ui->lineEdit_amount_money->text().toDouble();
  deposit_input->rate_of_exchange =
      ui->lineEdit_rate_of_exchange->text().toDouble();
  //        ui->pop_time->currentIndex() == 0
  int period = 0;
  switch (ui->pop_time->currentIndex()) {
    case 0:
      deposit_input->partial_withdrawal_list[0] =
          ui->pop_num->text().toDouble();
      for (int i = 1; i < ui->lineEdit_time_replament->text().toInt(); i++)
        deposit_input->partial_withdrawal_list[i] = 0;
      break;
    case 1:
      for (int i = 0; i < ui->lineEdit_time_replament->text().toInt(); i++) {
        deposit_input->partial_withdrawal_list[i] =
            ui->pop_num->text().toDouble();
      }
      break;
    case 2:
      //            period = 3;
      deposit_input->partial_withdrawal_list[ui->lineEdit_time_replament->text()
                                                 .toInt()] =
          ui->pop_num->text().toDouble();
      for (int i = 0; i < ui->lineEdit_time_replament->text().toInt(); i++) {
        if (period == 3) {
          deposit_input->partial_withdrawal_list[i] =
              ui->pop_num->text().toDouble();
          period = 0;
        } else {
          deposit_input->partial_withdrawal_list[i] = 0;
        }
        period += 1;
      }
      break;
    case 3:
      //            period = 12;
      for (int i = 0; i < ui->lineEdit_time_replament->text().toInt(); i++) {
        if (period == 12) {
          deposit_input->partial_withdrawal_list[i] =
              ui->pop_num->text().toDouble();
          period = 0;
        } else {
          deposit_input->partial_withdrawal_list[i] = 0;
        }
        period += 1;
      }
      break;
    default:
      break;
  }
  switch (ui->withdrawal_time->currentIndex()) {
    case 0:
      deposit_input->list_of_interest_capitalisation[0] =
          ui->withdrawal->text().toDouble();
      for (int i = 1; i < ui->lineEdit_time_replament->text().toInt(); i++)
        deposit_input->list_of_interest_capitalisation[i] = 0;
      break;
    case 1:
      for (int i = 0; i < ui->lineEdit_time_replament->text().toInt(); i++) {
        deposit_input->list_of_interest_capitalisation[i] =
            ui->withdrawal->text().toDouble();
      }
      break;
    case 2:
      //            period = 3;
      deposit_input->list_of_interest_capitalisation
          [ui->lineEdit_time_replament->text().toInt()] =
          ui->withdrawal->text().toDouble();
      for (int i = 0; i < ui->lineEdit_time_replament->text().toInt(); i++) {
        if (period == 3) {
          deposit_input->list_of_interest_capitalisation[i] =
              ui->withdrawal->text().toDouble();
          period = 0;
        } else {
          deposit_input->list_of_interest_capitalisation[i] = 0;
        }
        period += 1;
      }
      break;
    case 3:
      //            period = 12;
      for (int i = 0; i < ui->lineEdit_time_replament->text().toInt(); i++) {
        if (period == 12) {
          deposit_input->list_of_interest_capitalisation[i] =
              ui->withdrawal->text().toDouble();
          period = 0;
        } else {
          deposit_input->list_of_interest_capitalisation[i] = 0;
        }
        period += 1;
      }
      break;
    default:
      break;
  }
  //        deposit_input->partial_withdrawal_list[0] =
  //        ui->withdrawal->text().toDouble();
  if (ui->comboBox_time->currentIndex() == 0)
    deposit_input->placement_period =
        ui->lineEdit_time_replament->text().toInt();
  else if (ui->comboBox_time->currentIndex() == 1)
    deposit_input->placement_period =
        ui->lineEdit_time_replament->text().toInt() * 12;

  int currect_index_rate_of_payment =
      ui->comboBox_rate_of_payment->currentIndex();
  if (currect_index_rate_of_payment == 0) {
    deposit_input->repayment_period = 1;
  } else if (currect_index_rate_of_payment == 1) {
    deposit_input->repayment_period = 3;
  } else if (currect_index_rate_of_payment == 2) {
    deposit_input->repayment_period = 6;
  } else if (currect_index_rate_of_payment == 3) {
    deposit_input->repayment_period = 12;
  }

  if (ui->checkBox->checkState()) {
    deposit_input->capitalization = 1;
    //        std::cout << "CAPITALIZATION_ON" << std::endl;
  } else {
    deposit_input->capitalization = 0;
    //        std::cout << "CAPITALIZATION_OFF" << std::endl;
  }

  deposit_output = calculate_deposit(deposit_input);
  this->setFixedSize(600, 600);

  QString total_money = QString::number(deposit_output->total_sum);
  QString total_percent = QString::number(deposit_output->all_percent);
  QString total_tax = QString::number(deposit_output->sum_tax);
  QString total_amount_profit = QString::number(deposit_output->amount_profit);

  ui->label_total_money->setText(total_money + " руб.");
  ui->label_total_percent->setText(total_percent + " %");
  ui->label_total_tax->setText(total_tax + " руб.");
  ui->label_amount_profit->setText(total_amount_profit + " руб.");

  free(deposit_input);
  free(deposit_output);
}

void Deposit::on_Button_pop_clicked() {
  ui->pop_time->setVisible(1);
  ui->pop_num->setVisible(1);
}

void Deposit::on_Button_with_clicked() {
  ui->withdrawal_time->setVisible(1);
  ui->withdrawal->setVisible(1);
}
