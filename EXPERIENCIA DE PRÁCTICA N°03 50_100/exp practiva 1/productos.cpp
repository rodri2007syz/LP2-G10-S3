#include <iostream>
#include <stdlib.h>
using namespace std;

class Productos{
    private:
    string NombreProducto;
    double Precio;
    int CantidadDisponible;

    public:
    Productos(string nombreP, double precioP, int cantidadDP){
        NombreProducto = nombreP;
        Precio = precioP;
        CantidadDisponible = cantidadDP;
    }
};

class Pedido{
    private:
    string NombrePs;
    int CantidadSl;

};

