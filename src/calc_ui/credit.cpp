#include "credit.h"

#include <QMessageBox>

#include "ui_credit.h"

credit::credit(QWidget *parent) : QDialog(parent), ui(new Ui::credit) {
  ui->setupUi(this);
  ui->monthly_payment->setReadOnly(true);
  ui->total_payment->setReadOnly(true);
  ui->overpayment->setReadOnly(true);
}

credit::~credit() { delete ui; }

bool isNumber(std::string str) {
  int pointCount = 0;
  for (int i = 0; i < static_cast<int>(str.length()); i++) {
    if (!isdigit(str[i])) {
      if (str[i] != '.') {
        return false;
      } else {
        pointCount++;
        if (pointCount > 1 || i == 0 ||
            i == static_cast<int>(str.length() - 1)) {
          return false;
        }
      }
    }
  }
  return true;
}

void credit::on_pushButton_credit_clicked() {
  double total_credit_amount = ui->total_credit_amount->value();
  double interes_rate = ui->interes_rate->value();
  double term = ui->term->value();

  s21::Controller ctrl;
  if (ui->radioButton_Annuity->isChecked()) {
    std::vector<double> rez =
        ctrl.CrCalculations(total_credit_amount, term, interes_rate, true);
    ui->monthly_payment->setText(QString::number(rez[2], 'f', 2));
    ui->total_payment->setText(QString::number(rez[0], 'f', 2));
    ui->overpayment->setText(QString::number(rez[1], 'f', 2));
  } else if (ui->radioButton_Differentiated->isChecked()) {
    std::vector<double> rez =
        ctrl.CrCalculations(total_credit_amount, term, interes_rate, false);
    ui->monthly_payment->setText(QString::number(rez[0], 'f', 2) + "..." +
                                 QString::number(rez[1], 'f', 2));
    ui->total_payment->setText(QString::number(rez[2], 'f', 2));
    ui->overpayment->setText(QString::number(rez[3], 'f', 2));

  } else {
    QMessageBox::warning(this, "Warning", "Выберите тип платежа!");
  }
}
