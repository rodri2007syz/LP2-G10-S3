#ifndef PROYECTO_H
#define PROYECTO_H

#include "IEntidadGestionable.h"

class Proyecto : public IEntidadGestionable {
private:
    string nombre;
    string descripcion;
    int fechaInicio;
    int fechaFin;

public:
    Proyecto(const string& nom, const string& desc, int inicio, int fin)
        : nombre(nom), descripcion(desc), fechaInicio(inicio), fechaFin(fin) {
    }

    void mostrarDetalles() const override {
        cout << " Proyecto: " << nombre << "\n Descripcion: " << descripcion
            << "\n Inicio: " << fechaInicio << " - Fin: " << fechaFin << endl;
    }
};

#endif