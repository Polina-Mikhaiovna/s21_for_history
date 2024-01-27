#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <QDialog>
extern "C" {
#include "S21_Smart_calc_v1.h"
}
namespace Ui {
class Deposit;
}

class Deposit : public QDialog {
  Q_OBJECT
 public:
  explicit Deposit(QWidget *parent = nullptr);
  ~Deposit();
 signals:
  void firstWindow();

 private slots:
  //    void on_buttonBox_accepted();
  void on_pushButton_calculate_deposit_clicked();
  void on_back_to_main_clicked();

  //    void on_pushButton_add_money_clicked();

  //    void on_pushButton_sub_money_clicked();

  void on_Button_pop_clicked();

  void on_Button_with_clicked();

 private:
  Ui::Deposit *ui;
};

#endif  // DEPOSIT_H
