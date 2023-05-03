#include <errno.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <iostream>

#include "model/model.h"

TEST(Calc, ArithmeticTest1) {
  std::string str = "14+10.3";
  s21::Model model(str);
  double rez = model.Calculate();
  double calc = 14 + 10.3;
  ASSERT_EQ(std::round(rez * 10000000), std::round(calc * 10000000));
}

TEST(Calc, ArithmeticTest2) {
  std::string str = "100.0-50+10.3";
  s21::Model model(str);
  double rez = model.Calculate();
  double calc = 100.0 - 50 + 10.3;
  ASSERT_EQ(std::round(rez * 10000000), std::round(calc * 10000000));
}

TEST(Calc, ArithmeticTest3) {
  std::string str = "100/90*5";
  s21::Model model(str);
  double rez = model.Calculate();
  double calc = 5.55555555556;
  ASSERT_EQ(std::round(rez * 10000000), std::round(calc * 10000000));
}

TEST(Calc, ArithmeticTest4) {
  std::string str = "10*(2+3)";
  s21::Model model(str);
  double rez = model.Calculate();
  double calc = 50;
  ASSERT_EQ(rez, calc);
}

TEST(Calc, ArithmeticTest5) {
  std::string str = "28+3*15-47/15*8+10.6";
  s21::Model model(str);
  double rez = model.Calculate();
  double calc = 58.5333333333;
  ASSERT_EQ(std::round(rez * 10000000), std::round(calc * 10000000));
}

TEST(Calc, ModTest1) {
  std::string str = "8mod4";
  s21::Model model(str);
  double rez = model.Calculate();
  double calc = 8 % 4;
  ASSERT_EQ(std::round(rez * 10000000), std::round(calc * 10000000));
}

TEST(Calc, ModTest2) {
  std::string str = "18mod14";
  s21::Model model(str);
  double rez = model.Calculate();
  double calc = 18 % 14;
  ASSERT_EQ(std::round(rez * 10000000), std::round(calc * 10000000));
}

TEST(Calc, num) {
  std::string str = "10.12345";
  s21::Model model(str);
  double rez = model.Calculate();
  double check = 10.12345;
  ASSERT_EQ(std::round(rez * 10000000), std::round(check * 10000000));
}

TEST(Calc, CosTest1) {
  std::string str = "cos1";
  s21::Model model(str);
  double rez = model.Calculate();
  ASSERT_EQ(std::round(rez * 10000000), std::round((cos(1)) * 10000000));
}

TEST(Calc, CosTest2) {
  std::string str = "cos0";
  s21::Model model(str);
  double rez = model.Calculate();
  ASSERT_EQ(std::round(rez * 10000000), std::round((cos(0)) * 10000000));
}

TEST(Calc, CosTest3) {
  std::string str = "cos(-1)";
  s21::Model model(str);
  double rez = model.Calculate();
  ASSERT_EQ(std::round(rez * 10000000), std::round((cos(-1)) * 10000000));
}

TEST(Calc, SinTest1) {
  std::string str = "sin1";
  s21::Model model(str);
  double rez = model.Calculate();
  ASSERT_EQ(std::round(rez * 10000000), std::round((sin(1)) * 10000000));
}

TEST(Calc, SinTest2) {
  std::string str = "sin0";
  s21::Model model(str);
  double rez = model.Calculate();
  ASSERT_EQ(std::round(rez * 10000000), std::round((sin(0)) * 10000000));
}

TEST(Calc, SinTest3) {
  std::string str = "sin(-1)";
  s21::Model model(str);
  double rez = model.Calculate();
  ASSERT_EQ(std::round(rez * 10000000), std::round((sin(-1)) * 10000000));
}

TEST(Calc, SinTest4) {
  std::string str = "sin50";
  s21::Model model(str);
  double rez = model.Calculate();
  ASSERT_EQ(std::round(rez * 10000000), std::round((sin(50)) * 10000000));
}

TEST(Calc, TanTest1) {
  std::string str = "tan1";
  s21::Model model(str);
  double rez = model.Calculate();
  ASSERT_EQ(std::round(rez * 10000000), std::round((tan(1)) * 10000000));
}

TEST(Calc, TanTest2) {
  std::string str = "tan0";
  s21::Model model(str);
  double rez = model.Calculate();
  ASSERT_EQ(std::round(rez * 10000000), std::round((tan(0)) * 10000000));
}

