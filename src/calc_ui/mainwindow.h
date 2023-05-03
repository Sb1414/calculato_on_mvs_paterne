#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLineEdit>
#include <QMainWindow>
#include <QMessageBox>
#include <QTimer>
#include <QValidator>
#include <QVector>
#include <QtMath>

#include "../controller/controller.h"
#include "credit.h"
#include "deposit.h"
#include "qcustomplot.h"
#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = 0);
  ~MainWindow();
  Ui::MainWindow *ui;

 private:
  double xBegin, xEnd, h, X, xy_1, xy_2, result_1, result_2;
  int N;
  bool flag_ = true, flag_bracket = false;
  QString pi = "3.141592653589793", exp = "2.718281828459045";
  int count_bracket = 0;

 private slots:
  void digits_numbers();
  std::pair<size_t, int> helperDotClick();
  bool helper();
  void trigon_numbers();
  void ariph_numbers();
  void on_pushButton_dot_clicked();
  void on_pushButton_pi_clicked();
  void on_pushButton_exp_clicked();
  void on_pushButton_div_clicked();
  void on_pushButton_mul_clicked();
  void on_pushButton_equals_clicked();
  void on_pushButton_backspace_clicked();
  void on_pushButton_plusminus_clicked();
  void on_credit_clicked();
  void on_deposit_clicked();
  void on_pushButton_graph_clicked();
  void on_pushButton_clear_clicked();
  void on_pushButton_x_clicked();
  void on_pushButton_round_bracket_L_clicked();
  void on_pushButton_round_bracket_R_clicked();
  bool checkLastSym();

  void on_pushButton_pow_clicked();

 private:
  void CheckNull();
};
#endif  // MAINWINDOW_H
