#include "tienda.h"

#include <iostream>
#include <string>
using namespace std;



int main() {
    
    Tienda tiendaRopa("ModaRP", "Calle USA 123", "Tienda de ropa");
    Tienda tiendaElectronica("Tech World", "cb456", "Tienda de electronicos");

    // Mostrar informacion inicial de las tiendas
    cout << "Informacion inicial de las tiendas:" << endl;
    tiendaRopa.mostrarInformacion();
    tiendaElectronica.mostrarInformacion();

    // Agregar productos al stock
    tiendaRopa.agregarProducto(10);
    tiendaElectronica.agregarProducto(5);

    // Vender productos
    tiendaRopa.venderProducto();
    tiendaElectronica.venderProducto();

    tiendaRopa.venderProducto();
    tiendaElectronica.venderProducto();

    //info actualizada
    cout << "\nInformacion actualizada de las tiendas:" << endl;
    tiendaRopa.mostrarInformacion();
    tiendaElectronica.mostrarInformacion();

    return 0;
}