TEST(Calc, TanTest3) {
  std::string str = "tan(-1)";
  s21::Model model(str);
  double rez = model.Calculate();
  ASSERT_EQ(std::round(rez * 10000000), std::round((tan(-1)) * 10000000));
}

TEST(Calc, TanTest4) {
  std::string str = "tan(-45)";
  s21::Model model(str);
  double rez = model.Calculate();
  ASSERT_EQ(std::round(rez * 10000000), std::round((tan(-45)) * 10000000));
}

TEST(Calc, AtanTest1) {
  std::string str = "atan(0)";
  s21::Model model(str);
  double rez = model.Calculate();
  ASSERT_EQ(std::round(rez * 10000000), std::round((atan(0)) * 10000000));
}

TEST(Calc, AtanTest2) {
  std::string str = "atan(-45)";
  s21::Model model(str);
  double rez = model.Calculate();
  ASSERT_EQ(std::round(rez * 10000000), std::round((atan(-45)) * 10000000));
}

TEST(Calc, AtanTest3) {
  std::string str = "atan(1)";
  s21::Model model(str);
  double rez = model.Calculate();
  ASSERT_EQ(std::round(rez * 10000000), std::round((atan(1)) * 10000000));
}

TEST(Calc, AsinTest1) {
  std::string str = "asin(0)";
  s21::Model model(str);
  double rez = model.Calculate();
  ASSERT_EQ(std::round(rez * 10000000), std::round((asin(0)) * 10000000));
}

TEST(Calc, AsinTest2) {
  std::string str = "asin(1)";
  s21::Model model(str);
  double rez = model.Calculate();
  ASSERT_EQ(std::round(rez * 10000000), std::round((asin(1)) * 10000000));
}

TEST(Calc, AsinTest3) {
  std::string str = "asin(-1)";
  s21::Model model(str);
  double rez = model.Calculate();
  ASSERT_EQ(rez, (asin(-1)));
}

TEST(Calc, AsinTest4) {
  std::string str = "asin(-15)";
  s21::Model model(str);
  double rez = model.Calculate();
  ASSERT_TRUE(std::isnan(rez));
}

TEST(Calc, AcosTest1) {
  std::string str = "acos(-1)";
  s21::Model model(str);
  double rez = model.Calculate();
  ASSERT_EQ(std::round(rez * 10000000), std::round((acos(-1)) * 10000000));
}

TEST(Calc, AcosTest2) {
  std::string str = "acos(0)";
  s21::Model model(str);
  double rez = model.Calculate();
  ASSERT_EQ(std::round(rez * 10000000), std::round((acos(0)) * 10000000));
}

TEST(Calc, AcosTest3) {
  std::string str = "acos(1)";
  s21::Model model(str);
  double rez = model.Calculate();
  ASSERT_EQ(std::round(rez * 10000000), std::round((acos(1)) * 10000000));
}

TEST(Calc, AcosTest4) {
  std::string str = "acos(100)";
  s21::Model model(str);
  double rez = model.Calculate();
  ASSERT_TRUE(std::isnan(rez));
}

TEST(Calc, SqrtTest1) {
  std::string str = "sqrt4";
  s21::Model model(str);
  double rez = model.Calculate();
  ASSERT_EQ(std::round(rez * 10000000), std::round((sqrt(4)) * 10000000));
}

TEST(Calc, SqrtTest2) {
  std::string str = "sqrt0";
  s21::Model model(str);
  double rez = model.Calculate();
  ASSERT_EQ(std::round(rez * 10000000), std::round((sqrt(0)) * 10000000));
}

TEST(Calc, SqrtTest3) {
  std::string str = "sqrt(-1)";
  s21::Model model(str);
  double rez = model.Calculate();
  ASSERT_TRUE(std::isnan(rez));
}

TEST(Calc, LogTest1) {
  std::string str = "log4";
  s21::Model model(str);
  double rez = model.Calculate();
  ASSERT_EQ(std::round(rez * 10000000), std::round((log10(4)) * 10000000));
}

TEST(Calc, LogTest2) {
  std::string str = "log0";
  s21::Model model(str);
  double rez = model.Calculate();
  ASSERT_EQ(std::round(rez * 10000000), std::round((log10(0)) * 10000000));
}

