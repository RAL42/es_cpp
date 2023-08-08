#include<iostream>

int main(){
    int a;
    std::cin>>a;
    int i=1;
    int sum=0;
    if(a<0){
        std::cout<<"nope, deve essere non-negativo"<<'\n';
        return 1;
    }
    while(i<=a){
        sum+=i;
        ++i;
    }
    std::cout<<"la somma dei primi "<<a<< " numeri è "<< sum<<'\n';
}