#include <iostream>

int main() {
  double a;
  double b;
  std::string op;
  std::cin >> a >> op >> b;
  
  double res;

  if(op == "+"){
      res = a+b;
  }
  else if(op == "-"){
      res = a-b;
  }else if(op == "*"){
      res =  a*b;
  }else if(op == "/"){
      res =  a/b;
  }else{
    std::cout<<"non agg capit"<<'\n';
    return 0;
  }
  std::cout<<res<<'\n';
}