#include "vec.hpp"

sf::Vector2<double> vec::state() const { return v_; };

vec &vec::operator-=(vec const &other) {
  v_.x -= other.v_.x;
  v_.y -= other.v_.y;
  return *this;
}

vec &vec::operator*=(double const scalar) {
  v_.x *= scalar;
  v_.y *= scalar;
  return *this;
}

vec &vec::operator/=(double const scalar) {
  if (scalar == 0.) {
    throw std::runtime_error{"Cannot divide by zero."};
  }
  v_.x /= scalar;
  v_.y /= scalar;
  return *this;
}

double vec::get_x() const { return v_.x; };

double vec::get_y() const { return v_.y; };

double vec::norm() const { return sqrt(v_.x * v_.x + v_.y * v_.y); }

void vec::update_x(double const z) { v_.x = z; }

void vec::update_y(double const z) { v_.y = z; }

std::ostream &operator<<(std::ostream &os, vec const &v_) {
  os << '(' << v_.get_x() << ',' << v_.get_y() << ')';
  return os;
}

vec operator+(vec const &a, vec const &b) {
  return vec{a.get_x() + b.get_x(), a.get_y() + b.get_y()};
}

vec operator-(vec const &a, vec const &b) {
  return vec{a.get_x() - b.get_x(), a.get_y() - b.get_y()};
}

vec operator*(vec const &a, double const b) {
  return vec{b * a.get_x(), b * a.get_y()};
}

vec operator*(double const b, vec const &a) {
  return vec{b * a.get_x(), b * a.get_y()};
}

vec operator/(vec const &a, double const b) {
  if (b == 0.) {
    throw std::runtime_error{"Cannot divide by zero."};
  }
  return vec{a.get_x() / b, a.get_y() / b};
}

bool operator==(vec const &a, vec const &b) {
  return a.get_x() == b.get_x() && a.get_y() == b.get_y();
}
