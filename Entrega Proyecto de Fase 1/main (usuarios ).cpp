#include <iostream>
#include <string>
#include "usuario.h"

using namespace std;

int main() {
   // Crear clientes
    UsuarioRegular persona1("Carlos", "carlosgos@.com", "1234d", 243544323, 15);
    UsuarioPremium persona2("Jeff", "appel@.com", "asdfasdasfa", 412312442, "Obsidiana", 15.5);
    
    //persona1.mostrarInfo();
    cout << "---------------------" << endl;
    persona2.mostrarInfo();
    cout << "---------------------" << endl;
    
    //recuperar contraseña
    // persona1.recuperarContrasena();
    // cout << "---------------------" << endl;
    
    
    // metodo de acumular puntos
    // persona1.acumularPuntos(20);
    // persona1.acumularPuntos(15);
    
    // persona1.mostrarInfo();
    
    
    //UsuarioPremium actu de membresia
    persona2.actMembresia("Diamante",30.0);
    
    persona2.mostrarInfo();
    
    
    return 0;
}