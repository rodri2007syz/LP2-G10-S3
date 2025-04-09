#include <iostream>
#include <string>
using namespace std;

// Definición de la constante para el tamaño máximo del arreglo de trabajadores
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

    // Método para agregar compañero de trabajo
    void agregarCompanero(Trabajador* trabajador) {
        if (numCompaneros < CanTrabajadores) {
            compañeros[numCompaneros] = trabajador;
            numCompaneros++;
        } else {
            cout << "No se pueden agregar más compañeros. Capacidad máxima alcanzada." << endl;
        }
    }

    // Método para mostrar los compañeros de trabajo
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
            cout << "No se pueden agregar más trabajadores a cargo. Capacidad máxima alcanzada." << endl;
        }
    }

    // Método para mostrar los trabajadores a cargo
    void mostrarTrabajadoresACargo() {
        cout << "Trabajadores a cargo de " << getNombre() << ": " << endl;
        for (int i = 0; i < numTrabajadores; i++) {
            cout << "  - " << trabajadoresACargo[i]->getNombre() << " (Edad: " << trabajadoresACargo[i]->getEdad() << ")" << endl;
            trabajadoresACargo[i]->mostrarCompaneros();  // Mostrar compañeros de trabajo del trabajador
        }
    }
};

int main() {
    // Crear instancias de trabajadores y gerente
    Trabajador* t1 = new Trabajador("Juan Perez", 30);
    Trabajador* t2 = new Trabajador("Maria Lopez", 25);
    Trabajador* t3 = new Trabajador("Carlos Gomez", 28);

    Gerente* g1 = new Gerente("Andres Martinez", 45);

    // Establecer relaciones entre compañeros de trabajo
    t1->agregarCompanero(t2);
    t1->agregarCompanero(t3);
    t2->agregarCompanero(t1);
    t3->agregarCompanero(t1);

    // Establecer trabajadores a cargo del gerente
    g1->agregarTrabajadorACargo(t1);
    g1->agregarTrabajadorACargo(t2);
    g1->agregarTrabajadorACargo(t3);

    // Mostrar información de los trabajadores y sus compañeros
    g1->mostrarTrabajadoresACargo();

    // Liberar memoria de las instancias creadas
    delete t1;
    delete t2;
    delete t3;
    delete g1;

    return 0;
}
