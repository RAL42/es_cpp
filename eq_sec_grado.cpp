#include<iostream>
#include<math.h>

int main(){
    double a; 
    double b;
    double c;

    std::cout<<"Ramm o primm coefficiiente, grazie: ";        
    std::cin>> a ;
    std::cout<< '\n' <<"Ramm u secunn coefficiiente, grazie: ";        
    std::cin>> b;
    std::cout<< '\n' <<"Ramm u terzz coefficiiente, grazie: ";        
    std::cin>> c;

    double delta = ((b*b) - (4*a*c));
    if(delta<0){
        std::cout<<"Non esistono soluzioni nei Reali, t pijj nto cul mi dispiac" << '\n';
        return EXIT_FAILURE;
    }else{
    std::cout<< '\n' << "Le soluzioni di " << a << "x^2 + " << b << "x + " << c << " sono:" << '\n' ;
    float x1 = (-b + sqrt(delta))/(2*a);
    float x2 = (-b - sqrt(delta))/(2*a);
    std::cout<< "x1 = " << x1 << ";" <<'\n';
    std::cout<< "x2 = " << x2 << "." << '\n';
    return 0;
    }
}