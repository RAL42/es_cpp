template<class T> //il concetto ( / tipo (?) )Incrementable è un tipo su cui posso fare  ++t
concept Incrementable = requires(T t) {++t; };

template<Incrementable T> //il metodo advance si può instanziare solo con un tipo che soddisfa il concetto "Incrementable"
auto advance (T& t) {++t; }

int i{};
advance(i); // va bene prche i è un modello di Incrementable

struct S{};
S s;
advance(s); //errore, s non è di "tipo" Incrementble

//oppure

/*

template<class T>
concept Incrementable = requires(T t) {++t; };

auto advance (Incrementable auto& t) {++t; }

int i{};
advance(i); // va bene prche i è un modello di Incrementable

struct S{};
S s;
advance(s); //errore, s non è di "tipo" Incrementble

*/

// TUTTI GLI ALGORITMI : !cpp algorithm