TEST(Calc, LogTest3) {
  std::string str = "log0+log1";
  s21::Model model(str);
  double rez = model.Calculate();
  ASSERT_EQ(std::round(rez * 10000000),
            std::round((log10(0) + log10(1)) * 10000000));
}

TEST(Calc, LnTest1) {
  std::string str = "ln4";
  s21::Model model(str);
  double rez = model.Calculate();
  ASSERT_EQ(std::round(rez * 10000000), std::round((log(4)) * 10000000));
}

TEST(Calc, LnTest2) {
  std::string str = "ln0";
  s21::Model model(str);
  double rez = model.Calculate();
  ASSERT_EQ(std::round(rez * 10000000), std::round((log(0)) * 10000000));
}

TEST(Calc, PowTest1) {
  std::string str = "4^2";
  s21::Model model(str);
  double rez = model.Calculate();
  ASSERT_EQ(std::round(rez * 10000000), std::round(pow(4, 2)) * 10000000);
}

TEST(Calc, PowTest2) {
  std::string str = "9^0.2";
  s21::Model model(str);
  double rez = model.Calculate();
  ASSERT_EQ(rez, pow(9, 0.2));
}

TEST(Calc, ComboTest1) {
  std::string str = "9^0.2*cos(1)";
  s21::Model model(str);
  double rez = model.Calculate();
  ASSERT_EQ(rez, pow(9, 0.2) * cos(1));
}

TEST(Calc, ComboTest2) {
  std::string str = "ln(0)^(0.2*cos(1))";
  s21::Model model(str);
  double rez = model.Calculate();
  ASSERT_EQ(rez, pow((log(0)), 0.2 * cos(1)));
}

TEST(Calc, ComboTest3) {
  std::string str = "acos(1)^(1.2*sin(11))*10";
  s21::Model model(str);
  double rez = model.Calculate();
  ASSERT_EQ(rez, pow((acos(1)), 1.2 * sin(11)) * 10);
}

TEST(Calc, ComboTest4) {
  std::string str = "cos(10)+(1.2*sin(11))";
  s21::Model model(str);
  double rez = model.Calculate();
  ASSERT_EQ(rez, (cos(10)) + (1.2 * sin(11)));
}

TEST(Calc, ComboTest5) {
  std::string str = "sin(10)+(1.2*cos(11))+acos(1)^(1.2*sin(11))";
  s21::Model model(str);
  double rez = model.Calculate();
  ASSERT_EQ(rez, (sin(10)) + (1.2 * cos(11)) + pow((acos(1)), 1.2 * sin(11)));
}

TEST(Calc, ComboTest6) {
  std::string str = "tan(3)*(3.2*atan(1))^(1.2*sin(11))";
  s21::Model model(str);
  double rez = model.Calculate();
  ASSERT_EQ(rez, (tan(3)) * pow((3.2 * atan(1)), 1.2 * sin(11)));
}

TEST(Calc, ComboTest7) {
  std::string str = "tan(3)/(3*atan(1))^(12*sin(1))";
  s21::Model model(str);
  double rez = model.Calculate();
  ASSERT_EQ(rez, (tan(3)) / pow((3 * atan(1)), 12 * sin(1)));
}

TEST(Calc, ComboTest8) {
  std::string str = "log((3*atan(1))^(12*sin(1)/12))";
  s21::Model model(str);
  double rez = model.Calculate();
  ASSERT_EQ(rez, log10(pow((3 * atan(1)), 12 * sin(1) / 12)));
}

// throw
TEST(Calc, InvalidInput) {
  std::string longString(256, 'x');
  EXPECT_THROW(s21::Model model(longString), std::overflow_error);
}

TEST(Calc, LogLnTestThrow) {
  std::string str = "lo";
  s21::Model model(str);
  ASSERT_THROW(model.Calculate(), std::invalid_argument);
}

TEST(Calc, AcosAsinAtanTestThrow) {
  std::string str = "at";
  s21::Model model(str);
  ASSERT_THROW(model.Calculate(), std::invalid_argument);
}

TEST(Calc, SinSqrtTestThrow) {
  std::string str = "si";
  s21::Model model(str);
  ASSERT_THROW(model.Calculate(), std::invalid_argument);
}

TEST(Calc, CosTestThrow) {
  std::string str = "cs";
  s21::Model model(str);
  ASSERT_THROW(model.Calculate(), std::invalid_argument);
}

