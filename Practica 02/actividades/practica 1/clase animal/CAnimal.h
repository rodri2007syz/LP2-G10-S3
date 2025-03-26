#include <iostream>
#include <string>
using namespace std;

class Animal{
    private:
        string nombre;
        string tipoDeAnimal;
        int edad;
    
    public:
        Animal(string nom  , string tipo , int ed ): nombre(nom),tipoDeAnimal(tipo) ,edad(ed) {} // atento aqui
    
        void alimentar(){
            cout << nombre << " del tipo " << tipoDeAnimal << " fue alimentado " << endl;
        }
        /////////
        
        void hacerRuido(){
            if(tipoDeAnimal == "perro"){
                cout <<nombre << " dice: Guau Guau ! " << endl;
            }
            else if (tipoDeAnimal == "gato"){
                cout <<nombre << " dice: Miau  " << endl;
            }
            else if(tipoDeAnimal=="cerdo"){
                cout <<nombre << " dice: Oinc oinc ! " << endl;
            }
        }
        ///////
        
        void mostrarinfo(){
            cout << "Datos del Animal"<< endl;
            cout << "----------------"<< endl;
            cout << "Nombre : " << nombre << endl;
            cout << "Edad : "<< edad << endl;
            cout << "Tipo :" << tipoDeAnimal<< endl;
            cout << "----------------"<< endl;
            
        }
};