#include "GestorTareas.h"
#include "TareaUrgente.h"

using namespace std;

int main() {
    GestorTareas gestor;

    Tarea tareaNormal("Hacer presentacion", "Juan", "2024-12-20");
    TareaUrgente tareaImportante("Actualizar seguridad", "Ana", "2024-12-10");

    gestor.agregarTarea(&tareaNormal);
    gestor.agregarTarea(&tareaImportante);

    gestor.mostrarTareas();
    gestor.notificarTareas(); // Solo las tareas urgentes

    return 0;
}
