#include<cassert>
#include<iostream>

int main(){
    /*  
    //  (I)
    int v=3;
    auto l=[&] {++v;};
    l();
    //return v;  //v==4
    assert(v==4);
    std::cout<<"v = "<<v<<std::endl;
    */ 
    
    //  (II)
    int v=3;
    auto l=[=] () mutable {++v;};
    l();
    // return v; //v==3 perche vado a modificare la variabile privata dentro la funzione creata dalla lamda expression
    std::cout<<"v = "<<v<<std::endl;
    
    /*
    //  (III) stessa cosa di (I)
    int v = 3;
    [&] {++v;} ();
    return v; 
    */
}