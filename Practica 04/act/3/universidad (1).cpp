#include "universidad.h"

// estd
Estudiante::Estudiante(string n, string d, int m) {
    nombre = n;
    direccion = d;
    matricula = m;
}

void Estudiante::matricular(Asignatura* a) {
    asignaturas.push_back(a);
    notas.push_back(0);
    asistencias.push_back(0);
}

void Estudiante::registrarNota(int index, float nota) {
    if (index < notas.size()) notas[index] = nota;
}

void Estudiante::registrarFaltas(int index, int faltas) {
    if (index < asistencias.size()) asistencias[index] += faltas;
}

// prof
Profesor::Profesor(string n, string d, string t) {
    nombre = n;
    direccion = d;
    telefono = t;
}

void Profesor::agregarAsignatura(Asignatura* a) {
    asignaturas.push_back(a);
}

// asignaturas
Asignatura::Asignatura(string c, string n, string d, Profesor* p) {
    codigo = c;
    nombre = n;
    descripcion = d;
    profesor = p;
    p->agregarAsignatura(this);
}
