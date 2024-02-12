#include <iostream>
#include <string>

double calculate(char const& op, double const& left, double const& right) {
  double result;
  switch (op) {
    case '+':
      result = left + right;
      break;
    case '-':
      result = left - right;
      break;
    case '*':
      result = left * right;
      break;
    case '/':
      result = (right != 0) ? left / right : 0.;
      break;
    default:
      break;
  }
  return result;
}

double calculate(Operators op, double const& left, double const& right) {
  double result;
  switch (op) {
    case Operators::Plus:
      result = left + right;
      break;
    case Operators::Minus:
      result = left - right;
      break;
    case Operators::Multiply:
      result = left * right;
      break;
    case Operators::Divide:
      result = (right != 0) ? left / right : 0.;
      break;
    default:
      break;
  }
  return result;
}

int main() {
  enum class Operators { Plus, Minus, Multiply, Divide };
  double left;
  double right;
  char op;
  Operators op;
  std::cin >> left >> op >> right;

  double result = calculate(op, left, right);
  double result1 = calculate()
  std::cout << result << '\n';
}