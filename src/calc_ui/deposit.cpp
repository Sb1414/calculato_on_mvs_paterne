#include "deposit.h"

#include <QMessageBox>

#include "ui_deposit.h"

deposit::deposit(QWidget *parent) : QDialog(parent), ui(new Ui::deposit) {
  ui->setupUi(this);
  ui->accured_interest->setReadOnly(true);
  ui->tax_ammount->setReadOnly(true);
  ui->deposit_end->setReadOnly(true);
}

deposit::~deposit() { delete ui; }

bool isNum(std::string const &str) {
  auto it = str.begin();
  while (it != str.end() && std::isdigit(*it)) {
    it++;
  }
  return !str.empty() && it == str.end();
}

void deposit::on_pushButton_credit_clicked() {
  double deposit_amount = ui->deposit_amount->value();
  double deposit_term = ui->deposit_term->value();
  double interest_rate = ui->interes_rate->value();
  double tax_rate = ui->tax_rate->value();
  double partial_withdrawals_sum = ui->withdraw_sum->value();
  double partial_withdrawals_month = ui->partial_withdraw_month->value();
  double replenishments_sum = ui->replenishments_sum->value();
  double replenishments_month = ui->partial_replanishment_month->value();
  bool check = false;
  if (ui->checkBox->isChecked()) {
    check = true;
  }
  s21::Controller Contr;
  std::vector<double> rez =
      Contr.DepCalculations(check, deposit_term, deposit_amount, interest_rate,
                            tax_rate, replenishments_month, replenishments_sum,
                            partial_withdrawals_month, partial_withdrawals_sum);
  ui->accured_interest->setText(QString::number(rez[0], 'f', 2));
  ui->deposit_end->setText(QString::number(rez[1], 'f', 2));
  ui->tax_ammount->setText(QString::number(rez[2], 'f', 2));
}
