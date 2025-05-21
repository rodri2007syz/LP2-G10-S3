#include <iostream>
using namespace std;

class Reproductor{
    public:
    virtual void reproducir()=0;
    virtual void pausar()=0;
    virtual void detener()=0;
     
};

class ReproductorMP3 : public Reproductor{
    private:
    string nombarch;
    bool enreproducion;
    bool pausado;
    public:
    ReproductorMP3(string nombarch_, bool enreproducion_=false , bool pausado_=false) 
    : nombarch(nombarch_), enreproducion(enreproducion_), pausado(pausado_) {}
    
    void reproducir() override{
        if ((pausado=false)&&(enreproducion=true)){
            cout<<"El archivo "<<nombarch<< " ya se esta reproduciendo"<<endl;
        }
        else{
            pausado=false;
            enreproducion=true;
            cout << "El archivo "<<nombarch<< " se empezo a reproducir "<< endl;
        }
    }
    void pausar() override{
        if (enreproducion=true){
            enreproducion=false;
            pausado=true;
            cout << "El archivo "<<nombarch<< " se pauso exitosamente"<<endl;
        }
        else{
            cout << "El archivo "<<nombarch<< " ya esta pausado"<<endl;
        }
    }
    void detener() override{
        enreproducion=false;
        pausado=false;
        cout << "El archivo "<<nombarch<< " se detuvo"<<endl;
    }
    void otroarchivo(const string& archivo){
        nombarch=archivo;
        enreproducion=false;
        pausado=false;
        cout << "El archivo: "<<archivo<<" fue cargado exitosamente! "<<endl;
    }
};

int main()
{
    ReproductorMP3 archivo1("musica.mp3");
    archivo1.reproducir();
    archivo1.pausar();
    archivo1.detener();
    archivo1.otroarchivo("musica2.mp3");
    archivo1.reproducir();
    archivo1.detener();
    return 0;
}
