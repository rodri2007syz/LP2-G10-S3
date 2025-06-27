#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

struct Contacto {
    string nombre;
    string telefono;
    string email;

    Contacto(string n = "", string t = "", string e = "")
        : nombre(std::move(n)), telefono(std::move(t)), email(std::move(e)) {}
};

void clearInputBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void mostrarMenuContactos() {
    cout << "\n--- REGISTRO DE CONTACTOS ---" << endl;
    cout << "1. Agregar nuevo contacto" << endl;
    cout << "2. Buscar contacto por nombre" << endl;
    cout << "3. Actualizar informacion de contacto" << endl;
    cout << "4. Mostrar todos los contactos (alfabeticamente)" << endl;
    cout << "5. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

int main() {
    vector<Contacto> agenda;
    int opcion;

    do {
        mostrarMenuContactos();
        cin >> opcion;
        clearInputBuffer();

        switch (opcion) {
            case 1: {
                cout << "\n--- AGREGAR CONTACTO ---" << endl;
                string nombre, telefono, email;
                cout << "Ingrese nombre: ";
                getline(cin, nombre);

                auto it_existente = find_if(agenda.begin(), agenda.end(),
                                             [&](const Contacto& c) { return c.nombre == nombre; });
                if (it_existente != agenda.end()) {
                    cout << "Error: Ya existe un contacto con ese nombre." << endl;
                    break;
                }

                cout << "Ingrese telefono: ";
                getline(cin, telefono);
                cout << "Ingrese correo electronico: ";
                getline(cin, email);

                agenda.emplace_back(nombre, telefono, email);
                cout << "Contacto '" << nombre << "' agregado correctamente." << endl;
                break;
            }
            case 2: {
                cout << "\n--- BUSCAR CONTACTO ---" << endl;
                cout << "Ingrese el nombre del contacto a buscar: ";
                string nombreBuscar;
                getline(cin, nombreBuscar);

                auto it = find_if(agenda.begin(), agenda.end(),
                                 [&](const Contacto& c) { return c.nombre == nombreBuscar; });

                if (it != agenda.end()) {
                    cout << "--- CONTACTO ENCONTRADO ---" << endl;
                    cout << "Nombre: " << it->nombre << endl;
                    cout << "Telefono: " << it->telefono << endl;
                    cout << "Email: " << it->email << endl;
                } else {
                    cout << "Contacto '" << nombreBuscar << "' no encontrado." << endl;
                }
                break;
            }
            case 3: {
                cout << "\n--- ACTUALIZAR CONTACTO ---" << endl;
                cout << "Ingrese el nombre del contacto a actualizar: ";
                string nombreActualizar;
                getline(cin, nombreActualizar);

                auto it = find_if(agenda.begin(), agenda.end(),
                                 [&](const Contacto& c) { return c.nombre == nombreActualizar; });

                if (it != agenda.end()) {
                    cout << "Contacto encontrado: " << it->nombre << endl;
                    cout << "Ingrese nuevo telefono (deje vacio para no cambiar): ";
                    string nuevoTelefono;
                    getline(cin, nuevoTelefono);
                    if (!nuevoTelefono.empty()) {
                        it->telefono = nuevoTelefono;
                    }

                    cout << "Ingrese nuevo correo electronico (deje vacio para no cambiar): ";
                    string nuevoEmail;
                    getline(cin, nuevoEmail);
                    if (!nuevoEmail.empty()) {
                        it->email = nuevoEmail;
                    }
                    cout << "Informacion de contacto actualizada." << endl;
                } else {
                    cout << "Contacto '" << nombreActualizar << "' no encontrado." << endl;
                }
                break;
            }
            case 4: {
                cout << "\n--- LISTA DE CONTACTOS ---" << endl;
                if (agenda.empty()) {
                    cout << "La agenda esta vacia." << endl;
                } else {
                    sort(agenda.begin(), agenda.end(),
                              [](const Contacto& a, const Contacto& b) {
                                  return a.nombre < b.nombre;
                              });

                    for (const auto& contacto : agenda) {
                        cout << "Nombre: " << contacto.nombre
                             << ", Telefono: " << contacto.telefono
                             << ", Email: " << contacto.email << endl;
                    }
                }
                break;
            }
            case 5: {
                cout << "Saliendo del programa de registro de contactos. ¡Hasta luego!" << endl;
                break;
            }
            default: {
                cout << "Opcion no valida. Por favor, intente de nuevo." << endl;
                break;
            }
        }
    } while (opcion != 5);

    return 0;
}