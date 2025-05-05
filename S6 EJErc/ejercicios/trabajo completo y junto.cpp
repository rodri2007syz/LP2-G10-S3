#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <limits> 

using namespace std;

class Estudiante {
private:
    string nom;
    string cod;
    vector<float> notas;
    float promedio;
    void calcularPromedio() {
        if (notas.empty()) {
            promedio = 0.0f;
            return;
        }

        float suma = 0.0f;
        for (float nota : notas) {
            suma += nota;
        }
        promedio = suma / notas.size();
    }

public:

    Estudiante() : nom(""), cod(""), promedio(0.0f) {}

    Estudiante(string nombre, string codigo)
        : nom(nombre), cod(codigo), promedio(0.0f) {}

    void agregarNota(float nota) {
        notas.push_back(nota);
        calcularPromedio();
    }

    void mostrarInformacion() const {
        cout << "\nInformacion del Estudiante" << endl;
        cout << "Nombre: " << nom << endl;
        cout << "Codigo: " << cod << endl;
        cout << "Notas: ";
        for (float nota : notas) {
            cout << fixed << setprecision(2) << nota << " ";
        }
        cout << "\nPromedio: " << fixed << setprecision(2) << promedio << endl;
    }

    float obtenerPromedio() const {
        return promedio;
    }
    string obtenerCodigo() const {
        return cod;
    }
    string obtenerNombre() const {
        return nom;
    }
};

class Grupo {
private:
    vector<Estudiante> alumnos;
    int cantidad;

public:
    Grupo(int can) : cantidad(can) {
        cout << "El grupo se ha creado con una capacidad maxima de " << cantidad << endl;
        alumnos.reserve(cantidad);
    }

    void agregarAlumno(const string& nombre, const string& codigo) {
        if (alumnos.size() < static_cast<size_t>(cantidad)) {
            Estudiante nuevoAlumno(nombre, codigo);
            alumnos.push_back(nuevoAlumno);
            cout << "Alumno: " << nombre << " (Codigo: " << codigo << ") se agrego a la lista." << endl;
            cout << "Tamaño actual del grupo: " << alumnos.size() << endl;
        } else {
            cout << "La lista de alumnos ha alcanzado su capacidad maxima." << endl;
        }
    }

    Estudiante* obtenerAlumno(const string& codigo) {
        for (auto& alumno : alumnos) {
            if (alumno.obtenerCodigo() == codigo) {
                return &alumno;
            }
        }
        return nullptr;
    }

    void mostrarAlumnos() const {
        if (alumnos.empty()) {
            cout << "La lista de alumnos esta vacia. Ingrese alumnos." << endl;
            return;
        }

        cout << "\nLISTA DE ALUMNOS EN EL GRUPO" << endl;
        for (size_t i = 0; i < alumnos.size(); ++i) {
            cout << (i + 1) << "==> " << alumnos[i].obtenerNombre() << " (Codigo: " << alumnos[i].obtenerCodigo() << ")" << endl;
        }
    }

    // Método para calcular el promedio de los promedios de los alumnos
    float calcularPromedioDePromedios() const {
        if (alumnos.empty()) {
            cout << "La lista de alumnos esta vacia. No se puede calcular el promedio de promedios." << endl;
            return 0.0f;
        }
        float sumaDePromedios = 0.0f;
        for (const auto& alumno : alumnos) {
            sumaDePromedios += alumno.obtenerPromedio();
        }
        return sumaDePromedios / alumnos.size();
    }

    // mejor alumno promedios
    Estudiante* obtenerMejorPromedio() const {
        if (alumnos.empty()) {
            cout << "La lista de alumnos esta vacia. No hay alumnos para comparar promedios." << endl;
            return nullptr;
        }

        Estudiante* mejorAlumno = nullptr;
        float mejorPromedio = numeric_limits<float>::lowest();

        for (const auto& alumno : alumnos) {
            if (alumno.obtenerPromedio() > mejorPromedio) {
                mejorPromedio = alumno.obtenerPromedio();
                mejorAlumno = const_cast<Estudiante*>(&alumno);
            }
        }
        return mejorAlumno;
    }
};

int main() {
    Grupo grupo1(3);

    grupo1.agregarAlumno("Juan Perez", "2023001");
    grupo1.agregarAlumno("Maria Lopez", "2023002");
    grupo1.agregarAlumno("Carlos Diaz", "2023003");

    Estudiante* juan = grupo1.obtenerAlumno("2023001");
    if (juan != nullptr) {
        juan->agregarNota(15.5f);
        juan->agregarNota(16.0f);
        juan->agregarNota(14.5f);
    }

    Estudiante* maria = grupo1.obtenerAlumno("2023002");
    if (maria != nullptr) {
        maria->agregarNota(18.0f);
        maria->agregarNota(17.5f);
    }

    Estudiante* carlos = grupo1.obtenerAlumno("2023003");
    if (carlos != nullptr) {
        carlos->agregarNota(12.0f);
        carlos->agregarNota(13.5f);
    }

    grupo1.mostrarAlumnos();

    cout << "\nInformacion individual de los estudiantes:" << endl;
    if (juan != nullptr) juan->mostrarInformacion();
    if (maria != nullptr) maria->mostrarInformacion();


    //promedios de los promedios
    float promedioDePromedios = grupo1.calcularPromedioDePromedios();
    cout << "\nPromedio de los promedios del grupo: " << fixed << setprecision(2) << promedioDePromedios << endl;

    //mejor promedio
    Estudiante* mejorEstudiante = grupo1.obtenerMejorPromedio();
    if (mejorEstudiante != nullptr) {
        cout << "\nEl alumno con el mejor promedio es:" << endl;
        mejorEstudiante->mostrarInformacion();
    }

    return 0;
}