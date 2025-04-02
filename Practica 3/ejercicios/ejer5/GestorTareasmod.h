// GestorTareas.h (modificado)
#ifndef GESTOR_TAREAS_H
#define GESTOR_TAREAS_H

#include "Tarea.h"
#include "Notificable.h"
#include <vector>

using namespace std;

class GestorTareas {
private:
    vector<Tarea*> tareas;

public:
    void agregarTarea(Tarea* tarea) {
        tareas.push_back(tarea);
    }

    void notificarTareas() {
        for (auto tarea : tareas) {
            if (notificable) {
                notificable->notificar();
            }
        }
    }

    void mostrarTareas() const {
        for (const auto& tarea : tareas) {
            tarea->mostrarInfo();
        }
    }
};

#endif
