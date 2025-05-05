#include <iostream>
#include <vector>
#include <iomanip>
#include <string> 

using namespace std;

class Estudiante{
private:
    string nom;
    string cod;
    vector<float> notas;
    float promedio;
    void calcularPromedio() {
        if (notas.empty()){
            promedio = 0.0f;
            return;
        }

        float suma = 0.0f;
        for (float nota : notas){
            suma += nota;
        }
        promedio = suma / notas.size();
    }

public:

    Estudiante() : nom(""), cod (""), promedio(0.0f) {}

    Estudiante(string nombre, string codigo)
    : nom(nombre), cod(codigo), promedio(0.0f) {}

    void agregarNota(float nota) { 
        notas.push_back(nota);
        calcularPromedio();
    }

    void mostrarInformacion() const {
        cout << "\nInformación del Estudiante" << endl;
        cout << "Nombre: " << nom << endl;
        cout << "Código: " << cod << endl;
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

int main() {
    Estudiante est1("Juan Perez", "2023001");
    est1.agregarNota(15.5f);
    est1.agregarNota(16.0f);
    est1.agregarNota(14.5f);

    est1.mostrarInformacion();

    Estudiante est2("Maria Lopez", "2023002");
    est2.agregarNota(18.0f);
    est2.agregarNota(17.5f);

    cout << "\nComparacion de promedios:" << endl;
    cout << est1.obtenerNombre() << ": " << est1.obtenerPromedio() << endl;
    cout << est2.obtenerNombre() << ": " << est2.obtenerPromedio() << endl;

    if (est1.obtenerPromedio() > est2.obtenerPromedio()) {
        cout << est1.obtenerNombre() << " tiene mejor promedio" << endl;
    } else if (est2.obtenerPromedio() > est1.obtenerPromedio()) {
        cout << est2.obtenerNombre() << " tiene mejor promedio" << endl;
    } else {
        cout << "Ambos estudiantes tienen el mismo promedio" << endl;
    }

    return 0;
}