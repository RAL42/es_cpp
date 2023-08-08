#ifndef GCD
#define GCD

int gcd(int n, int m) {
  int result;
  if (n == 0) {
    return m;
  }
  else if (m == 0) {
    return n;
  }
  else if (n < m) {
      if((m % n)!=0){
        int resto = m % n;
    while (resto != 0) {
     resto = m % n;
      n = m;
      m = resto;
    }
    result = n;
    }
  }

  else {
    if((n % m)!=0){
    int resto = n % m;
    while (resto != 0) {
        resto = n % m;
        m=n;
        n=resto;
    }
    result = m;
    }
  }
  return result;
}
  
#endif