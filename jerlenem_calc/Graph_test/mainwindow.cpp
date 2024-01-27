#include "mainwindow.h"

#include <limits.h>
#include <math.h>

#include <QCheckBox>
#include <QDebug>
#include <QMessageBox>
#include <QPixmap>
#include <QString>
#include <cfloat>
#include <cmath>
#include <iostream>
#include <limits>
#include <string>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  credit_window = new Credit();
  connect(credit_window, &Credit::firstWindow, this, &MainWindow::show);

  deposit_window = new Deposit();
  connect(deposit_window, &Deposit::firstWindow, this, &MainWindow::show);

  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_mul, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_sub, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_add, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_openBracket, SIGNAL(clicked()), this,
          SLOT(digits_numbers()));
  connect(ui->pushButton_closeBracket, SIGNAL(clicked()), this,
          SLOT(digits_numbers()));
  connect(ui->pushButton_point, SIGNAL(clicked()), this,
          SLOT(digits_numbers()));
  connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_remove, SIGNAL(clicked()), this,
          SLOT(digits_numbers()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::digits_numbers() {
  QString new_label;
  QPushButton *button = (QPushButton *)sender();

  if (button == ui->pushButton_sin || button == ui->pushButton_cos ||
      button == ui->pushButton_tan || button == ui->pushButton_asin ||
      button == ui->pushButton_acos || button == ui->pushButton_atan ||
      button == ui->pushButton_ln || button == ui->pushButton_log) {
    new_label = (ui->show_result->text() + button->text()) + '(';

  } else if (button == ui->pushButton_openBracket) {
    new_label = (ui->show_result->text() + "(");

  } else if (button == ui->pushButton_closeBracket) {
    new_label = (ui->show_result->text() + ")");

  } else if (button == ui->pushButton_remove) {
    new_label = "";

  } else if (button == ui->pushButton_mod) {
    new_label = ui->show_result->text() + "mod";
  } else if (button == ui->pushButton_sqrt) {
    new_label = (ui->show_result->text() + "sqrt(");
  } else {
    new_label = (ui->show_result->text() + button->text());
  }

  ui->show_result->setText(new_label);
}

void MainWindow::on_pushButton_result_clicked() {
  int error = 0;
  setlocale(LC_NUMERIC, "C");
  std::string str_string;
  double result = 0;
  str_string = ui->show_result->text().toStdString();
  const char *str = str_string.c_str();
  result = expression_to_polish_notation((char *)str, 0, &error);
  if (error == 0)
    ui->show_result->setText(QString::number(result));
  else
    ui->show_result->setText("error");
}

void MainWindow::on_pushButton_clear_clicked() {
  //    std::string new_str = ui->show_result->text().toStdString();
  //    const char *str = new_str.c_str();
  //    if (str != NULL) {
  //    char str_delete_one[255] = "";
  //    for (size_t i = 0; i < strlen(str)-1; i++)
  //        str_delete_one[i]=str[i];
  //    ui->show_result->setText(str_delete_one);
  //    }
  std::string str = ui->show_result->text().toStdString();
  if (!str.empty()) {
    str.erase(str.size() - 1);
  }
  QString tmp;
  if (str.empty()) {
    tmp = QString::fromStdString(str);
  } else {
    tmp = QString::fromStdString(str);
  }
  ui->show_result->setText(tmp);
}

void MainWindow::on_pushButton_Graph_clicked() {
  QPen pen;
  pen.setColor(QColor(137, 38, 87));

  //    QString text = ui->show_result->text();
  std::string str_string;
  str_string = ui->show_result->text().toStdString();
  const char *str = str_string.c_str();

  ui->widget->clearGraphs();

  xBegin = ui->X1->text().toDouble();
  xEnd = ui->X2->text().toDouble();

  h = (fabs(xEnd) + fabs(xBegin)) / 100;
  xy1 = DBL_MAX, xy2 = DBL_MIN;
  ui->widget->xAxis->setRange(xBegin, xEnd);
  result_1 = ui->Y1->text().toDouble();
  result_2 = ui->Y2->text().toDouble();
  ui->widget->yAxis->setRange(result_1, result_2);
  int error = 0;
  for (X = xBegin; X <= xEnd; X += h) {
    result = expression_to_polish_notation((char *)str, (X), &error);
    y.push_back(result);
    x.push_back(X);
    ui->widget->addGraph()->setPen(pen);
    ui->widget->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->widget->graph(0)->setScatterStyle(
        QCPScatterStyle(QCPScatterStyle::ssStar, 4));
    ui->widget->setInteraction(QCP::iRangeZoom, true);
    ui->widget->setInteraction(QCP::iRangeDrag, true);
    ui->widget->setBackground(QColor(235, 234, 230));
    ui->widget->graph(0)->addData(x, y);
    ui->widget->replot();
  }

  x.clear();
  y.clear();
}

void MainWindow::on_pushButton_clicked() {
  credit_window->show();
  this->close();
}

void MainWindow::on_Deposit_clicked() {
  deposit_window->show();
  this->close();
}
