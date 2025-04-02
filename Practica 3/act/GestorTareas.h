#pragma once
#ifndef GESTOR_TAREAS_H
#define GESTOR_TAREAS_H

#include "IEntidadGestionable.h"
#include <vector>

class GestorTareas {
private:
    vector<IEntidadGestionable*> entidades;

public:
    void agregarEntidad(IEntidadGestionable* entidad) {
        entidades.push_back(entidad);
    }

    void mostrarEntidades() const {
        for (const auto& entidad : entidades) {
            entidad->mostrarDetalles();
        }
    }

    ~GestorTareas() {
        for (auto entidad : entidades) {
            delete entidad;
        }
    }
};

#endif