TEST(Calc, ModTestThrow) {
  std::string str = "mo";
  s21::Model model(str);
  ASSERT_THROW(model.Calculate(), std::invalid_argument);
}

TEST(Calc, DivNullTestThrow) {
  std::string str = "6/0";
  s21::Model model(str);
  ASSERT_THROW(model.Calculate(), std::logic_error);
}

TEST(Calc, ModNullTestThrow) {
  std::string str = "6mod0";
  s21::Model model(str);
  ASSERT_THROW(model.Calculate(), std::logic_error);
}

TEST(Calc, InvalidSimbolsTestThrow) {
  std::string str = "cos7arc6";
  s21::Model model(str);
  ASSERT_THROW(model.Calculate(), std::invalid_argument);
}

TEST(Calc, GetSymbolInvalidChar) {
  std::string str = "a+b";
  std::istringstream iss(str);
  s21::Model model(iss.str());
  ASSERT_THROW(model.Calculate(), std::invalid_argument);
}

// bonus

TEST(ModelTest, CreditCalculations_Check) {
  s21::Model model;
  std::vector<double> expected = {172165, 72165.1, 1434.71};
  std::vector<double> result = model.CreditCalculations(100000, 120, 12, true);
  ASSERT_NEAR(expected[0], result[0], 1);
  ASSERT_NEAR(expected[1], result[1], 1);
  ASSERT_NEAR(expected[2], result[2], 1);
}

TEST(ModelTest, CreditCalculations_NoCheck) {
  s21::Model model;
  std::vector<double> expected = {831.20, 1000, 10958.9, 958.879};
  std::vector<double> result = model.CreditCalculations(10000, 12, 20, false);
  ASSERT_NEAR(expected[0], result[0], 1);
  ASSERT_NEAR(expected[1], result[1], 1);
  ASSERT_NEAR(expected[2], result[2], 1);
}

TEST(DepositCalculationsTest, NoReplenishmentsOrWithdrawals) {
  s21::Model model_;
  std::vector<double> result =
      model_.DepositCalculations(true, 12, 10000, 10, 20, 0, 0, 0, 0);
  ASSERT_NEAR(829.995, result[0], 1);
  ASSERT_NEAR(11659.990, result[1], 1);
  ASSERT_NEAR(207.498, result[2], 1);
}

TEST(DepositCalculationsTest, NoReplenishmentsOrWithdrawalsFalse) {
  s21::Model model_;
  std::vector<double> result =
      model_.DepositCalculations(false, 12, 10000, 10, 20, 0, 0, 0, 0);
  ASSERT_NEAR(800, result[0], 1);
  ASSERT_NEAR(10800, result[1], 1);
  ASSERT_NEAR(200, result[2], 1);
}

TEST(DepositCalculationsTest, MonthlyReplenishments) {
  s21::Model model_;
  std::vector<double> result =
      model_.DepositCalculations(true, 12, 10000, 10, 20, 5, 500, 0, 0);
  ASSERT_NEAR(850.33, result[0], 1);
  ASSERT_NEAR(12200.66, result[1], 1);
  ASSERT_NEAR(212.58, result[2], 1);
}

TEST(DepositCalculationsTest, MonthlyPartialWithdrawals) {
  s21::Model model_;
  std::vector<double> result =
      model_.DepositCalculations(true, 12, 10000, 10, 20, 0, 0, 5, 500);
  ASSERT_NEAR(809.65, result[0], 1);
  ASSERT_NEAR(11119.31, result[1], 1);
  ASSERT_NEAR(202.41, result[2], 1);
}

TEST(DepositCalculationsTest, MonthlyReplenishmentsAndPartialWithdrawals) {
  s21::Model model_;
  std::vector<double> result =
      model_.DepositCalculations(true, 12, 10000, 10, 20, 5, 500, 5, 500);
  ASSERT_NEAR(829.99, result[0], 1);
  ASSERT_NEAR(11659.99, result[1], 1);
  ASSERT_NEAR(207.49, result[2], 1);
}

TEST(DepositCalculationsTest, FalseDeposit) {
  s21::Model model_;
  std::vector<double> result =
      model_.DepositCalculations(false, 12, 10000, 10, 20, 5, 500, 5, 500);
  ASSERT_NEAR(800.00, result[0], 1);
  ASSERT_NEAR(10800, result[1], 1);
  ASSERT_NEAR(200.00, result[2], 1);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
