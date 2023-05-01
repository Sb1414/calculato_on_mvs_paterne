#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
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
  connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(ariph_numbers()));
  connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(ariph_numbers()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(trigon_numbers()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(trigon_numbers()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(trigon_numbers()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(trigon_numbers()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(trigon_numbers()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(trigon_numbers()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(trigon_numbers()));
  connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(ariph_numbers()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(trigon_numbers()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(trigon_numbers()));
}

MainWindow::~MainWindow() {}

void MainWindow::digits_numbers() {
  CheckNull();
  QPushButton *button = (QPushButton *)sender();
  std::pair<size_t, int> rez = helperDotClick();
  QString str_form = ui->result->text();
  if (rez.second == 0 || rez.second == 1) {
      ui->result->setText(str_form + button->text());
  }
}

void MainWindow::ariph_numbers() {
  CheckNull();
  QPushButton *button = (QPushButton *)sender();
  if (helper()) {
    ui->result->setText(ui->result->text() + button->text());
  }
}

void MainWindow::on_pushButton_div_clicked() {
  CheckNull();
  if (helper()) {
    ui->result->setText(ui->result->text() + "/");
  }
}

void MainWindow::on_pushButton_mul_clicked() {
  CheckNull();
  if (helper()) {
    ui->result->setText(ui->result->text() + "*");
  }
}

void MainWindow::on_pushButton_x_clicked() {
    CheckNull();
    QPushButton *button = (QPushButton *)sender();
    QString str_form = ui->result->text();
    if (!str_form.endsWith('X')) {
      ui->result->setText(ui->result->text() + button->text());
    }
}

void MainWindow::trigon_numbers() {
    CheckNull();
    QPushButton *button = (QPushButton *) sender();
    std::pair<size_t, int> rez = helperDotClick();
    QString str_form = ui->result->text();
    if (rez.second == 0) {
        if (ui->result->text() == '0' || ui->result->text() == "") {
            ui->result->setText(button->text());
        }
        else if (!str_form.endsWith('*') && !str_form.endsWith('/') && !str_form.endsWith('+') && !str_form.endsWith('-') && !str_form.endsWith('(')) {
            ui->result->setText(ui->result->text() + "*" + button->text());
        } else {
            ui->result->setText(ui->result->text() + button->text());
        }
   }
}

std::pair<size_t, int> MainWindow::helperDotClick() {
  int count = 0;
  QString str = ui->result->text();
  size_t len = str.isNull() ? 0 : str.length();
  for (size_t i = 0; i < len; i++) {
    if (str[i] == '.') {
      count = 1;
    } else if (!std::isdigit(str[i].toLatin1())) {
      count = 0;
      break;
    }
  }
  std::pair<size_t, int> result = {len, count};
  return result;
}

void MainWindow::on_pushButton_dot_clicked() {
  std::pair<size_t, int> rez = helperDotClick();
  QString str = ui->result->text();
  if (rez.first != 0) {
    if (rez.second == 0 && (str[rez.first - 1] >= '0' && str[rez.first - 1] <= '9')) {
      ui->result->setText(ui->result->text() + ".");
    }
  }
}

void MainWindow::on_pushButton_pi_clicked() {
  std::pair<size_t, int> rez = helperDotClick();
  QString str = ui->result->text();
  size_t j = rez.first - 1;
  if (str == "" || str == '0') {
    ui->result->setText(ui->result->text() + "3.141592653589793");
  } else if (rez.first == 0) {
    ui->result->setText(ui->result->text() + "3.141592653589793");
  } else if (rez.second == 0 && (!std::isdigit(str[j].toLatin1()) && str[j] != '.')) {
    ui->result->setText(ui->result->text() + "3.141592653589793");
  } else if (!str.endsWith('*') && !str.endsWith('/') && !str.endsWith('+') && !str.endsWith('-') && !str.endsWith('.') && !str.endsWith('(')) {
    ui->result->setText(ui->result->text() + "*3.141592653589793");
  }
}

void MainWindow::on_pushButton_exp_clicked() {
  std::pair<size_t, int> rez = helperDotClick();
  QString str = ui->result->text();
  size_t j = rez.first - 1;
  if (str == "" || str == '0') {
    ui->result->setText(ui->result->text() + "2.718281828459045");
  } else if (rez.first == 0) {
    ui->result->setText(ui->result->text() + "2.718281828459045");
  } else if (rez.second == 0 && (!std::isdigit(str[j].toLatin1()) && str[j] != '.')) {
    ui->result->setText(ui->result->text() + "2.718281828459045");
  } else if (!str.endsWith('*') && !str.endsWith('/') && !str.endsWith('+') && !str.endsWith('-') && !str.endsWith('.') && !str.endsWith('(')) {
    ui->result->setText(ui->result->text() + "*2.718281828459045");
  }
}

bool MainWindow::helper() {
  bool rez = false;
  QString str = ui->result->text();
  int len = str.isNull() ? 0 : str.length();
  if (len != 0) {
    if ((str[len - 1] >= '0' && str[len - 1] <= '9') || str[len - 1] == ')' ||
        str[len - 1] == 'X') {
      rez = true;
    }
  }
  return rez;
}

void MainWindow::on_pushButton_equals_clicked() {
  QString str_expr = ui->result->text();
  std::string strIn = str_expr.toLocal8Bit().data();
    s21::Controller control(strIn);
    std::pair<std::string, double> result = control.calculations();
    char str[256] = {0};
    if (result.first.size() == 0) {
      result.second = result.second == -0.0 ? 0.0 : result.second;
      sprintf(str, "%.15g", result.second);
      ui->result->setText(str);
    } else {
      QString qs = QString::fromLocal8Bit(result.first.c_str());
      ui->result->setText(qs);
    }
}

void MainWindow::on_pushButton_graph_clicked()
{
    QString send = ui->result->text();
    ui->widget->clearGraphs();
    if (send != "") {
        QByteArray ba = send.toLocal8Bit();
        if (ui->x2->text().toDouble() >= ui->x1->text().toDouble() ||
            ui->y2->text().toDouble() >= ui->y1->text().toDouble()) {
          QMessageBox::warning(this, "Warning", "Неверный интервал x/y", QMessageBox::Ok);
        } else {
          ui->widget->xAxis->setRange(ui->x2->text().toDouble(), ui->x1->text().toDouble());
          ui->widget->yAxis->setRange(ui->y2->text().toDouble(), ui->y1->text().toDouble());
          ui->widget->addGraph();
          QList<double> x;
          QList<double> y;
          for (double i = ui->x2->text().toDouble(); i < ui->x1->text().toDouble();) {
            x.push_back(i);
            QString buf = ui->result->text();
            QString str_expr = buf.replace(QString("X"), QString::number(i, 'f', 3));
            std::string strBuf = str_expr.toLocal8Bit().data();
            s21::Controller ctrl(strBuf);
            std::pair<std::string, double> result = ctrl.calculations();
            y.push_back(result.second);
            i += 0.10;
          }
          ui->widget->graph(0)->addData(x, y);
          ui->widget->setInteraction(QCP::iRangeZoom, true);
          ui->widget->setInteraction(QCP::iRangeDrag, true);
          ui->widget->graph(0)->addData(x, y);
          ui->widget->replot();
        }
    } else {
        QMessageBox::warning(this, "Warning", "Нет данных для построения графика");
    }
}


void MainWindow::on_pushButton_clear_clicked()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_mul->setChecked(false);
    ui->pushButton_div->setChecked(false);
    ui->result->setText("0");
}

void MainWindow::on_pushButton_backspace_clicked()
{
    std::string rdctstr = ui->result->text().toUtf8().constData();
    std::string result = rdctstr.substr(0, rdctstr.length() - 1);
    ui->result->setText(QString::fromStdString(result));
}

void MainWindow::on_pushButton_plusminus_clicked()
{
    std::string strres = ui->result->text().toStdString();
    if (strres[0] == '-') {
        char ch = '-';
            if (strres.front() == ch) {
                strres.erase(strres.begin());
            }
        ui->result->setText(QString::fromStdString(strres));
    } else {
        flag_ = true;
        ui->result->setText(QString::fromStdString("-" + strres));
    }
}

void MainWindow::on_pushButton_round_bracket_clicked()
{
    QString all_numbers;
    CheckNull();
    if (!flag_bracket) {
        all_numbers = (ui->result->text() + "(");
        ui->result->setText(all_numbers);
        flag_bracket = true;
    } else if (flag_bracket) {
        all_numbers = (ui->result->text() + ")");
        ui->result->setText(all_numbers);
        flag_bracket = false;
    }
}

void MainWindow::CheckNull() {
    if (ui->result->text() == '0') { ui->result->setText(""); }
}

void MainWindow::on_credit_clicked()
{
    credit window;
    window.setModal(true);
    window.exec();
}

void MainWindow::on_deposit_clicked()
{
    deposit window;
    window.setModal(true);
    window.exec();
}


