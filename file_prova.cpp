//TYPE CONVERSION
/*
#include <iostream>
void print(int a){
    std::cout<< "il numero e' = " << a << '\n';
}

int main(){
   /*float a;
    int b;
    std::cin>> a;
    print(a);
    std::cin>> b;
    print(b);*/

    //print(2);     //print 2
    //print(2.22);  //print 2

  // print(static_cast<int>(3.2));
//}

//-------------------------------------------------------------------------------------------------------------------


//INTRODUZIONE A IOSTREAM,  STD::GETLINE
/*
#include<iostream>
#include<string>

int main(){
    std::cout<<"SCRIVI UNA FRASE IN INPUT \n";
    std::string frase{};
    std::getline(std::cin, frase);  //argomento 1: da dove vuoi prendere la "linea" (sempre da cin); argomento 2: dove la vuoi salvare
    std::cout<<frase << " EZ \n";
    }*/

//-------------------------------------------------------------------------------------------------------------------

/*
#include<iostream>

int main(){
    int i = 1+2;
    std::cout<<i<<std::endl;    //prints 3
}*/

//-------------------------------------------------------------------------------------------------------------------

//SMALLEST OF N NUMBER con ciclo for
/*
#include<iostream>
int main(){
    int number;    //errore inizializzare number a 0, il risultato farà sempre 0 siccome pongo smallest=number
    int N{};

    std::cout<<"quanti numeri hai? \n"; 
    std::cin>>N;
    std::cout<<number<<'\n';

    int smallest = number;
    for(int i = 0; i < N; ++i){
        int variabile_cavia;
        std::cin>>variabile_cavia;

        if(variabile_cavia<smallest){
            smallest=variabile_cavia;
        }        
    };
    std::cout<<"il piu piccolo è: " << smallest << '\n';
}*/

//-------------------------------------------------------------------------------------------------------------------
//SMALLEST OF N NUMBER con ciclo while

/* #include<iostream>
int main(){
    int number;
    int N{};

    std::cout<<"quanti numeri hai? \n"; 
    std::cin>>N;

    int smallest;
    int i = 0;
    
    std::cout<<"Primo check "<<smallest<<'\n';        //primo check

    bool first_time=true;
    while(i < N){
        int variabile_cavia;
        std::cout<<"inserisci il numero \n";
        std::cin>>variabile_cavia;
        
        if(first_time){                 //per assegnare il primo valore che do in input alla variabile smallest, altrimenti è un numero qualsiasi (poiche non è inizializzata) 
            smallest=variabile_cavia;   //LO ESEGUE UNA VOLTA 
            first_time=false;
            std::cout<<"Secondo check "<<smallest<<'\n';        //secondo check
        };       
        if(variabile_cavia<smallest){
            smallest=variabile_cavia;
        };       
    ++i;
    };
    std::cout<<"il piu piccolo è: " << smallest << '\n';
}
*/

//-------------------------------------------------------------------------------------------------------------------

//FUNCTION
/*
#include<iostream>          //NOTA: LA FUNZIONE RITORNA UN INTERO
                            // NONOSTANTE IL RISULTATO SIA UN FLOAT. 
int myfun(float x){         //ARROTONDA per troncamento
    return x*x;
}

int main(){
    std::cout << myfun(3.1) << '\n';    //print 10
}
*/

//-------------------------------------------------------------------------------------------------------------------

//REFERENCE
/*
#include<iostream>
int main(){
  //  int a=3;
  //  std::cout<<&a<<'\n'; //print the position in memomry of a, in hexadecimal


   //   int a=4;
   // int* b= &a;
   // std::cout<<b<<'\n';

   // int i{33};
   // int& ri {i};
   // std::cout<< ri << '\n'; //print 33

   // ri==32 ? std::cout<<"cacca \n" : std::cout<<"pupu \n"; //prints pupu
    
   // ri=54;
   // std::cout<< ri << '\n'; //print 33
}*/

//-------------------------------------------------------------------------------------------------------------------

//STRUCT
/* #include<iostream>

struct Boid
{
    double pos;
    double vel;

};

void print_car(const Boid& boid){
    std::cout<<"Pass by ref \n";
    std::cout<<"posizione: "<< boid.pos << " ; velocita': " << boid.vel <<'\n';
}

void print_car(const Boid* ptr){
    std::cout<<"Pass by ptr \n";
    std::cout<<"posizione: "<< ptr->pos << " ; velocita': " << ptr->vel <<'\n';
}

int main() {
    Boid boid1{21.342, 34324.322};
    print_car(boid1);

    Boid* ptr_boid1 {&boid1};
    print_car(ptr_boid1);
}*/

//-------------------------------------------------------------------------------------------------------------------

//COPY CONSTRUCTOR
#include<iostream>

class Roba_a_caso {
    private:
    int a;
    int b;

    public:
    Roba_a_caso(int a_, int b_) : a{a_}, b{b_} {std::cout<<"Using normal constructor \n";}   //SENZA QUESTO NON POTREI INIZIALIZZARE "oggetto1",
                                                                                             // è UN CONSTRUTTORE (UNA FUNZIONE), è PUBBLICO E 
                                                                                             //POICHE "è DENTRO la classe" ha accesso ai membri PRIVATI 
    Roba_a_caso(Roba_a_caso& Elemento) : a{Elemento.a}, b{Elemento.b} {std::cout<<"Using Copy constructor \n";} 

void print(){
    std::cout<<"a = " << a << " ; b = " << b << '\n';
    }

};



int main(){
    Roba_a_caso oggetto1{12, 22};
    oggetto1.print();
    Roba_a_caso oggetto2{oggetto1};
    oggetto2.print();
}