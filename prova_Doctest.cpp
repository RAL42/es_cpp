#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>

int isqrt(int n) {
  if (n < 0) {
    std::cout << "non si può fare, è negativo" << '\n';
    return EXIT_FAILURE;
    return 1;
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
TEST_CASE("testing isqrt") {
  CHECK(isqrt(0) == 0);
  CHECK(isqrt(9) == 3);
  CHECK(isqrt(10) == 3);
  //CHECK(isqrt(-1) == 1);
  CHECK(isqrt(-1) == EXIT_FAILURE);
  CHECK(isqrt(2) == 1);
}