#include <iostream>
#include <random>
#include <vector>

struct pos {
  // private:
  double _x;
  double _y;
};

struct vel {
  // private:
  double _vx;
  double _vy;
};

struct boid {
  // private:
  pos _s;
  vel _v;
};

std::ostream& operator<<(std::ostream& output,pos p)
{         
    output << "pos : {" << p._x << ", " << p._y << "}; ";
    return output;
}

std::ostream& operator<<(std::ostream& output, vel v) 
{
  output << "vel : {" << v._vx << " " << v._vy << "}";
  return output;
}

std::ostream& operator<<(std::ostream& output, boid b)  // se non metto & nell'argometno da errore; il primo dei 2 par.  è ciò che sta a sx di "<<" il secondo è ciò che sta a dx
{            
  output << " boid : {" << b._s << " " << b._v << "}" << '\n';
  return output;
}

int n = 3;                       // numero di boids
std::vector<boid> stormo;        // vettore di boid
std::default_random_engine gen;  // gen di numeri casuali

void print(std::vector<boid> v) {
   std::cout << "gli elementi del vettore sono :" << std::endl ;
  // //devo trovare una funzione che stampi il nome del vettore, quando do in
  // pasto il vettore
  bool first = true;
  for (int i = 0, n = v.size(); i != n; ++i) {
    if (first) {
      std::cout << v[i];
      first = false;
    } else {
      std::cout << v[i];
    }
  }
  first = true;
  std::cout << "-----------------------" << std::endl;
}

int main() {
  // esempio generatore numeri casuali (molto lento)
  /*int N;
  std::cout << "dammi un numero di numeri da generare" << std::endl;
  std::cin >> N;
  std::cout << std::endl;

  for (int n = 0; n != N; ++n) // genero N numeri casuali
  {
      int k = gen();

      while (k > 30)  // 30 è il limite superiore
      {
          k = gen();
      }
      std::cout << k << std::endl;
  }
*/
  for (int i = 0; i != n; ++i) {  // per generare boids casuali... da fare
    double x = gen();
    double y = gen();
    double z = gen();
    double t = gen();
    pos posi{x, y};
    vel veli{z, t};
    boid bi{posi, veli};

    stormo.push_back(bi);
  };
  print(stormo);
}