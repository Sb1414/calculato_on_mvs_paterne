#include "deposit.h"
#include "ui_deposit.h"
#include <QMessageBox>

deposit::deposit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deposit)
{
    ui->setupUi(this);
    ui->accured_interest->setReadOnly(true);
    ui->tax_ammount->setReadOnly(true);
    ui->deposit_end->setReadOnly(true);
}

deposit::~deposit()
{
    delete ui;
}

bool isNum(std::string const &str)
{
    auto it = str.begin();
    while (it != str.end() && std::isdigit(*it)) {
        it++;
    }
    return !str.empty() && it == str.end();
}

void deposit::on_pushButton_credit_clicked()
{
    double deposit_amount = ui->deposit_amount->text().toDouble();
    double deposit_term = ui->deposit_term->text().toDouble();
    double interest_rate = ui->interes_rate->text().toDouble();
    double tax_rate = ui->tax_rate->text().toDouble();
    double partial_withdrawals_sum = ui->withdraw_sum->text().toDouble();
    double partial_withdrawals_month = ui->partial_withdraw_month->text().toDouble();
    double replenishments_sum = ui->replenishments_sum->text().toDouble();
    double replenishments_month = ui->partial_replanishment_month->text().toDouble();

    if (ui->deposit_amount->text() != "" && ui->deposit_term->text() != "" && ui->interes_rate->text() != "") {

        std::string amount_text = ui->deposit_amount->text().toStdString();
        std::string term_text = ui->deposit_term->text().toStdString();
        std::string rate_text = ui->interes_rate->text().toStdString();
        if (isNum(amount_text) && isNum(term_text) && isNum(rate_text)) {

            if (ui->periodicity_of_payments->text() != "") {
                if (isNum(ui->periodicity_of_payments->text().toStdString())) {
                    bool check = false;
                    if (ui->checkBox->isChecked()) {
                        check = true;
                    }
                    s21::Controller Contr;
                    std::vector<double> rez = Contr.DepCalculations(check, deposit_term, deposit_amount,
                                          interest_rate, tax_rate, replenishments_month, replenishments_sum,
                                          partial_withdrawals_month, partial_withdrawals_sum);
                    ui->accured_interest->setText(QString::number(rez[0], 'f', 2));
                    ui->deposit_end->setText(QString::number(rez[1], 'f', 2));
                    ui->tax_ammount->setText(QString::number(rez[2], 'f', 2));
                } else {
                    QMessageBox::warning(this, "Warning","Периодичность выплат должна быть числом!");
                }
            } else {
                QMessageBox::warning(this, "Warning","Заполните периодичность выплат!");
            }
        } else {
            QMessageBox::warning(this, "Warning","Вводите только числа!");
        }
    } else {
        QMessageBox::warning(this, "Warning","Заполните сумму, срок и процентную ставку!");
    }
}
