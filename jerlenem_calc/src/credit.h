#ifndef CREDIT_H
#define CREDIT_H

#include <QMainWindow>
#include <QTimer>
#include <QVector>
#include <QtMath>
#include <limits>

#include "credit.h"
#include "deposit.h"
#include "qcustomplot.h"

extern "C" {
#include "S21_Smart_calc_v1.h"
}

namespace Ui {
class Credit;
}

class Credit : public QMainWindow {
  Q_OBJECT

 signals:
  void firstWindow();

 public:
  explicit Credit(QWidget *parent = nullptr);
  ~Credit();

 private slots:

  //    void on_buttonBox_2_accepted();

  void on_back_to_main_clicked();

  void on_pushButton_result_credit_clicked();

 private:
  Ui::Credit *ui;
};

#endif  // CREDIT_H
