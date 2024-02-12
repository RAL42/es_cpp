#include<iostream>
#include<memory>
#include<cassert>

int main(){
    
//unique pointer
    std::cout<< "unique \n";
    int a = 3;
    std::unique_ptr<int> p{new int{a}};
    std::cout<< *p << '\n';

    //equivale a   
    auto q = std::make_unique<int>(23);
    std::cout<< *q << '\n';
    assert(p == q);

    q = std::move(p);
    std::cout<< *q << '\n';

//shared pointer
    std::cout<< "shared \n";
    double b = 32.1;
    std::shared_ptr<double> pp{new double{b}};
    std::cout<< *pp << '\n';

    //equivale a
    auto qq = std::make_shared<double>(42.12);
    std::cout<< *qq << '\n';
    assert(pp == qq);
    
    qq = std::move(pp);
    std::cout<< *qq << '\n';
    assert(pp == qq);
}