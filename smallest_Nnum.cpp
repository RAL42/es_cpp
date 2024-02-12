#include <iostream>
using namespace std;

int main() {
  int a;
  int i;
  cin >> a;
  int smallest = a;

  /*
    if(cin.good()){
    return 0;
    }
  */

  while (cin.good()) {
    cin >> i;
    if (i < a) {
      smallest = i;
    }
  };
  cout << "il piu piccolo e' " << smallest << '\n';
}