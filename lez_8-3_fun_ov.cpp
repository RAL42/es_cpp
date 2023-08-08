struct LessThan42 {
    auto operator() (int n) const {return n < 42; } //overload dell'operatore () (che sarebbe quindi una funzione)
};

int main(){
    auto lt42 = LessThan42{};  // analogo : LessThan42 lt42 = LessThan42{};
    return lt42.operator()(32);
}

//oppure

/*
struct LessThan42 {
    auto execute() (int n) const {return n < 42; }
}

int main(){
    auto lt42 = LessThan42{};
    return lt42.execute()(32);  //per capire... è un operatore e posso chiamarla come tale...
}
*/

// che quindi diventa 
//     ||
//     \/

auto f(){
    auto lt42 = LessThan42{};
    return lt42(32);         //... ma è anche una funzione e la posso chiamare come una funzione
};
