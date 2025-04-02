#pragma once
#ifndef IENTIDAD_GESTIONABLE_H
#define IENTIDAD_GESTIONABLE_H

#include <iostream>
using namespace std;

class IEntidadGestionable {
public:
    virtual void mostrarDetalles() const = 0;
    virtual ~IEntidadGestionable() = default;
};

#endif