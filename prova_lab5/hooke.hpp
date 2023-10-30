#pragma once
#include<iostream>
#include<cmath>
#include<vector>

struct PM {
  double m{};
  double x{};
  double v{};  
};

class Hooke{
  double l; // lunghezza a riposo
  double k;

public:
  Hooke(double l_, double k_): l(l_), k(k_) {
    if(l || k < 0.) {
      throw std::runtime_error{"caccamerda tutto fa schifo coglione"};
    }; 
  };

  double operator() (PM const& pm1, PM const& pm2) const{
    return k * (std::abs(pm1.x - pm2.x) - l);
  };
};

class Chain {
  Hooke spring;
  std::vector<PM> chain;

public:
  Chain();
};


