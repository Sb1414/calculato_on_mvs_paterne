#include "model.h"

namespace s21 {

Model::Model(std::string initString) {
  if (initString.length() > 255) {
    throw std::overflow_error(
        "An Expressionession of more than 255 characters has been entered");
  } else {
    p_stream_string = initString;
    p_stream = nullptr;
    current = NUMBER;
    m_number_value = '0';
  }
}

Model::~Model() {}

void Model::GetSymbol() {
  char ch;
  if (!p_stream->get(ch)) {
    current = END;
  }
  if (ch == '\n' || isspace(ch)) {
    do {
      if (!p_stream->get(ch)) {
        current = END;
      }
    } while (ch != '\n' && isspace(ch));
  }
  if (ch == 0) {
    current = END;
  } else if (ch == MULT || ch == DIV || ch == PLUS || ch == MINUS ||
             ch == MOD || ch == POW || ch == SIN || ch == COS || ch == TAN ||
             ch == ATAN || ch == ASIN || ch == ATAN || ch == ACOS || ch == SQRT ||
             ch == LOG || ch == LN || ch == ROUNDBRACKET_L ||
             ch == ROUNDBRACKET_R) {
    current = type_t(ch);
  } else if (isdigit(ch) || ch == '.') {
    p_stream->putback(ch);
    *p_stream >> m_number_value;
    current = NUMBER;
  } else {
    throw std::invalid_argument("invalid character");
  }
}

std::string Model::Parser() {
  std::string newStr;
  bool check = false;
  for (size_t i = 0; i < p_stream_string.size(); i++) {
    char c = p_stream_string[i];
    switch (c) {
      case 'm':
        if (p_stream_string.substr(i, 3) == "mod") {
          newStr += "mod";
          i += 2;
        } else {
          check = true;
        }
        break;
      case 's':
        if (p_stream_string.substr(i, 3) == "sin") {
          newStr += "sin";
          i += 2;
        } else if (p_stream_string.substr(i, 4) == "sqrt") {
          newStr += "sqrt";
          i += 3;
        } else {
          check = true;
        }
        break;
      case 'c':
        if (p_stream_string.substr(i, 3) == "cos") {
          newStr += "cos";
          i += 2;
        } else {
          check = true;
        }
        break;
      case 't':
        if (p_stream_string.substr(i, 3) == "tan") {
          newStr += "tan";
          i += 2;
        } else {
          check = true;
        }
        break;
      case 'a':
        if (p_stream_string.substr(i, 4) == "atan") {
          newStr += "atan";
          i += 3;
        } else if (p_stream_string.substr(i, 4) == "asin") {
          newStr += "asin";
          i += 3;
        } else if (p_stream_string.substr(i, 4) == "acos") {
          newStr += "acos";
          i += 3;
        } else {
          check = true;
        }
        break;
      case 'l':
        if (p_stream_string.substr(i, 2) == "ln") {
          newStr += "ln";
          i += 1;
        } else if (p_stream_string.substr(i, 3) == "log") {
          newStr += "log";
          i += 2;
        } else {
          check = true;
        }
        break;
      default:
        newStr += c;
        break;
    }
  }
  if (check) {
    throw std::invalid_argument("invalid symbol");
  }
  return newStr;
}

double Model::Arithmetic(bool get) {
  if (get) {
    GetSymbol();
  }
  double result = 0.0;
  if (current == NUMBER) {
    result = m_number_value;
    GetSymbol();
  } else if (current == MINUS) {
    result = -Arithmetic(true);
  } else if (current == PLUS) {
    result = Arithmetic(true);
  } else if (current == SIN) {
    result = sin(Arithmetic(true));
  } else if (current == COS) {
    result = cos(Arithmetic(true));
  } else if (current == TAN) {
    result = tan(Arithmetic(true));
  } else if (current == ATAN) {
    result = atan(Arithmetic(true));
  } else if (current == ASIN) {
    result = asin(Arithmetic(true));
  } else if (current == ACOS) {
    result = acos(Arithmetic(true));
  } else if (current == SQRT) {
    result = sqrt(Arithmetic(true));
  } else if (current == LOG) {
    result = log10(Arithmetic(true));
  } else if (current == LN) {
    result = log(Arithmetic(true));
  } else if (current == ROUNDBRACKET_L) {
    double expr = Expression(true);
    GetSymbol();
    result = expr;
  } else {
    throw std::logic_error("undefined");
  }
  return result;
}

double Model::Pow(bool get) {
  double left = Arithmetic(get);

  while (true) {
    if (current == POW) {
      left = pow(left, Arithmetic(true));
    } else {
      return left;
    }
  }
}

double Model::Operation(bool get) {
  double left = Pow(get);

  while (true) {
    switch (current) {
      case MULT:
        left *= Pow(true);
        break;
      case DIV:
        if (double divisor = Pow(true)) {
          left /= divisor;
          break;
        }
        throw std::logic_error("divide by 0");
      case MOD:
        if (double divisor = Pow(true)) {
          left = std::fmod(left, divisor);
          break;
        }
        throw std::logic_error("mode by 0");
      default:
        return left;
    }
  }
}

double Model::Expression(bool get) {
  double left = Operation(get);

  for (;;) {
    switch (current) {
      case PLUS:
        left += Operation(true);
        break;
      case MINUS:
        left -= Operation(true);
        break;
      default:
        return left;
    }
  }
}

void Model::ReplaceSubstrings(std::string& str) {
  std::unordered_map<std::string, std::string> replacements = {
      {"mod", "m"},  {"log", "g"}, {"ln", "l"},  {"acos", "o"}, {"asin", "i"},
      {"atan", "n"}, {"tan", "t"}, {"cos", "c"}, {"sin", "s"},  {"sqrt", "q"},
  };
  for (auto& replacement : replacements) {
    size_t pos = 0;
    while ((pos = str.find(replacement.first, pos)) != std::string::npos) {
      if ((pos == 0 || !std::isalpha(str[pos - 1])) &&
          (pos + replacement.first.length() == str.length() ||
           !std::isalpha(str[pos + replacement.first.length()]))) {
        str.replace(pos, replacement.first.length(), replacement.second);
        pos += replacement.second.length();
      } else {
        pos += replacement.first.length();
      }
    }
  }
}

double Model::Calculate() {
  std::string str = Parser();
  ReplaceSubstrings(str);
  p_stream = new std::istringstream(str);
  double tmp = 0.0;
  while (p_stream) {
    GetSymbol();
    if (current == END) {
      break;
    }
    tmp = Expression(false);
  }
  if (p_stream != nullptr) {
    delete p_stream;
  }
  return tmp;
}

}  // namespace s21
