#ifndef COMPLEX
#define COMPLEX

#include<iostream>

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

#endif
