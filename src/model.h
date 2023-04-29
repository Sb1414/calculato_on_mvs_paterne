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
  void ReplaceSubstrings(std::string& str);
};

}  // namespace s21

#endif  // CALC_MODEL_H
