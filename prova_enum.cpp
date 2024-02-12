#include <iostream>

enum class operazione { piu, meno, per, diviso };
auto compute(char const& op, double const& left, double const& right) {
  operazione OP;
  switch (op) {
    case '+':
        OP = operazione::piu;
      break;

    default:
      break;
  }

  switch (OP) {
    case operazione::piu:
      return left + right;
      break;
    case operazione::meno:
      return left - right;
      break;
    case operazione::per:
      return left * right;
      break;
    case operazione::diviso:
      return (right != 0) ? left / right
                          : throw std::runtime_error("non divisibile per 0");
      break;
  }
}

int main() {
  char op;
  double left, right;
  std::cin >> left >> op >> right;
  compute(op, left, right);
}