#include "Coche.h" 

#include <iostream>
#include <string>
using namespace std;

int main() // modelo - anio 
{
    Coche coche1("Toyota corolla", 2019);
    Coche coche2("Ford", 2021);

    //informacion de los veiculos
    coche1.informacionVi();
    coche2.informacionVi();
    
    coche1.acelerar(80);
    coche2.acelerar(30);
    
    coche1.frenar(30);
    
    coche1.informacionVi();
    coche2.informacionVi();
    
    return 0;
}