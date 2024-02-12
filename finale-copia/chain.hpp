#ifndef CHAIN_HPP
#define CHAIN_HPP

#include <iostream>

#include "hooke.hpp"
#include "pm.hpp"
//--------------------- FREE FUNCTION ---------------------

double d(PM const&, PM const&);
// distanza tra due PM

vec x(PM const&, PM const&);
// vettore che collega i due PM

vec apply_hooke(PM const &, PM const &, Hooke &);
// calcola la forza elastica

vec apply_CF(PM const &, double const &);
// calcola la forza centrifuga

//--------------------- CHAIN CLASS ---------------------

class Chain {
  Hooke hooke_;
  // molla che collega gli elementi della chain
  std::vector<PM> ch_;
  // vettore contenente i punti materiali

  PM solve(PM, vec, double const) const;
  // risolve le equazioni del moto e aggiorna la posizione e velocità del punto
  // materiale

 public:
  Chain(Hooke const &hooke, double const m, double const r, int const NoPM)
      : hooke_(hooke) {
    for (int i = 0; i != NoPM; ++i) {
      // con questo ciclo genero i dei punti della chain e li dispongo su una
      // circoneferenza, assegnando la posizioni iniziali utilizzando funzioni
      // di
      // i

      PM pm_temp(r * cos(2 * M_PI / NoPM * i), r * sin(2 * M_PI / NoPM * i), 0.,
                 0., m);
      // l'argomento di cos e sin sono in modo tale che i punti vengano disposti
      // su una circonferenza

      ch_.push_back(pm_temp);
    };
  };
  // parametrized constructor

  double kin_energy() const;
  // restituisce l'energia cinetica totale
  double pot_energy() const;
  // restituisce l'energia potenziale totale

  size_t size() const;
  // restituisce il numero di elementi della chain

  void push_back(PM const &);
  // richiama la funzione push_back dei std::vector

  std::vector<PM> const &state() const;
  // restituisce il vettore contenente gli elementi della chain

  PM operator[](int const);
  // per selezionare l'elemento i-esimo della chain

  void evolve(double const , double const w);
  // calcola le varie forze per ogni punto della chain e aggiorna le posizione
  // chiamando la funzione evolve
};

#endif