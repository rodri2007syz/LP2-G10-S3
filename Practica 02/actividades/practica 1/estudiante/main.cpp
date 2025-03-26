#include "estudiante.h"

#include <iostream>
#include <string>
using namespace std;


int main() { //nombre edad grado

    Estudiante estudiante1("Juan Perez", 15, "9no grado");
    Estudiante estudiante2("Maria López", 16, "10mo grado");

    //información
    cout << "Información inicial de los estudiantes:" << endl;
    estudiante1.mostrarInformacion();
    estudiante2.mostrarInformacion();

    // Simular examenes y calificaciones
    estudiante1.tomarExamen();
    estudiante1.recibirCalificacion(18.5);

    estudiante2.tomarExamen();
    estudiante2.recibirCalificacion(15.0);

    estudiante1.tomarExamen();
    estudiante1.recibirCalificacion(12.0);

    estudiante2.tomarExamen();
    estudiante2.recibirCalificacion(20.0);

    return 0;
}