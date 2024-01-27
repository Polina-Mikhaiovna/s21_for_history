#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QVector>
#include <QtMath>
#include <limits>

#include "./../src/credit.h"
#include "./../src/deposit.h"
#include "qcustomplot.h"

extern "C" {
#include "./../src/S21_Smart_calc_v1.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  Credit *credit_window;
  Deposit *deposit_window;

  double xBegin, xEnd, h, X, xy1, xy2, result_1, result_2, result;
  int N;

  QVector<double> x, y;
  QTimer *timer;
  int time;

 private slots:
  void digits_numbers();
  void on_pushButton_clear_clicked();
  void on_pushButton_result_clicked();
  void on_pushButton_Graph_clicked();
  void on_pushButton_clicked();
  void on_Deposit_clicked();
};
#endif  // MAINWINDOW_H
