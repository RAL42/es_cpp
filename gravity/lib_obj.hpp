#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include<cmath>
#include<SFML/Graphics.hpp>

class PM { // Punto Materiale
  sf::Vector2f pos;
  //sf::Vector2f vel;
  float m;  // massa

  sf::CircleShape s;

 public:
  PM(float p_x, float p_y,float m_) {  // constructor
    pos.x = p_x;
    pos.y = p_y;

    //vel.x = v_x;
    //vel.y = v_y;

    m = m_;

    s.setRadius(5);
    s.setPosition(pos);
    s.setFillColor(sf::Color::White);
  }
  void draw(sf::RenderWindow& wind){
    s.setPosition(pos);
    wind.draw(s);
  }
  float get_x(){
    return pos.x;
  };
  float get_y(){
    return pos.y;
  }

void operator= (PM pm1) {
  pos.x = pm1.get_x();
  pos.y = pm1.get_y();
}

void update_x(float x_){
  pos.x = x_;
}
void update_y(float y_){
  pos.y = y_;
}

};

//-------------------------------------------------------------------------------------------------------------------

class Hooke {
  float k;
 // float l;  // lunghezza a riposo, deve essere la stessa di quella nella classe chain, quindi la tolgo, è inutile

 public:
  Hooke(float k_): k(k_) {
    if (k <= 0.) {
      throw std::runtime_error{"La costante elastica deve essere > 0"};
    };
  };

  float get_k(){
    return k;
  };
  
  //float operator() (PM pm1_, PM pm2_) ;
};

//-------------------------------------------------------------------------------------------------------------------

class Chain {
  std::vector<PM> ch;  // catena inestensibile come insieme discreto di PM a distanza fissa;
 
 public:
 const float pi=3.1415926;//53589793
 
 float l{}; //IMPORTANTE!!  è LA lunghezza a riposo, la uso nel main quando la do in pasto al rk4_II()

  Chain(const int number_of_PM, const float mass) { //costruisce la catena nella configurazione iniziale
    l=2*pi/number_of_PM; //lunghezza dell'arco tra un PM e il successivo, OSSIA LA LUNGHEZA A RIPOSO
      for (int i = 0; i < number_of_PM; i++) {  // con questo ciclo for genero la configurazione iniziale della catena, assegnando la posizioni iniziali utilizzando funzioni di i
      PM pm_temp(200*cos(l*i), 200*sin(l*i), mass);  // l'argomento di cos e sin sono in modo tale che i punti, inizialmente, vengano disposti su una circonferenza
      ch.push_back(pm_temp);

      std::cout<< "("<< pm_temp.get_x() << ", " << pm_temp.get_y() << ")" << '\n';
    };
  };

  void push_back(PM pm){
    ch.push_back(pm);
  };

int size(){
  return ch.size();
}

PM operator[] (const int i){
  return ch[i];
}

void operator= (Chain evolved_ch){
  if (ch.size() <= evolved_ch.size()){
    for (int i = 0; i < ch.size(); i++){ //quelli che ci sono gia li aggiorna
      ch[i]=evolved_ch[i];
    };  
    for (int i = ch.size(); i < evolved_ch.size(); i++){//se il secondo vettore ha elementi in piu, semplicemente li pusha dentro
      ch.push_back(evolved_ch[i]);
    }; 

  }else{  //ossia se la chain a sinistra dell'uguale ha size maggiore di quella a destra dell'uguale

    for (int i = 0; i < ch.size(); i++){ //aggiorno solo i primi ch.size() membri della "chain a sinistra"
      ch[i]=evolved_ch[i];
    };
    
  }
}

PM back(){
  return ch.back();
}

auto end(){  //restituisce un iterator che punta all'(ultimo +1) elemento del vector [quindi *(vector.end() -1) da  l'ultimo elemento]
  return ch.end(); //quindi va dereferenziato
}

/*void evolve(){
  std::vector<Chain> evolution_of_chains = rk4_II(ch, 0.1, 10);
}*/
};

//float W; //velocità angolare