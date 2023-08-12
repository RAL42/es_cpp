#include <iostream>
#include "complex.hpp"

int main() {
  double a;
  double b;
  std::cout << "Immetti parte reale e immaginaria del PRIMO numero complesso" << '\n';
  std::cin >> a >> b;
  Complex c1{a, b};

  double c;
  double d;
  std::cout << "Immetti parte reale e immaginaria del SECONDO numero complesso"<< '\n';
  std::cin >> c >> d;
  Complex c2{c, d};

  Complex somma = c1 + c2;
  std::cout << "I numeri sono :" << '\n'<< "c1 = " << c1 << "c2 = " << c2 << '\n' << "La loro somma fa: " << somma <<'\n';

  std::cout<< "La norma al quadrato di c1 vale= " << norm2(c1) << '\n' << "la norma al quadrato di c2 vale= " << norm2(c2) << '\n';

}