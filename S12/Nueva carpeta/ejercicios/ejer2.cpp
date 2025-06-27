#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <limits>

using namespace std;

struct Evento {
    string nombre;
    string fecha;
    set<string> asistentes;

    Evento(string n = "", string f = "") : nombre(std::move(n)), fecha(std::move(f)) {}

    void agregarAsistente(const string& asistente) {
        asistentes.insert(asistente);
    }
};

void clearInputBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void mostrarMenuEventos() {
    cout << "\n--- ORGANIZACION DE EVENTOS ---" << endl;
    cout << "1. Agregar nuevo evento" << endl;
    cout << "2. Agregar asistentes a un evento" << endl;
    cout << "3. Mostrar asistentes de un evento" << endl;
    cout << "4. Buscar eventos por fecha" << endl;
    cout << "5. Mostrar todos los eventos" << endl;
    cout << "6. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

int main() {
    map<string, Evento> eventos;
    int opcion;

    do {
        mostrarMenuEventos();
        cin >> opcion;
        clearInputBuffer();

        switch (opcion) {
            case 1: {
                cout << "\n--- AGREGAR NUEVO EVENTO ---" << endl;
                cout << "Ingrese nombre del evento: ";
                string nombreEvento;
                getline(cin, nombreEvento);

                if (eventos.count(nombreEvento)) {
                    cout << "Error: Ya existe un evento con ese nombre." << endl;
                    break;
                }

                cout << "Ingrese fecha del evento (YYYY-MM-DD): ";
                string fechaEvento;
                getline(cin, fechaEvento);

                eventos[nombreEvento] = Evento(nombreEvento, fechaEvento);
                cout << "Evento '" << nombreEvento << "' agregado correctamente." << endl;
                break;
            }
            case 2: {
                cout << "\n--- AGREGAR ASISTENTES ---" << endl;
                cout << "Ingrese el nombre del evento: ";
                string nombreEvento;
                getline(cin, nombreEvento);

                auto it = eventos.find(nombreEvento);
                if (it != eventos.end()) {
                    cout << "Evento '" << nombreEvento << "' encontrado." << endl;
                    string asistenteNombre;
                    while (true) {
                        cout << "Ingrese nombre del asistente (o 'fin' para terminar): ";
                        getline(cin, asistenteNombre);
                        if (asistenteNombre == "fin") {
                            break;
                        }
                        it->second.agregarAsistente(asistenteNombre);
                        cout << "Asistente '" << asistenteNombre << "' agregado." << endl;
                    }
                } else {
                    cout << "Evento '" << nombreEvento << "' no encontrado." << endl;
                }
                break;
            }
            case 3: {
                cout << "\n--- MOSTRAR ASISTENTES ---" << endl;
                cout << "Ingrese el nombre del evento: ";
                string nombreEvento;
                getline(cin, nombreEvento);

                auto it = eventos.find(nombreEvento);
                if (it != eventos.end()) {
                    cout << "Asistentes para el evento '" << it->second.nombre << "' (" << it->second.fecha << "):" << endl;
                    if (it->second.asistentes.empty()) {
                        cout << "No hay asistentes registrados para este evento." << endl;
                    } else {
                        for (const string& asistente : it->second.asistentes) {
                            cout << "- " << asistente << endl;
                        }
                    }
                } else {
                    cout << "Evento '" << nombreEvento << "' no encontrado." << endl;
                }
                break;
            }
            case 4: {
                cout << "\n--- BUSCAR EVENTOS POR FECHA ---" << endl;
                cout << "Ingrese la fecha a buscar (YYYY-MM-DD): ";
                string fechaBuscar;
                getline(cin, fechaBuscar);

                bool encontrados = false;
                cout << "Eventos en la fecha " << fechaBuscar << ":" << endl;
                for (const auto& par : eventos) {
                    if (par.second.fecha == fechaBuscar) {
                        cout << "- " << par.second.nombre << endl;
                        encontrados = true;
                    }
                }
                if (!encontrados) {
                    cout << "No se encontraron eventos para esa fecha." << endl;
                }
                break;
            }
            case 5: {
                cout << "\n--- LISTA DE TODOS LOS EVENTOS ---" << endl;
                if (eventos.empty()) {
                    cout << "No hay eventos registrados." << endl;
                } else {
                    for (const auto& par : eventos) {
                        cout << "Evento: " << par.second.nombre << ", Fecha: " << par.second.fecha << endl;
                        cout << "  Asistentes (" << par.second.asistentes.size() << "): ";
                        if (par.second.asistentes.empty()) {
                            cout << "Ninguno" << endl;
                        } else {
                            for (const auto& asistente : par.second.asistentes) {
                                cout << asistente << "; ";
                            }
                            cout << endl;
                        }
                    }
                }
                break;
            }
            case 6: {
                cout << "Saliendo del programa de organizacion de eventos. ¡Hasta luego!" << endl;
                break;
            }
            default: {
                cout << "Opcion no valida. Por favor, intente de nuevo." << endl;
                break;
            }
        }
    } while (opcion != 6);

    return 0;
}