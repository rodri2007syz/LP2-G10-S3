
//OCP Extensión sin modificar la clase base

#ifndef TAREA_URGENTE_H
#define TAREA_URGENTE_H

#include "Tarea.h"
using namespace std;

//TareaUrgente constr ---- notificacion
class TareaUrgente : public tarea{
    public:
    TareaUrgente(const string& titulo ,const string responsable, const string fechalimite)
    : Tarea (titulo,responsable,fechalimite ) {}
    
    void notificacion(){
        count << "revisar " << titulo << "urgentemente"
    }
};

#endif