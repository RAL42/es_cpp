#include <iostream>

auto pow(int b, int e) {
  float result ;

  if (e >= 0) {
    result = 1;
    for (int i = 1; i <= e; ++i) {
      result = result * b;
    }
  } else {
    result = 1;
    for (int i = 1; i <= -e; ++i) {
      result = result * b;
    }
    result = 1 / result;
  }
  return result;
}

int main() {
  int b;
  int e;
  std::cin >> b >> e;
  auto res = pow(b, e);

  std::cout << b << " alla " << e << " fa: " << res << '\n';
}