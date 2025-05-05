#include <iostream>
using namespace std; 

class Alumno{
    private:
    string nombre;
    int codigo;
    float promedio;
    public:
    
    Alumno(string n_ , int cod_ , float prom_)
    : nombre(n_), codigo(cod_), promedio(prom_) {}
    
    Alumno (const Alumno& otro)
    : nombre(otro.nombre), codigo(otro.codigo), promedio(otro.promedio) {}
    
    void compararPromedio(const Alumno& otro) const {
        cout << nombre << " (" << promedio << ") ";
        
        if (promedio < otro.promedio) {
            cout << "tiene menor promedio que ";
        } 
        else if (promedio > otro.promedio) {
            cout << "tiene mayor promedio que ";
        } 
        else {
            cout << "tiene el mismo promedio que ";
        }
        
        cout << otro.nombre << " (" << otro.promedio << ")" << endl;
    }
    
    void mostrar() const {
        cout << "Alumno: "<< nombre <<" \n Codigo: "<< codigo << "Promedio "<< promedio << endl;
    }
};

int main(){
    Alumno alumno1("María García", 2023001, 16.5);
    Alumno alumno2("Carlos López", 2023002, 15.8);
    Alumno alumno3("Ana Martínez", 2023003, 16.5);

    cout << "\n Datos de los alumnos:" << endl;
    alumno1.mostrar();
    alumno2.mostrar();
    alumno3.mostrar();
    
    cout << "\nComparación de promedios: " << endl;
    alumno1.compararPromedio(alumno2);  
    alumno1.compararPromedio(alumno3);  
    alumno2.compararPromedio(alumno3);  

}