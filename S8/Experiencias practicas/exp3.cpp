#include <iostream>
using namespace std;

class Animal {
public:
    virtual void hacerSonido() const = 0;
   
};

class Perro : public Animal {
public:
    void hacerSonido() const override {
        cout << "Guau guau!" << endl;
    }
};

class Gato : public Animal {
public:
    void hacerSonido() const override {
        cout << "Miau miau!" << endl;
    }
};

class Vaca : public Animal {
public:
    void hacerSonido() const override {
        cout << "Muuu muuu!" << endl;
    }
};

int main() {
    
    Perro p;
    Gato g;
    Vaca v;
  
    p.hacerSonido();
    g.hacerSonido();
    v.hacerSonido();
    
    return 0;
}