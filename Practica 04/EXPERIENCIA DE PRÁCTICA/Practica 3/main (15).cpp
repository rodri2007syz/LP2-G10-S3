#include <iostream>
#include <string>
using namespace std;

// Clase Estudiante
class Estudiante {
private:
    string nombre;
    int edad;

public:
    Estudiante(string nombre, int edad) : nombre(nombre), edad(edad) {}

    string getNombre() {
        return nombre;
    }

    int getEdad() {
        return edad;
    }
};

// Clase Docente
class Docente {
private:
    string nombre;
    string especialidad;

public:
    Docente(string nombre, string especialidad) : nombre(nombre), especialidad(especialidad) {}

    string getNombre() {
        return nombre;
    }

    string getEspecialidad() {
        return especialidad;
    }
};

// Clase Curso
class Curso {
private:
    string nombre;
    int codigo;

public:
    Curso(string nombre, int codigo) : nombre(nombre), codigo(codigo) {}

    string getNombre() {
        return nombre;
    }

    int getCodigo() {
        return codigo;
    }
};

// Clase Asociacion
class Asociacion {
private:
    Estudiante* estudiante;
    Docente* docente;
    Curso* curso;

public:
    Asociacion(Estudiante* estudiante, Docente* docente, Curso* curso)
        : estudiante(estudiante), docente(docente), curso(curso) {}

    void mostrarAsociacion() {
        cout << "Asociacion: " << endl;
        cout << "Estudiante: " << estudiante->getNombre() << " (Edad: " << estudiante->getEdad() << ")" << endl;
        cout << "Docente: " << docente->getNombre() << " (Especialidad: " << docente->getEspecialidad() << ")" << endl;
        cout << "Curso: " << curso->getNombre() << " (Codigo: " << curso->getCodigo() << ")" << endl;
    }
};

int main() {
    //Estudiantes, Docentes y Cursos
    Estudiante* est1 = new Estudiante("Juan Perez", 20);
    Estudiante* est2 = new Estudiante("Maria Lopez", 22);

    Docente* doc1 = new Docente("Dr. Garcia", "Matematica");
    Docente* doc2 = new Docente("Lic. Fernandez", "Historia");

    Curso* curso1 = new Curso("calculo", 101);
    Curso* curso2 = new Curso("Historia ", 202);

    // Asociacion entre docente estudiante 
    Asociacion* asoc1 = new Asociacion(est1, doc1, curso1);
    Asociacion* asoc2 = new Asociacion(est2, doc2, curso2);

    asoc1->mostrarAsociacion();
    asoc2->mostrarAsociacion();

    return 0;
}
