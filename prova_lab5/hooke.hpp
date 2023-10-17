struct PPState {
  double m{};
  double x{};
  double v{};
};

class Hooke {
  double m_k;
  double m_l;

 public:
  Hooke(double k, double l);
  double operator()(PPState const& p1, PPState const& p2) const {};
};

int main() {
    Hooke hooke
}