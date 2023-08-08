#include <iostream>
#include <vector>
#include<numeric>
#include<execution>
#include<algorithm>

int somma(std::vector<int> v) {
  /* dalle slide, con la conversione implicita (I esempio)

  for(int i = 0, n = v.size(); i != n; ++i) {
      auto const& w = v[i];
      sum += w;
  }
  */

  /* II esempio
  for(auto first = v.begin(), last = v.end(); first != last ; ++first)
  {
     auto const& w = *first;
     sum += w;
  }
  */

  /* III esempio
  for (auto const& w : v){ //la variabile w scorre tutti gli elementi del range, v
  sum+=w;
  }

  //oppure
  
  for (auto const& w : v) sum += w;
*/

// IV esempio (algoritmo, serve la libreria "numeric")

 auto sum =std::accumulate(v.begin(), v.end(), 0) ;//0 è il valore di partenza
 
  return sum;

}

/* codice presentato a lezione : fa vedere la conversione esplicita, siccome
vector.size() e (long) unsigned int mentre i è un int, non da warning ma
static_cast appesantisce il codice. In molti casi è meglio usare la conversione
implicita da unsigned int a int

auto f(std::vector<int> const& c){
    auto sum = 0;
    for (int i = 0; i != static_cast<int>(c.size()); ++i){
        auto const& v = c[i];
        sum += v;
    }
}
*/

void print(std::vector<int> v){
  //std::cout << "gli elementi del vettore " << std::name(v) << " sono : {" ; //devo trovare una funzione che stampi il nome del vettore, quando do in pasto il vettore
  bool first = true;
  for (int i = 0, n = v.size(); i != n; ++i) {
    if (first) {
      std::cout << v[i];
      first = false;
    } else {
      std::cout << ", " << v[i];
    }
  }
  first = true;
  std::cout << "}" <<std::endl<<"-----------------------"<<std::endl  ;
}


std::vector<int> v1{1, 5, 3, 69, 420};
std::vector<int> v2{};
int sum = 0;

int main() {
  // auto it = v1.begin() + v1.size() / 2;  // it è un iterator che punta a
  // quell'elemento del vettore. DEVE ESSERE DI TIPO ITERATOR v1.insert(it, 42);
  sum = somma(v1);
  std::cout <<"-----------------------"<<std::endl << "la somma degli elementi di v1 e : " << sum << std::endl;
  std::cout << "size of the vector v1 is: " << v1.size() << std::endl;
  std::cout << "gli elementi del vettore v1 sono : {" ;
  print(v1);

  int n;
  int q;
  std::cout <<std::endl<< "dammi il numero da aggiungere: ";
  std::cin >> q;
  std::cout << "in che posizione vuoi aggiungerlo? ";
  std::cin >> n;
  auto it = v1.begin() + n; //deve essere di tipo iterator, se facessi solo "n" sarebbe int
  v1.insert(it, q);         //ricorda che le posizioni iniziano dallo 0

  sum = somma(v1);

  std::cout <<"-----------------------"<<std::endl<< "ORA la somma degli elementi di v1 e : " << sum << std::endl;
  std::cout << "size of the vector v1 is: " << v1.size() << std::endl;
    std::cout << "gli elementi del vettore v1 sono : {" ;
  print(v1);

  std::partial_sum(std::begin(v1), std::end(v1), std::back_inserter(v2)); //riempie v2 con le somme parziali del vettore v1
  std::cout <<std::endl<< "gli elementi del vettore v2 sono : {" ;
  print(v2);

/*
std::sort(std::execution::par, v1.begin(), v1.end());      //sort ordina confrontando i numeri
auto it = std::find(std::execution::par, v1.begin(), v1.end(), 123);
*/

}  // main
