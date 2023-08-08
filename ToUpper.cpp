// #include <array>
// #include <vector>
#include<iostream>

int main() {
  std::string p{"MAMMT'?!"};

  for (char& c : p) {
    c=std::toupper(c);
  }

  std::cout<<p<<'\n';
}