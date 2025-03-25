#include "CAnimal.h" 

#include <iostream>
#include <string>
using namespace std;

int main() // nombre - tipo - edad
{
    Animal perro("Hachico", "perro", 3);
    
    
    perro.mostrarinfo();
    
    perro.hacerRuido();
    
    perro.alimentar();

    
}