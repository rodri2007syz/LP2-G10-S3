#include <iostream>
#include <string>
using namespace std;

const int CanTrabajadores = 5;

// Clase Trabajador
class Trabajador {
private:
    string nombre;
    int edad;
    Trabajador* compañeros[CanTrabajadores];
    int numCompaneros;

public:
    Trabajador(string nombre, int edad) : nombre(nombre), edad(edad), numCompaneros(0) {}

    string getNombre() {
        return nombre;
    }

    int getEdad() {
        return edad;
    }

    // agregar compañero
    void agregarCompanero(Trabajador* trabajador) {
        if (numCompaneros < CanTrabajadores) {
            compañeros[numCompaneros] = trabajador;
            numCompaneros++;
        } else {
            cout << "Capacidad máxima alcanzada." << endl;
        }
    }

    void mostrarCompaneros() {
        cout << "Compañeros de trabajo de " << nombre << ": " << endl;
        for (int i = 0; i < numCompaneros; i++) {
            cout << "  - " << compañeros[i]->getNombre() << " (Edad: " << compañeros[i]->getEdad() << ")" << endl;
        }
    }
};

// Clase Gerente que hereda de Trabajador
class Gerente : public Trabajador {
private:
    Trabajador* trabajadoresACargo[CanTrabajadores];
    int numTrabajadores;

public:
    Gerente(string nombre, int edad) : Trabajador(nombre, edad), numTrabajadores(0) {}

    // Método para agregar un trabajador a cargo
    void agregarTrabajadorACargo(Trabajador* trabajador) {
        if (numTrabajadores < CanTrabajadores) {
            trabajadoresACargo[numTrabajadores] = trabajador;
            numTrabajadores++;
        } else {
            cout << "No se pueden agregar más trabajadores a cargo" << endl;
        }
    }

    void mostrarTrabajadoresACargo() {
        cout << "Trabajadores a cargo de " << getNombre() << ": " << endl;
        for (int i = 0; i < numTrabajadores; i++) {
            cout << "  - " << trabajadoresACargo[i]->getNombre() << " (Edad: " << trabajadoresACargo[i]->getEdad() << ")" << endl;
            trabajadoresACargo[i]->mostrarCompaneros();  
        }
    }
};

int main() {
    Trabajador* t1 = new Trabajador("Juan ", 22);
    Trabajador* t2 = new Trabajador("Maria ", 20);
    Trabajador* t3 = new Trabajador("Carloz", 21);

    Gerente* g1 = new Gerente("Andres Martinez", 45);

    // relaciones entre compañeros de trabajo
    t1->agregarCompanero(t2);
    t1->agregarCompanero(t3);
    t2->agregarCompanero(t1);
    t3->agregarCompanero(t1);

    // establecer gerente
    g1->agregarTrabajadorACargo(t1);
    g1->agregarTrabajadorACargo(t2);
    g1->agregarTrabajadorACargo(t3);


    g1->mostrarTrabajadoresACargo();


    return 0;
}
