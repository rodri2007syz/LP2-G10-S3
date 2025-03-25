#include "libro.h"

#include <iostream>
#include <string>
using namespace std;


int main() { // titulo - autor - genero
    Libro libro1("1984", "George Orwell", "Ciencia ficción");


    cout << "Información inicial de los libros:" << endl;
    libro1.mostrarInfoLibro();


    // Modificar atributos usando set
    libro1.setTitulo("El amor en los tiempos del cólera");


    // Mostrar información actualizada de los libros
    cout << "\nInformación actualizada de los libros:" << endl;
    libro1.mostrarInfoLibro();


    // Acceder a atributos usando get
    cout << "Acceso a atributos usando get:" << endl;
    cout << "Titulo del libro 1: " << libro1.getTitulo() << endl;
 

    return 0;
}