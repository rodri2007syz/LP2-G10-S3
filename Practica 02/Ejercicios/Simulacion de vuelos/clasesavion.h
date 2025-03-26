#ifndef CLASESAVION_H
#define CLASESAVION_H

#include <iostream>
using namespace std;

class Avion {
private:
    string modelo;
    double capacidadcomb, consumoh;

public:
    Avion(string _modelo, double _capacidadcomb, double _consumoh) {
        modelo = _modelo;
        capacidadcomb = _capacidadcomb;
        consumoh = _consumoh;
    }

    void setmodelo(string _modelo) { modelo = _modelo; }
    void setcapacidad(double _capacidadcomb) { capacidadcomb = _capacidadcomb; }
    void setconsumo(double _consumoh) { consumoh = _consumoh; }

    string getmodelo() { return modelo; }
    double getcapacidad() { return capacidadcomb; }
    double getconsumo() { return consumoh; }

    bool combustiblesuficiente(double duracion) {
        return capacidadcomb >= duracion * consumoh;
    }
};

class Mision {
private:
    int tripulacion;
    double duracion;
    string mision, destino;
    Avion* avionasignado;

public:
    Mision(int _tripulacion, double _duracion, string _mision, string _destino, Avion* _avion) {
        tripulacion = _tripulacion;
        duracion = _duracion;
        mision = _mision;
        destino = _destino;
        avionasignado = _avion;
    }

    void settripulacion(int _tripulacion) {
        if (_tripulacion > 0) {
            tripulacion = _tripulacion;
        } else {
            cout << "Número de tripulación inválido" << endl;
        }
    }

    void setduracion(double _duracion) { duracion = _duracion; }
    void setmision(string _mision) { mision = _mision; }
    void setdestino(string _destino) { destino = _destino; }

    int gettripulacion() { return tripulacion; }
    double getduracion() { return duracion; }
    string getmision() { return mision; }
    string getdestino() { return destino; }

    void planificarmision() {
        cout << "Planificación de la misión: " << mision << " hacia -> " << destino << endl;
    }

    void ejecutarmision() {
        cout << "Ejecutando misión: " << mision << ", hacia: " << destino << endl;
        cout << "Duración: " << duracion << ", Tripulación: " << tripulacion << endl;

        if (avionasignado->combustiblesuficiente(duracion)) {
            cout << "El avión " << avionasignado->getmodelo() << " tiene combustible suficiente, Misión Exitosa =)" << endl;
        } else {
            cout << "El avión no tiene combustible suficiente, Misión Fallida =(" << endl;
        }
    }
};

#endif
