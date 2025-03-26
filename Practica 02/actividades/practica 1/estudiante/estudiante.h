#include <iostream>
#include <string>
using namespace std;

class Estudiante {
private:
    string nombre;
    int edad;
    string grado;

public:
    // Constructor
    Estudiante(string nom, int ed, string grad)
        : nombre(nom), edad(ed), grado(grad) {}

    void tomarExamen() {
        cout << nombre << " está tomando un examen." << endl;
    }

    // calificacion
    void recibirCalificacion(float nota) {
        if (nota >= 0 && nota <= 20) {
            cout << nombre << " ha recibido una calificación de " << nota << "." << endl;
        } else {
            cout << "Error: La calificación debe estar entre 0 y 20." << endl;
        }
    }

  
    void mostrarInformacion() const {
        cout << "Información del estudiante:" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "Grado: " << grado << endl;
        cout << "-----------------------" << endl;
    }
};

