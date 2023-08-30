#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

const float gravity{9.81};

class particle {
  double x_;
  double v_;

 public:
  particle(double x, double v) : x_{x}, v_{v} {};
  ~particle(){};

  void applyG(double dt) { x_ = x_ + v_ * dt + gravity * dt * dt; }

  auto x() { return x_; }
  auto v() { return v_; }
    
};

int main() {
 

  double x{10};
  double v{};
  double dt{0.1};
  /*std::cout << "Inserisci x, v, dt ";
  std::cin >> x, v, dt;
  std::cout << '\n';
*/
  particle p1{x, v};
  v = gravity*dt;
  p1.applyG(dt);


  sf::RenderWindow window(sf::VideoMode(1000, 500), "finestra");
  window.setPosition(sf::Vector2i(100, 100));
  window.setVerticalSyncEnabled(true);
  window.setFramerateLimit(60);

  sf::CircleShape cerchio(30);
  cerchio.setPosition(50,p1.x());

  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }
    window.clear(sf::Color::White);
    window.draw(cerchio);
    window.display();
  }
}