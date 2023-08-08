#include<iostream>

int main(){
    int a;
    std::cin>>a;
    int i=1;
    if(a<0){
        std::cout<<"non si può fare, è negativo"<<'\n';
        return 1;
    }
    if(i*i==a){
        std::cout<<"la radice quadrata di "<<a<< " è esattamente "<<i<< '\n';
    }
    else{
       while(i*i<=a){
            ++i;
        }if(i*i>a) {
            --i;
        }
        std::cout<<"la radice quadrata di "<<a<< " è poco piu di "<<i<< '\n';
    }
}