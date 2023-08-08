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
#include<iostream>
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