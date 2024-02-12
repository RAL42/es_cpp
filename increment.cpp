#include <cassert>
#include <iostream>
#include <string>
#include <vector>

/*void increment(int& a){
    ++a;
}

int increment(int b){
    ++b;
    return b;
}*/

int& increment(int& b) {
  ++b;
  return b;
}

struct Cacca {
  double a;
  double b;
};

template <class Iterator, class T>
Iterator find(Iterator first, Iterator last, const T& c) {
  for (; first != last; ++first) {
    if (*first == c) {
      break;
    } else {
      std::cout << "\n-----Non trovato----- \n";
      break;
    }
    return first;
  }
}

class dinamicarray {
 private:
  int* membro_;

 public:
  dinamicarray(int n);
  ~dinamicarray();

  auto operator[](int i) { return *membro_; };
  //  auto operator()(int i){ *membro_ = i;};
};
dinamicarray::dinamicarray(int n) : membro_{new int[n]} {}
dinamicarray::~dinamicarray() { delete[] membro_; }

struct cacca {
  int a_;
  cacca(int a) : a_{a} {}
  void f() { std::cout << a_ << '\n'; };
};

struct cacchina : cacca {
  int b_;
  cacchina(int a, int b) : cacca{a}, b_{b} {}
  void g() { std::cout << a_ << ' ' << b_ << '\n'; };
};

int main() {
  cacca merda(1);
  cacchina merdina(32, 2);
  merda.f();
  merdina.f();
  merdina.g();

  cacca* b1 = &merda;
  cacchina* b2 = &merdina;
  std::cout << b1 << '\n';
  std::cout << b2 << '\n';
  cacca& p = merdina;  
  
  // std::cout << *b1 << '\n';
  // std::cout << *b2 << '\n';
  

  /*dinamicarray DinArray(3);
  std::cout<< DinArray[0] << ' ' << DinArray[1] << ' ' << DinArray[2] << '\n';
  */
  /*  std::vector<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    auto it = find(a.begin(), a.end(), 6);
    std::cout << *it << '\n';*/

  /*int a = 42;
  std::cout << "&a = " << &a << '\n';
  int* p = &a;
  assert(p = &a);
  std::cout << "p  = " << p << '\n';

  int** pp = &p;
  std::cout << "pp = " << pp << '\n';

  pp = nullptr;
  //  std::cout << "*pp = " << *pp << '\n';

  int b = 0;
  int* q = &b;
  std::cout << "*q  = " << *q << '\n';

  int i = 32;
  int& pi = i;
  std::cout << "pi  = " << pi << '\n';
  int* qpi = &pi;
  std::cout << "*qpi = " << qpi << '\n';

  int c = increment(a);
  std::cout << c << '\n';

  //-----------------------------
  std::string cacca = "caca";
  for (char& i : cacca) {
    std::cout << i << ' ';
    i = std::toupper(i);
    std::cout << ' ' << i << '\n';
  }
  std::cout << cacca << '\n';

  //-----------------------------

Cacca caccona{1., 213.};
auto p_caccona {&caccona};
std::cout << "p_caccona = " << p_caccona << '\n';
std::cout << "p_caccona->a = " << p_caccona->a << '\n';
std::cout << "p_caccona->b = " << p_caccona->b << '\n';
assert(p_caccona->a == caccona.a);
//auto [cacca1, cacca2] = caccona;
*/

  /*  std::vector<double> vec;
    for (double i; std::cin >> i;) {
      vec.push_back(i);
      std::cout << "hai appena aggiunto : " << i << '\n';
      std::cout << "vector is (";
      for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
      }
      std::cout << ")" << '\n';
    }
  */

  /*std::vector<std::vector<std::string>> vec{{"cacca", "merda"},
                                            {"piscio", "sbura"}};
  auto it = vec.begin();
  std::cout << (*it)[0] << '\n';
  */
}
