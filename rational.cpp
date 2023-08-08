#include <iostream>
#include "gcd.hpp"


  struct rational {
    int n_;
    int d_;

    rational(int num = 0, int den = 1) : n_{num}, d_{den} {
      
      if (d_ == 0) {
        // must fail
        std::cout << "non si puo dividere per 0" << '\n';
        EXIT_FAILURE;
      }
      
      if (d_ < 0) {
        n_ = -n_;
        d_ = -d_;
      }

      auto const g = GCD::gcd(n_, d_);
      n_ /= g;
      d_ /= g;

      
    }
  };

std::ostream& operator<<(std::ostream& output,rational r) { // se non metto & nell'argometno da errore; il primo dei 2 par. è ciò che sta a sx di "<<" il secondo è ciò che sta a dx  
  output << r.n_ << '/' << r.d_ << '\n';
  return output;
  }


int n;
int d;

int main() {
  std::cout << "inserisci numeratore e denominatore: ";
  std::cin >> n >> d;
  rational r1{n, d};
  std::cout<< r1 << '\n';
}