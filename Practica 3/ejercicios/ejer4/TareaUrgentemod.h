//tarea urgente esta modificada aqui 

#ifndef TAREA_URGENTE_H
#define TAREA_URGENTE_H

#include "Tarea.h"
#include "Notificable.h"

using namespace std;

class TareaUrgente : public Tarea, public Notificable {
public:
    TareaUrgente(const string& titulo, const string& responsable, const string& fechaLimite)
        : Tarea(titulo, responsable, fechaLimite) {}

    void notificar() override {
        cout << "¡Alerta! La tarea urgente '" << titulo <<;
    }
};

#endif