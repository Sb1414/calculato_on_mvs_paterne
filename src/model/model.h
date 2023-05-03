#ifndef CALC_MODEL_H
#define CALC_MODEL_H

#include <cctype>
#include <cmath>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

namespace s21 {
class Model {
 private:
  enum type_t : char {
    NUMBER,
    END,
    PLUS = '+',
    MINUS = '-',
    MULT = '*',
    DIV = '/',
    MOD = 'm',
    POW = '^',
    SIN = 's',
    COS = 'c',
    TAN = 't',
    ATAN = 'n',
    ASIN = 'i',
    ACOS = 'o',
    SQRT = 'q',
    LOG = 'g',
    LN = 'l',
    ROUNDBRACKET_L = '(',
    ROUNDBRACKET_R = ')'
  };

 public:
  Model() : p_stream(nullptr), p_stream_string("") {}
  explicit Model(std::string initString);
  ~Model();
  double Calculate();

 private:
  std::istream* p_stream;
  std::string p_stream_string;
  type_t current;
  double m_number_value;
  void GetSymbol();
  double Arithmetic(bool get);
  double Operation(bool get);
  double Pow(bool get);
  double Expression(bool get);
  std::string Parser();
  void Check(std::string str);
  void ReplaceSubstrings(std::string& str);

 public:
  // bonus
  std::vector<double> CreditCalculations(double sum_credit, double time_credit,
                                         double per, bool check);
  std::vector<double> DepositCalculations(bool check, double deposit_term,
                                          double deposit_amount,
                                          double interest_rate, double tax_rate,
                                          double replenishments_month,
                                          double replenishments_sum,
                                          double partial_withdrawals_month,
                                          double partial_withdrawals_sum);
};

}  // namespace s21

#endif  // CALC_MODEL_H
