

#include <string>
#include <iostream>
#include <vector>
#include <type_traits>
using namespace std;

class Vehiculo{
    private:
        string placa , tipo;
        double capacidadKg;
    public:
        Vehiculo(string pl,string tip,double cap):placa(pl),tipo(tip),capacidadKg(cap){}
        
        void infoVehiculo()const{
            cout << "Placa: "<< placa <<endl;
            cout << "Tipo:"<< tipo <<endl;
            cout << "capacidad Kg"<< capacidadKg <<endl;
        }    
  
};

class Ruta{
    private:
    string ID ,  direccion;
    float distancia;
    public:
    Ruta(string id , string dir, float dis):ID(id),direccion(dir),distancia(dis){}
    
    void mostrarRutaInfo() const {
        cout << "Direccion: " << direccion<< endl;
        cout << "ID: "<< ID << endl;
        cout << "Distancia :" << distancia<<endl;
    }
    
};
class Entrega{
    public:
    template <typename T>
    
    void asignarVehiculo(const Vehiculo& vehiculo,const Ruta& ruta , const T& Motivo){
        cout << "__----INFO DEL PEDIDO----___"<< endl;
        vehiculo.infoVehiculo();
        cout << "----------------------------"<<endl;
        ruta.mostrarRutaInfo();
        cout << "---------Motivo de asignacion--"<<endl;
        
        cout << "motivo de asignacion "<< Motivo << endl;
        if constexpr(is_same_v < T , int>){
               cout << " (Nivel de Prioridad)";
        } else if constexpr (std::is_same_v<T, std::string>) {
                cout << " (Nombre del Conductor)";
        } else if constexpr (std::is_same_v<T, double>) {
                cout << " (Tiempo Estimado de Llegada en Horas)";
        }cout << endl;
        
    }
    
};



int main() {

    Vehiculo miCamion("ABC-123", "Camion Grande", 5000.0);
    Vehiculo miMoto("XDY-231","Moto",250.0);
    Ruta miRuta("RUTA-001", "Av. Siempre Viva 742", 150.75f);

    Entrega miEntregaManager;

    cout << "--- Asignación 1 (Prioridad) ---" << endl;
    miEntregaManager.asignarVehiculo(miCamion, miRuta, 1);

    cout << "\n--- Asignación 2 (Conductor) ---" << endl;
    miEntregaManager.asignarVehiculo(miMoto, miRuta, string("Elena Rojas"));

    cout << "\n--- Asignación 3 (ETA) ---" << endl;
    miEntregaManager.asignarVehiculo(miCamion, miRuta, 3.5);

    return 0;
}
