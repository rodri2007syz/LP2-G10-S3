main:
#include "clases.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    string nombreJugador;
    int dif=1,vel;
    cout << "Ingrese el nombre del jugador: ";
    cin >> nombreJugador;

    Auto jugador(nombreJugador);
    Auto computadora("Computadora");
    while (dif < 4) {
        cout << " Eliga la dificultad \n 1. Facil \n 2. Medio \n 3. Dificil \n 4. Salir " << endl;
        cin >> dif;
        if (dif == 1) {
            Carrera carrera(50);
            vel = 11;
            while (vel > 10) {
                cout << "Escriba su velocidad ( limite 10 ) : " << endl;
                cin >> vel;
                Verificacion numero(vel);
                numero.validadorvelocidad(vel);
                if ((vel > 0) && (vel<=10)) {
                    jugador.setvelocidad(vel);
                    computadora.setvelocidad(rand() % 10 + 1);
                    carrera.iniciarCarrera(jugador, computadora);
                }
                if((vel<0) || (vel>10)){
                    cout << " EL numero excede el limite" << endl;
                    vel = 11;
                }   
            }
        }
        if (dif == 2) {
            Carrera carrera(100);
            vel = 21;
            while (vel > 20) {
                cout << " Escriba su velocidad ( limite 20) : " << endl;
                cin >> vel;
                Verificacion numero(vel);
                numero.validadorvelocidad(vel);
                if ((vel > 0) && (vel <= 20)) {
                    jugador.setvelocidad(vel);
                    computadora.setvelocidad(rand() % 20 + 15);
                    carrera.iniciarCarrera(jugador, computadora);
                }
                if ((vel < 0) || (vel > 20)) {
                    cout << " EL numero excede el limite" << endl;
                    vel = 21;
                }
            }
        }
        if (dif == 3) {
            Carrera carrera(500);
            vel = 31;
            while (vel > 30) {
                cout << " Escriba su velocidad (limite 30) : " << endl;
                cin >> vel;
                Verificacion numero(vel);
                numero.validadorvelocidad(vel);
                if ((vel > 0) && (vel <= 30)) {
                    jugador.setvelocidad(vel);
                    computadora.setvelocidad(rand() % 40 + 35);
                    carrera.iniciarCarrera(jugador, computadora);
                }
                if ((vel < 0) || (vel > 30)) {
                    cout << " EL numero excede el limite" << endl;
                    vel = 31;
                }
            }
        }
        if (dif == 4) {
            return dif = 5;
        }
            
    }
    
    return 0;
}