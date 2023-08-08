#include <iostream>

struct Complex {
  double r;
  double i;
};

std::ostream& operator<<(std::ostream& output,Complex c)  // se non metto & nell'argometno da errore; il primo dei 2 par.
  {                                                       // è ciò che sta a sx di "<<" il secondo è ciò che sta a dx  
  output << c.r << '+' << c.i << 'i' << '\n';
  return output;
  }

Complex operator + (Complex const& a, Complex const& b){
    return Complex{a.r + b.r , a.i + b. i};
}

double norm2(Complex c) { return c.r * c.r + c.i * c.i; }
// double n = norm2(c);

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
}