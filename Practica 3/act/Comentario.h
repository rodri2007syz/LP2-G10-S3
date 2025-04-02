 
#pragma once
#ifndef COMENTARIO_H
#define COMENTARIO_H

#include "IEntidadGestionable.h"

class Comentario : public IEntidadGestionable {
private:
    string texto;

public:
    Comentario(const string& txt) : texto(txt) {}

    void mostrarDetalles() const override {
        cout << " Comentario: " << texto << endl;
    }
};

#endif