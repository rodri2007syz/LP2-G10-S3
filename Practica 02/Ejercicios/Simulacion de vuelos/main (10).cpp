#include "clasesavion.h"
#include <iostream>

using namespace std;

int main() {
    int des = 4, valav = 0, trip, dur;
    string mod, mis, dest;
    double capcomb, consh;
    Avion* avion1 = nullptr;

    while (des > 3) {
        cout << "Menu:\n1. Introducir avión\n2. Introducir misión (Simulación) [Primero introduzca un avión]\n3. Salir" << endl;
        cin >> des;

        if (des == 1) {
            valav += 1;
            cout << "Introduzca el modelo del avión: " << endl;
            cin >> mod;

            capcomb = -1;
            while (capcomb < 0) {
                cout << "Introduzca la capacidad de combustible del avión: " << endl;
                cin >> capcomb;
            }

            consh = -1;
            while (consh < 0) {
                cout << "Introduzca el consumo por hora del avión: " << endl;
                cin >> consh;
            }

            avion1 = new Avion(mod, capcomb, consh);
            cout << "Avión registrado exitosamente =)" << endl;
            des = 4;
        }

        if (des == 2) {
            if (valav == 0) {
                cout << "Ingrese un avión primero" << endl;
                des = 4;
            } else {
                cout << "Ingrese el nombre de la misión: " << endl;
                cin >> mis;

                cout << "Ingrese el destino del vuelo: " << endl;
                cin >> dest;

                trip = dur = -1;
                while (trip < 0) {
                    cout << "Ingrese la tripulación que abordará el avión: " << endl;
                    cin >> trip;
                }

                while (dur < 0) {
                    cout << "Ingrese la duración del vuelo (horas): " << endl;
                    cin >> dur;
                }

                Mision mision1(trip, dur, mis, dest, avion1);
                mision1.planificarmision();
                mision1.ejecutarmision();
            }
        }

        if (des == 3) {
            cout << "Saliendo del programa..." << endl;
            break;
        }
    }

    if (avion1 != nullptr) {
        delete avion1;
    }

    return 0;
}
