#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>

//spazio vettoriale su SFML

class vec{
sf::Vector2f v;

public:
    vec(float x, float y): v{x, y} {};
    vec() = default;

    sf::Vector2f state() const;
    float get_x() const;
    float get_y() const;
    float norm() const;
  
  template <typename T>
  void update_pos(T p){ pos = p; };

  vec& operator+=(vec const&);
  vec& operator-=(vec const&);
  vec& operator*=(double);
  vec& operator/=(double);
};

std::ostream& operator<<(std::ostream&, vec const&);
vec operator+(vec const&, vec const&);
vec operator-(vec const&, vec const&);
vec operator*(vec const&, double);
vec operator/(vec const&, double);
vec operator*(double, vec const&);
bool operator==(vec const&, vec const&);






