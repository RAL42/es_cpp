#include "libreria_x_main_IV-copia.hpp"

int main() {
  const int number_of_PM{10};
  const float L{2 * pi / number_of_PM};  // lunghezza a riposo calcolata come arco tra un PM e il successivo nella condizione iniziale
  Hooke molla{32, L};

  PM pm1{0, 20, 0, 0, 1};
  PM pm2{20, 20, 0, 0, 1};
  PM pm3{20, -20, 0, 0, 1};

  w = 2;

std::cout<< "iniziale : \n1" << pm1 << "2: " <<  pm2 << "3: "<< pm3;
  float t0 = 0.;
  float dt = 0.5;
  float t_max = 0.5;

  float t = t0;
  while (t <= t_max){
    PM new_pm1 = update_physics(pm1, pm2, pm3, molla, dt);
    PM new_pm2 = update_physics(pm1, pm2, pm3, molla, dt);
    PM new_pm3 = update_physics(pm1, pm2, pm3, molla, dt);


  // facendo così NON è come se lo facessi in ordine perchè gli sto dando in pasto sempre gli stessi PM 


    std::cout<< "istante " << t << ": \n" << "new_pm1 : " << new_pm1 << '\n';
    std::cout<< "new_pm2 : " << new_pm2 << '\n';
    std::cout<< "new_pm3 : " << new_pm3 << '\n';
             
    t += dt;
  }
  
  

}