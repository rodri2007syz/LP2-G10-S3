#pragma once
#ifndef ARCHIVO_H
#define ARCHIVO_H

#include "IEntidadGestionable.h"

class Archivo : public IEntidadGestionable {
private:
    string nombreArchivo;
    string ruta;

public:
    Archivo(const string& nombre, const string& rutaArchivo)
        : nombreArchivo(nombre), ruta(rutaArchivo) {
    }

    void mostrarDetalles() const override {
        cout << "Archivo: " << nombreArchivo << "  Ruta: " << ruta << endl;
    }
};

#endif