#include <iostream>
int main()
{
    std::cout<<"ramm nu numr strunz \n";
    int numr;
    std::cin>>numr;
    if(numr%2==0){
        std::cout<<"O numr "<<numr<<" e' pari, cià cià \n";
    }else{
        std::cout<<"O numr "<<numr<<" nun e' pari, strunz \n";
    }
}