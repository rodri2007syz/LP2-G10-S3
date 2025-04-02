#include "proyectos.h"
#include "Comentario.h"
#include "Archivo.h"
#include "GestorTareas.h"
#include <iostream>
using namespace std;

int main() {
    string nproy = " ", descproy = "", com = "", archg, rut;
    int fechain, fechater, des = 0, a = 0, des2 = -1;

    GestorTareas gestor;
    Proyecto* proyecto1 = nullptr;
    Comentario* comentario = nullptr;
    Archivo* archivo = nullptr;
    while (true) {  
        cout << "menu : \n que desea hacer? \n 1. crear un proyecto \n 2. hacer un comentario (obligatorio usar crear un proyecto) \n 3. guardar archivo \n 4. mostrar informacion \n 5. salir" << endl;
        cin >> des;

        if (des == 1) {
            a = 1;
            cout << "ingrese el nombre de su proyecto: " << endl;
            cin >> nproy;
            cout << "ingrese una descripcion del proyecto " << endl;
            cin >> descproy;
            cout << "ingrese la fecha de inicio de su proyecto" << endl;
            cin >> fechain;
            cout << "ingrese la fecha de finalizacion de su proyecto" << endl;
            cin >> fechater;

            proyecto1 = new Proyecto(nproy, descproy, fechain, fechater);
            gestor.agregarEntidad(proyecto1);

           
            cout << "proyecto agregado correctamente.\n";
            continue;  
        }
        else if (des == 2) {
            if (a >= 1) {
                cout << "ingrese un comentario :" << endl;
                cin >> com;
                comentario = new Comentario(com);
                gestor.agregarEntidad(comentario);
                cout << "comentario agregado correctamente.\n";
            }
            else {
                cout << "debe crear un proyecto antes de comentar." << endl;
            }
            continue;
        }
        else if (des == 3) {
            if (a >= 1) {
                cout << "ingrese el nombre del archivo (escriba su terminacion (ejemplo.pdf) ) : " << endl;
                cin >> archg;
                cout << "ingrese la ruta del archivo (ejemplo/archivo/disco:c)" << endl;
                cin >> rut;
                archivo = new Archivo(archg, rut);
                gestor.agregarEntidad(archivo);
                cout << "archivo guardado correctamente.\n";
            }
            else {
                cout << "debe crear un proyecto antes de guardar archivos." << endl;
            }
            continue;
        }
        else if (des == 4) {
            while (true) {  
                cout << "que informacion desea que se muestre?: \n 1. mostrar info del proyecto registrado \n 2. mostrar comentarios \n 3. mostrar ruta de archivo \n 4. salir al menu anterior" << endl;
                cin >> des2;

                if (des2 == 1) {
                    if (proyecto1)
                        proyecto1->mostrarDetalles();
                    else
                        cout << "no hay proyectos registrados." << endl;
                }
                else if (des2 == 2) {
                    if (comentario)
                        comentario->mostrarDetalles();
                    else
                        cout << "no hay comentarios registrados." << endl;
                }
                else if (des2 == 3) {
                    if (archivo)
                        archivo->mostrarDetalles();
                    else
                        cout << "no hay archivos registrados." << endl;
                }
                else if (des2 == 4) {
                    break; 
                }
            }
            continue;
        }
        else if (des == 5) {
            cout << "saliendo del programa..." << endl;
            break;  
        }
}


}