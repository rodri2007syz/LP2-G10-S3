#ifndef GESTOR_TAREAS_H
#define GESTOR_TAREAS_H

#include "Tarea.h"
#include <vector>
using namespace std;

class GestorTareas;{
    private:
        vector<Tarea> tareas;
        
    public://agregarTarea -- mostrarTarea
        void agregarTarea(const Tarea& tarea){
            tareas.push_back(tarea);
        }
        void mostrarTarea() const {
            tarea.mostrarInfo}
    
}

    