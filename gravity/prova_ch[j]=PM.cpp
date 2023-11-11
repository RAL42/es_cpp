#define _USE_MATH_DEFINES

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include<cmath>
#include<SFML/Graphics.hpp>

const float pi = M_PI; //usa l'alias


class PM { // Punto Materiale
  sf::Vector2f pos;
  //sf::Vector2f vel;
  float m;  // massa


 public:
  PM(float p_x, float p_y,float m_): pos(p_x, p_y), m(m_) {  // constructor
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

void operator() (PM pm1) {
   pos.x=pm1.get_x();
   pos.y= pm1.get_y();
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
/*
class Chain {
  std::vector<PM> ch;  // catena inestensibile come insieme discreto di PM a distanza fissa;
 
 public:
 float l{}; //IMPORTANTE!!  è LA lunghezza a riposo, la uso nel main quando la do in pasto al rk4_II()

  Chain(const int number_of_PM, const float mass) { //costruisce la catena nella configurazione iniziale
    l=2*pi/number_of_PM; //lunghezza dell'arco tra un PM e il successivo, OSSIA LA LUNGHEZA A RIPOSO
      for (int i = 0; i < number_of_PM; i++) {  // con questo ciclo for genero la configurazione iniziale della catena, assegnando la posizioni iniziali utilizzando funzioni di i
      sf::Vector2f w(200*cos(l*i), 200*sin(l*i));
      PM pm_temp{w, mass};  // l'argomento di cos e sin sono in modo tale che i punti, inizialmente, vengano disposti su una circonferenza
      ch.push_back(pm_temp);

      std::cout<< "("<< pm_temp.pos.x << ", " << pm_temp.pos.y << ")" << '\n';
    };
  };

  void push_back(PM pm){
    ch.push_back(pm);
  };

int size(){
  return ch.size();
}

PM operator[] ( int i){
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

void empty(){
  ch.empty();
}

/*void evolve(){
  std::vector<Chain> evolution_of_chains = rk4_II(ch, 0.1, 10);
}*/
//};

class Chain {
  std::vector<PM> ch;  // catena inestensibile come insieme discreto di PM a distanza fissa;
  float m;
  int NoPM; //sta per Number of PM
  
 public:

  Chain(const int number_of_PM, const float mass): NoPM(number_of_PM), m(mass) {
    /*if(number_of_PM <= 0){
      std::cout<< "number_of_PM = " << number_of_PM << '\n';
      throw std::runtime_error{"numero di PM deve essere > 0"};
    }*/
  };
  
  void initial_config(float l){ //costruisce la catena nella configurazione iniziale
      for (int i = 0; i < NoPM; i++) {  // con questo ciclo for genero la configurazione iniziale della catena, assegnando la posizioni iniziali utilizzando funzioni di i
      PM pm_temp{static_cast<float>(200*cos(l*i)/l), static_cast<float>(200*sin(l*i)/l), m};  // l'argomento di cos e sin sono in modo tale che i punti, inizialmente, vengano disposti su una circonferenza
      ch.push_back(pm_temp);

      std::cout<< "("<< pm_temp.get_x() << ", " << pm_temp.get_y() << ")" << '\n';
    };
    std::cout<<"size of chain initially = " << ch.size() << '\n'; 
  }



 void push_back(PM pm){ch.push_back(pm);};

 int size(){return ch.size();}

 PM operator[] ( int i){return ch[i];}

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

 PM back(){return ch.back();}

 auto end(){return ch.end();}; //restituisce un iterator che punta all'(ultimo +1) elemento del vector [quindi *(vector.end() -1) da  l'ultimo elemento] quindi va dereferenziato

 void empty(){ch.empty();}

//void resize(int n){ch.resize(n);};
/*void evolve(){
  std::vector<Chain> evolution_of_chains = rk4_II(ch, 0.1, 10);
}*/
};

int main(){

    PM pm {12.3, 553.2 ,1};
    Chain ch(3, 1);
    ch.initial_config(2*pi/3);
    PM pm1=ch[1];

    std::cout<< "PRIMA \n";
    std::cout<< "pm = (" << pm.get_x() << ", " << pm.get_y() << ") \n";
    std::cout<< "pm1 = (" << pm1.get_x() << ", " << pm1.get_y() << ") \n";
    pm1 = pm;
    ch[1](pm);
    std::cout<< "DOPO \nch[1] = (" << ch[1].get_x() << ", " << ch[1].get_y() << ") \n";
    std::cout<< "pm1 = (" << pm1.get_x() << ", " << pm1.get_y() << ") \n";

    ch[1](pm1);
    std::cout<< "DOPO \nch[1] = (" << ch[1].get_x() << ", " << ch[1].get_y() << ") \n";
/*
    float a = 9328.;
    std::vector<float> v{21.,11.2, 321.54};
    
    std::cout<< "a = "<< a << '\n';
    std::cout<< "v[1] = " << v[1] << "\n";
    v[1]= a;
    std::cout<< "DOPO \nv[1] = " << v[1] << "\n";
  */  
}