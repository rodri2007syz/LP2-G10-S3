//clase tarea SRP
//cada clase tiene una unica responsabilidad
#ifndef TAREA_H
#define TAREA_H

#include <iostream>
#include <string>
using namespace std;

class Tarea{
private:
    
    string titulo;
    string responsable;
    string estado;
    string fechalimite;
    
public://titulo , fechalimite , responsable => estado = pendiente
    Tarea(const string titulo , const string responsable , const string fechalimite )
    : titulo(titulo) , responsable (responsable) , estado("Pendiente"), fechalimite(fechalimite){}
    
    
    
    //actualizarEstado -- mostrarInfo
    
    void actualizarEstado(const string& nuevoEstado ){
        estado = nuevoEstado;
    }
    
    void mostrarInfo() const{
        cout << "Tare :" << titulo << " Responsable :" << responsable << " Estado : " << estado << "Fecha Limite : " << fechalimite << endl;
        
    }
    
    #endif 
}