#include<iostream>
#include<vector>
#include<math.h>

std::vector<double> v1 {2.,4.};
std::vector<double> v2 {5.,6.};

double d(std::vector<double> v, std::vector<double> w)
{
    double a=std::abs(v[1]-w[1]);
    double b=std::abs(v[2]-w[2]);
    std::cout<< "cacca:" << a << " culo:" << b << ",  " << v[1] << ",  " << v[2] << ",  " << w[1] <<  ",  " << w[2  ] << std::endl;
    return std::max(a, b);
}

int main() {
    double distanza = d(v1,v2); 
    std::cout<< "la distanza tra i due vettori e' = " << distanza <<std::endl;
}
