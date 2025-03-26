#include <iostream>
#include <string>
using namespace std;

class Persona {
private:
    string dni; // Atributo privado
    int edad;   // Atributo privado

public:
    // Atributos publicos
    string nombre;
    string apellido;

    // Constructor
    Persona(string nom, string ape, string d, int e)
        : nombre(nom), apellido(ape), dni(d), edad(e) {}

    // Metodos get para atributos privados
    string getDNI() const {
        return dni;
    }

    int getEdad() const {
        return edad;
    }

    // Metodos set para atributos privados
    void setDNI(string d) {
        dni = d;
    }

    void setEdad(int e) {
        if (e >= 0) { // Validar que la edad no sea negativa
            edad = e;
        } else {
            cout << "Error: La edad no puede ser negativa." << endl;
        }
    }

    // Metodo para mostrar la informacion de la persona
    void mostrarInformacion() const {
        cout << "Informacion de la persona:" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Apellido: " << apellido << endl;
        cout << "DNI: " << dni << endl;
        cout << "Edad: " << edad << endl;
        cout << "-----------------------" << endl;
    }
};
