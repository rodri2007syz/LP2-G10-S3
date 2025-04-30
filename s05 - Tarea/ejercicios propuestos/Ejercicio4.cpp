
#include <iostream>
#include <string>
using namespace std;

class Direccion{
    private:
    string DireccionVi;
    public:
    Direccion(string Di):
    DireccionVi(Di){
        cout << "registro de direccion aceptado"<< endl;
    }

    void infDireccion(){
        cout << "Direccion -> " << DireccionVi << endl;
    }
    ~Direccion(){
        cout << "se elimino correctamente la direccion " << endl;
        cout << "----------------------------"<< endl;
    }

};
class Gerente{//alta gerencia, gerentes medios, gerentes de primera línea
    private:
    string nombre;
    string nivelJerar;
    int ID;
    string turno;

    public:
    Gerente (string nom , string niv, int id , string tur):
    nombre(nom),nivelJerar(niv), ID(id),turno(tur){
        cout <<" se registro al gerente " << endl;
        cout << "----------------------------"<< endl;
    }
    void infoGerente(){
        cout << " Gerente --> Sr." << nombre << endl;
        cout << " Nivel --> " << nivelJerar << endl;
        cout << "ID --> "<< ID << endl;
        cout << "Turno " << turno << endl;
    }

    ~Gerente(){
        cout << "se elimino correctamente al gerente" << endl;
        cout << "----------------------------"<< endl;
    }
};
class Empresa{
    private:
    string NombreEmp;
    Gerente GerenteE;
    Direccion DireccionGen;
    public:
    Empresa ( string nomemp,string nom , string niv, int id , string tur,string Di):
    NombreEmp(nomemp),GerenteE(nom,niv, id,tur),DireccionGen(Di){
        cout << "se registro la empresa "<< NombreEmp << "correctamente con sus datos" << endl;
        cout << "----------------------------"<< endl;
    }

    void infoEmpresa(){
        cout << "La empresa " << NombreEmp << endl;
        GerenteE.infoGerente();
        DireccionGen.infDireccion();
    }

    ~Empresa(){
        cout << "se elimino la empresa"<< NombreEmp << endl;
    }
};

int main(){
    Empresa emp1("Interbank","Ronaldo","Alto gerente",222222,"mañana","avenida D serca a mall");
    Empresa emp2("BCP","Carlos","gerente de primera linia",111,"noche","avenida O");
    emp1.infoEmpresa();
    cout << "----------------------------"<< endl;
    emp2.infoEmpresa();

}