#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>

/*class lessthan {
 private:
  int a_;

 public:
  lessthan(int a) : a_{a} {}
  auto operator()(int b) { return b < a_; }
};
*/

struct LT42 {
  int a;
  bool operator()(int b) { return b < 42; };
};

struct increment {
  int v;
  auto operator()() { ++v; };
};
int main() {
  // e nel main
  /*int a = 12;
  LT42 lt42;
  lt42(a);
  */

  int b = 4;
  auto incc = [b]() mutable ->int {return ++b;};
  b = incc();
  assert(b == 5);

  auto inccc = [&]() ->void {++b;};
  inccc();
  assert(b == 6);

  increment inc{b};
  inc();
  assert(inc.v == 7);
  
}