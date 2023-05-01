#include "controller.h"

namespace s21 {

std::pair<std::string, double> Controller::calculations() {
  std::string error = "";
  double rez = 0.0;
  try {
    Model model(m_inputString);
    rez = model.Calculate();
  } catch (const std::exception& e) {
    error = e.what();
  }
  std::pair<std::string, double> result = {error, rez};
  return result;
}

std::vector<double> Controller::CrCalculations(double sum_credit,
                                           double time_credit, double per, bool check) {
  Model model(m_inputString);
  return model.CreditCalculations(sum_credit, time_credit, per, check);
}

std::vector<double> Controller::DepCalculations(bool check, double deposit_term, double deposit_amount, double interest_rate,
                                                double tax_rate, double replenishments_month, double replenishments_sum,
                                                double partial_withdrawals_month, double partial_withdrawals_sum) {
  Model model(m_inputString);
  return model.DepositCalculations(check, deposit_term, deposit_amount, interest_rate,
                                  tax_rate, replenishments_month, replenishments_sum,
                                  partial_withdrawals_month, partial_withdrawals_sum);
}

}  // namespace s21
