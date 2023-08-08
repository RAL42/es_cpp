#include<iostream>

int main(){
    int a;
    int b;
    int c;
    std::cin>> a>> b>> c ;
    if(a<=b && a<=c){
        std::cout<< "il piu piccolo e' "<< a <<'\n';
        return 0;
    }
     if(b<=a && b<=c){
        std::cout<< "il piu piccolo e' "<< b <<'\n';
        return 0;
    }
     if(c<=a && c<=b){
        std::cout<< "il piu piccolo e' "<< c <<'\n';
        return 0;
    }
}