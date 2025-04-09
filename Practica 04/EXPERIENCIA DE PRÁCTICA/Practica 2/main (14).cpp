#include <iostream>
#include <string>
#include <vector>
using namespace std;

//clase Estudiante
class Estudiante {
private:
    string nombre;

public:
    Estudiante(string nombre) : nombre(nombre) {}

    string getNombre() {
        return nombre;
    }
};

// clase Curso
class Curso {
private:
    string nombre;
    int codigo;
    string descripcion;
    string fechaST;
    string fechaET;
    vector<Estudiante*> estudiantes; 

public:
    Curso(string nombre, int codigo, string descripcion = "NA", string fechaST = "", string fechaET = "")
        : nombre(nombre), codigo(codigo), descripcion(descripcion), fechaST(fechaST), fechaET(fechaET) {}

    void agregarEstudiantes(Estudiante* est) {
        estudiantes.push_back(est);
    }

    void eliminarEstudiante(int pos) {
        if (pos >= 0 && pos < estudiantes.size()) {
            estudiantes.erase(estudiantes.begin() + pos); // Eliminar del vector
            cout << "Estudiante eliminado." << endl;
        } else {
            cout << "Posición inválida." << endl;
        }
    }

    void mostrarEstudiantes() {
        cout << "Estudiantes en el curso: " << nombre << endl;
        for (auto est : estudiantes) {
            cout << "  - " << est->getNombre() << endl;
        }
    }
};

int main() {

    Estudiante* est1 = new Estudiante("Juan Perez");
    Estudiante* est2 = new Estudiante("Maria Lopez");

    Curso curso("Matematicas", 101);

    curso.agregarEstudiantes(est1);
    curso.agregarEstudiantes(est2);


    curso.mostrarEstudiantes();

    curso.eliminarEstudiante(0); // Eliminar al primer estudiante [0,1,2,3]

    curso.mostrarEstudiantes();

    // Liberar memoria
    delete est1;
    delete est2;

    return 0;
}
