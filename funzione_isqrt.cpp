#include <iostream>

int isqrt(int n) {
  if (n < 0) {
    std::cout << "non si può fare, è negativo" << '\n';
    return EXIT_FAILURE;
  }

  int i = 1;

  // if (i * i == n) {
  //   std::cout << "la radice quadrata di " << n << " è esattamente " << i
  //             << '\n';
  // } else {
    while (i * i <= n) {
      ++i;
    }
    if (i * i > n) {
      --i;
    }
    if (i * i == n) {
      std::cout << "la radice quadrata di " << n << " è esattamente " << i
                << '\n';
    } else {
      std::cout << "la radice quadrata di " << n << " è poco piu di " << i
                << '\n';
    }
  //}
  return i;
}

int main() {
  int a;
  std::cin >> a;
  isqrt(a);
}