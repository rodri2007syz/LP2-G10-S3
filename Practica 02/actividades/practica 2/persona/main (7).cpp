#include "dni.h"

#include <iostream>
#include <string>
using namespace std;


int main() {
    Persona persona1("Juan", "Perez", "12345678A", 25);
    Persona persona2("Maria", "Lopez", "87654321B", 30);

    cout << "Informacion inicial de las personas:" << endl;
    persona1.mostrarInformacion();
    persona2.mostrarInformacion();

    persona1.setDNI("98765432C");
    persona1.setEdad(26);

    persona2.setEdad(-5); 

    persona1.nombre = "Carlos";
    persona2.apellido = "Gomez";

    cout << "\nInformacion actualizada de las personas:" << endl;
    persona1.mostrarInformacion();
    persona2.mostrarInformacion();

    cout << "Acceso a atributos privados usando getters:" << endl;
    cout << "DNI de persona1: " << persona1.getDNI() << endl;
    cout << "Edad de persona2: " << persona2.getEdad() << endl;

    return 0;
}