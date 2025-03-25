#include "carrera.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
    int velcomp,poscomp,nivcomp=4,ruta;
    string name;
    cout << " ingrese nombre del jugador: "<<endl;
    cin >> name;
    srand(time(0));
    while (nivcomp>3){
      cout << "con que nivel de CPU desea competir ? \n (1 - Facil) \n (2 - Medio) \n (3 - Dificil)"<<endl;
      cin >> nivcomp;  
      if (nivcomp=1){
          velcomp=rand() %11;
          ruta=rand() % 51 + 50;
          Carrera p1(ruta,name);
          cout << "informacion de la carrera: " << endl;
          p1.mostrarinformacion();
      }
    }
}
