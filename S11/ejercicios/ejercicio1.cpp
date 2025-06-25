#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string nombreArchivo;


    cout << "Ingresa el nombre del archivo de texto ( miarchivo.txt): ";
    getline(cin, nombreArchivo);

    ifstream archivo(nombreArchivo);


    if (archivo.is_open()) {
        string linea;
        cout << "\n--- Contenido de '" << nombreArchivo << "' ---" << endl;

        while (getline(archivo, linea)) {
            cout << linea << endl;
        }
        cout << "---------------------------------------" << endl;
        archivo.close();
    } else {

        cerr << "Error: No se pudo abrir el archivo '" << nombreArchivo << "'. "<< "Asegúrate de que el archivo exista y tengas los permisos necesarios." << endl;
    }

    return 0;
}