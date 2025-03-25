#include "factura.h"

#include <iostream>
#include <string>
using namespace std;


int main() { //numeroFac - descripcion - cantidad - precio por Unidad 
    
    Factura factura1("F001", "Laptop Gamer", 2, 12.50);
    Factura factura2("F002", "Teclado mecánico", 5, 75.99);

    cout << "Informacion de las facturas:" << endl;
    factura1.mostrarFactura();
    factura2.mostrarFactura();

    // modificar atributos usando set
    factura1.setCantidad(3);
    factura2.setPrecioUnitario(69.99);

    // info actualizada
    cout << "\nInformacion actualizada de las facturas:" << endl;
    factura1.mostrarFactura();
    factura2.mostrarFactura();

    // usando get
    cout << "Acceso a atributos usando get:" << endl;
    cout << "Numero de factura 1: " << factura1.getNumeroFactura() << endl;
    cout << "Descripcion de factura 2: " << factura2.getDescripcionArticulo() << endl;

    return 0;
}