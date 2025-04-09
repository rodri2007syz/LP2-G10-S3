#ifndef UNIVERSIDAD_H
#define UNIVERSIDAD_H

#include <string>
#include <vector>
using namespace std;

class Asignatura;
class Profesor;

class Estudiante {
public:
    string nombre;
    string direccion;
    int matricula;
    
    vector<Asignatura*> asignaturas;
    vector<float> notas;
    vector<int> asistencias;

    Estudiante(string n, string d, int m);
    void matricular(Asignatura* a);
    void registrarNota(int index, float nota);
    void registrarFaltas(int index, int faltas);
};

class Profesor {
public:
    string nombre;
    string direccion;
    string telefono;
    vector<Asignatura*> asignaturas;

    Profesor(string n, string d, string t);
    void agregarAsignatura(Asignatura* a);
};

class Asignatura {
public:
    string codigo;
    string nombre;
    string descripcion;
    Profesor* profesor;

    Asignatura(string c, string n, string d, Profesor* p);
};

#endif
