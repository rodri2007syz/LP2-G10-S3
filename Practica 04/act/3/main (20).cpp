// main.cpp
#include <iostream>
#include "universidad.h"
#include <vector>

using namespace std;

int main() {
    vector<Estudiante> estudiantes;
    vector<Profesor> profesores;
    vector<Asignatura> asignaturas;
    int opcion;

    do {
        cout << "\n1. Registrar estudiante" << endl;
        cout << "2. Registrar profesor" << endl;
        cout << "3. Crear asignatura" << endl;
        cout << "4. Matricular estudiante" << endl;
        cout << "5. Registrar nota y faltas" << endl;
        cout << "6. Mostrar datos" << endl;
        cout << "0. Salir\nOpcion: ";
        cin >> opcion; cin.ignore();

        if (opcion == 1) {
            string nombre, direccion;
            int matricula;
            cout << "Nombre: "; getline(cin, nombre);
            cout << "Direccion: "; getline(cin, direccion);
            cout << "Matricula: "; cin >> matricula; cin.ignore();
            estudiantes.emplace_back(nombre, direccion, matricula);
            cout << "Estudiante registrado.\n";
        }
        else if (opcion == 2) {
            string nombre, direccion, telefono;
            cout << "Nombre: "; getline(cin, nombre);
            cout << "Direccion: "; getline(cin, direccion);
            cout << "Telefono: "; getline(cin, telefono);
            profesores.emplace_back(nombre, direccion, telefono);
            cout << "Profesor registrado.\n";
        }
        else if (opcion == 3) {
            if (profesores.empty()) {
                cout << "Registre un profesor primero.\n"; continue;
            }
            string codigo, nombre, descripcion;
            int profIdx;
            cout << "Codigo: "; getline(cin, codigo);
            cout << "Nombre: "; getline(cin, nombre);
            cout << "Descripcion: "; getline(cin, descripcion);
            cout << "Profesor:\n";
            for (size_t i = 0; i < profesores.size(); ++i)
                cout << i << ". " << profesores[i].nombre << endl;
            cout << "Seleccione el indice del profesor: "; cin >> profIdx; cin.ignore();
            if (profIdx >= 0 && profIdx < profesores.size()) {
                asignaturas.emplace_back(codigo, nombre, descripcion, &profesores[profIdx]);
                cout << "Asignatura creada.\n";
            } else {
                cout << "Indice de profesor invalido.\n";
            }
        }
        else if (opcion == 4) {
            if (estudiantes.empty() || asignaturas.empty()) {
                cout << "Faltan estudiantes o asignaturas.\n"; continue;
            }
            int estIdx, asigIdx;
            cout << "Estudiante:\n";
            for (size_t i = 0; i < estudiantes.size(); ++i)
                cout << i << ". " << estudiantes[i].nombre << endl;
            cout << "Seleccione el indice del estudiante: "; cin >> estIdx;
            cout << "Asignatura:\n";
            for (size_t i = 0; i < asignaturas.size(); ++i)
                cout << i << ". " << asignaturas[i].nombre << endl;
            cout << "Seleccione el indice de la asignatura: "; cin >> asigIdx; cin.ignore();
            if (estIdx >= 0 && estIdx < estudiantes.size() && asigIdx >= 0 && asigIdx < asignaturas.size()) {
                estudiantes[estIdx].matricular(&asignaturas[asigIdx]);
                cout << "Estudiante matriculado en la asignatura.\n";
            } else {
                cout << "Indices de estudiante o asignatura invalidos.\n";
            }
        }
        else if (opcion == 5) {
            if (estudiantes.empty()) {
                cout << "No hay estudiantes registrados.\n"; continue;
            }
            int estIdx, asigIdx;
            float nota;
            int faltas;
            cout << "Estudiante:\n";
            for (size_t i = 0; i < estudiantes.size(); ++i)
                cout << i << ". " << estudiantes[i].nombre << endl;
            cout << "Seleccione el indice del estudiante: "; cin >> estIdx;

            if (estIdx >= 0 && estIdx < estudiantes.size() && !estudiantes[estIdx].asignaturas.empty()) {
                cout << "Asignaturas matriculadas por " << estudiantes[estIdx].nombre << endl;
                for (size_t i = 0; i < estudiantes[estIdx].asignaturas.size(); ++i)
                    cout << i << ". " << estudiantes[estIdx].asignaturas[i]->nombre << endl;
                cout << "Seleccione el indice de la asignatura: "; cin >> asigIdx;

                if (asigIdx >= 0 && asigIdx < estudiantes[estIdx].asignaturas.size()) {
                    cout << "Nota: "; cin >> nota;
                    cout << "Faltas: "; cin >> faltas;
                    estudiantes[estIdx].registrarNota(asigIdx, nota);
                    estudiantes[estIdx].registrarFaltas(asigIdx, faltas);
                    cout << "Nota y faltas registradas.\n";
                } else {
                    cout << "Indice de asignatura invalido para este estudiante"<< endl;
                }
            } else {
                cout << "Indice de estudiante invalido o el estudiante no tiene asignaturas matriculadas"<< endl;
            }
            cin.ignore();
        }
        else if (opcion == 6) {
            for (const auto& est : estudiantes) {
                cout << "\nEstudiante: " << est.nombre << ", Matricula: " << est.matricula << endl;
                if (est.asignaturas.empty()) {
                    cout << "  No tiene asignaturas matriculadas"<< endl;
                } else {
                    for (size_t i = 0; i < est.asignaturas.size(); ++i) {
                        cout << "  Asignatura: " << est.asignaturas[i]->nombre
                             << ", Profesor: ";
                        if (est.asignaturas[i]->profesor) {
                            cout << est.asignaturas[i]->profesor->nombre;
                        } else {
                            cout << "Sin profesor asignado";
                        }
                        cout << ", Nota: " << est.notas[i]
                             << ", Faltas: " << est.asistencias[i] << endl;
                    }
                }
            }
            if (estudiantes.empty()) {
                cout << "No hay estudiantes para mostrar"<< endl;
            }
        }
        else if (opcion == 0) {
            cout << "salio correctamente"<< endl;
        }
        else {
            cout << "ingrese una opcion valida"<< endl;
        }

    } while (opcion != 0);

    return 0;
}