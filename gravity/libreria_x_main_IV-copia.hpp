#pragma once

#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
#include <vector>

#include "Spazio_vett.hpp"

const float pi = M_PI;  // usa l'alias
float w{};              // velocità angolare

//---------------------------------------------------------------

class PM {  // Punto Materiale
  vec pos;
  vec vel;
  float m;  // massa

  sf::CircleShape s;

 public:
  PM(float p_x, float p_y, float v_x, float v_y, float m_)
      : pos{p_x, p_y}, vel{v_x, v_y}, m(m_) {  // constructor

    s.setRadius(2.5);
    s.setPosition(pos.get_x(), pos.get_y());
    s.setFillColor(sf::Color::White);
  }

  PM(vec x, vec y, float m_) : pos(x), vel(y), m(m_){};

  float get_x() { return pos.get_x(); };
  float get_y() { return pos.get_y(); };
  float get_m() { return m; };

  vec get_pos() { return pos; }
  vec get_vel() { return vel; }
};

//---------------------------------------------------------------

class Hooke {
  const float k;
  const vec l;

 public:
  Hooke(const float k_, const vec l_) : k(k_), l(l_){};
  Hooke() = default;

  auto operator()(PM pm1, PM pm2) const { // calcola la forza (è un vettore)
  return k * ((pm2.get_pos() - pm1.get_pos()) - l); 
  }

  float get_k() { return k; }
  vec get_lv() { return l; } //lv stsa per "l vettoriale"
  float get_l() {return l.norm();} 
};

//---------------------------------------------------------------

float d(PM pm1, PM pm2) {  // distanza tra due PM
  vec v = pm1.get_pos() - pm2.get_pos();
  return v.norm();
}

vec x(PM pm1, PM pm2) {
  return pm2.get_pos() - pm1.get_pos();
}  // vettore che esce da pm1 e punta pm2: pm1=pm_j; pm2=pm_j+1 oppure pm_j-1

std::ostream &operator<<(std::ostream &output, PM pm) {
  output << "\nPM:  x = (" << pm.get_x() << ", " << pm.get_y() << ") "
         << "\n     v = (" << pm.get_vel().get_x() << ", "
         << pm.get_vel().get_y() << ") " << '\n';
  return output;
}

//---------------------------------------------------------------

class Chain {
  Hooke hooke_;
  std::vector<PM> ch_;

  PM solve(PM pm, vec f, double const delta_t) const {
    auto const a = f / pm.get_m();
    auto const v = pm.get_vel() + a * delta_t;
    auto const x = pm.get_pos() + (v + 0.5 * a * delta_t) * delta_t;

    return PM(x, v, pm.get_m());
  }

 public:
  Chain(Hooke const &hooke) : hooke_(hooke){};

  bool empty() { return ch_.empty(); };
  std::size_t size() const { return ch_.size(); };
  void push_back(PM const &pm) { ch_.push_back(pm); }
  std::vector<PM> const &state() const {return ch_;};

  void evolve(double const dt) {
    auto state_it = ch_.begin();
    auto state_it_next = std::next(state_it);
    auto state_last = std::prev(ch_.end());

    vec f_prev;
    for (; state_it != state_last; ++state_it, ++state_it_next) {
      vec f = hooke_(*state_it, *state_it_next);
      *state_it = solve(*state_it, f - f_prev, dt);
      f_prev = f;
    }

    *state_last = solve(*state_last, (-1)*f_prev, dt);
  };
};

// aggiorna la "fisica" di pm_j
/*PM update_physics(PM pmj, PM pmP1, PM pmM1, Hooke molla,
                  float dt) {  // PM1=PMj e pmP1=PMj+1 pmM1=PMj-1
  PM temp_pm = pmj;
  float M{1 / temp_pm.get_m()};
  float inverse_d1{1 / d(temp_pm, pmP1)};
  float inverse_d2{1 / d(temp_pm, pmM1)};

  const sf::Vector2f F1 = molla.get_k() * (d(temp_pm, pmP1) - molla.get_l()) *
                          (pmP1 - temp_pm) *
                          inverse_d1;  // F dovuta alla massa successiva
  const sf::Vector2f F2 = molla.get_k() * (d(temp_pm, pmM1) - molla.get_l()) *
                          (pmM1 - temp_pm) *
                          inverse_d2;  // F dovuta alla massa precedente
  const sf::Vector2f F3 =
      w * w *
      sf::Vector2f(
          pmj.get_x(),
          0);  // moltiplicando per il vector dovrei dividere per il modulo, che
               // però sarebbe comparso a numeratore per via della formula
               // analtica Senza massa così evito di moltiplicare e dividere,
               // nella formula di a la metto fuori dalla parentesi
  const sf::Vector2f a = M * (F1 + F2) + F3;

  temp_pm.= (a * dt) + temp_pm.get_vel();
  sf::Vector2f v = temp_pm.get_vel();

  temp_pm.update_pos((v * dt) + temp_pm.get_pos());
  sf::Vector2f x = temp_pm.get_pos();
  // std::cout<< "temp_pm " <<temp_pm;
  // std::cout<<"     a = (" << a.get_x() << ", " << a.get_y() << ") " << '\n';

  return temp_pm;
}*/
