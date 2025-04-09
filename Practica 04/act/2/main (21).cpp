#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Autor {
private:
    string nombre;
    string nacionalidad;
public:
    Autor(string n, string nac) : nombre(n), nacionalidad(nac) {}
    string getNombre() { return nombre; }
    string getNacionalidad() { return nacionalidad; }
};


class Libro {
private:
    string ISBN;
    string titulo;
    int anio;
    int cantidad;
    Autor* autor;  
public:
    Libro(string isbn, string t, int a,int can, Autor* aut)
        : ISBN(isbn), titulo(t), anio(a),cantidad(can), autor(aut) {
    }
    string getTitulo() { return titulo; }
    Autor* getAutor() { return autor; }
    string getISBN() { return ISBN; }
    int getCantidad() { return cantidad; }
    void reducirCantidad() { if (cantidad > 0) cantidad--; }
    void aumentarCantidad() { cantidad++; }
    
};

// Clase Usuario
class Usuario {
private:
    string nombre;
    string direccion;
    vector<Libro*> librosPrestados;  
public:
    Usuario(string n, string d) : nombre(n), direccion(d) {}

    string getNombre() {
        return nombre;
    }

    void prestarLibro(Libro* libro) {
        librosPrestados.push_back(libro);
    }
    void devolverLibro(Libro* libro) {
        for (auto it = librosPrestados.begin(); it != librosPrestados.end(); ++it) {
            if (*it == libro) {
                librosPrestados.erase(it);
                libro->aumentarCantidad();
                cout << "Libro devuelto con exito!\n";
                return;
            }
        }
        cout << "Este usuario no tiene prestado este libro.\n";
    }

    void mostrarLibros() {
        cout << "Libros prestados a " << nombre << ":\n";
        for (auto libro : librosPrestados) {
            cout << "- " << libro->getTitulo()
                << " (Autor: " << libro->getAutor()->getNombre() << ")\n";
        }
    }
};
int main(){
    vector<Autor*> autores;
    vector<Libro*>libros;
    vector<Usuario*>usuarios;
    string noma, nacia;
    int opc=-1,conf=0;
    while (opc < 1) {
        cout << "Menu: \n 1. Agregar un autor \n 2. Agregar un libro  \n 3. Crear un usuario  \n 4. mostrar informacion de la biblioteca \n 5. SALIR  "<<endl;
        cin >> opc;
        if (opc == 1) {
            conf += 1;
            cout << "Ingrese el nombre del autor: " << endl;
            cin >> noma;
            cout << "Ingrese la nacionalidad del autor: " << endl;
            cin >> nacia;
            autores.push_back(new Autor(noma, nacia));
            cout << "Autor agregado con exito! \n ";
            opc = -1;
        }
        if (opc == 2) {
            if (conf < 1) {
                cout << "Primero debe de agregar un autor para agregar un libro recien " << endl;
                opc = -1;

            }
            else {
                string isbn, titulo;
                int anio, cantidad, autoridx;
                cout << "Autores disponibles: \n";
                for (int i = 0;i < autores.size();i++) {
                    cout << i + 1 << ". " << autores[i]->getNombre()<<endl;
                }
                cout << "Seleccione el numero del autor: " << endl;
                cin >> autoridx;
                if (autoridx<1 || autoridx > autores.size()) {
                    cout << "Seleccion no valida";
                    opc = -1;
                }
                cout << "Ingrese el ISBN del libro: ";
                cin >> isbn;
                cout << " Ingrese el titulo del libro: ";
                cin >> titulo;
                cout << "Ingrese el año de publicacion ";
                cin >> anio;
                cout << "Ingrese la cantidad de ejemplares: ";
                cin >> cantidad;
                libros.push_back(new Libro(isbn, titulo, anio, cantidad, autores[autoridx - 1]));
                cout << "Libro agregado con exito";
                opc = -1;
            }
        }
        if (opc == 3) {
            string nombus, direus;
            cout << "Ingrese el nombre del usuario: ";
            cin >> nombus;
            cout << "Ingrese la direccion del usuario: ";
            cin >> direus;
            usuarios.push_back(new Usuario(nombus, direus));
            int opc2=-1;
            while (opc2 < 1) {
                cout << " Menu usuario: \n 1. Prestar un libro \n 2. Devolver un libro \n 3. Salir al menu anterior  " << endl;
                cin >> opc2;
                if (opc2 == 1) {
                    cout << "Usuarios disponibles:\n";
                    for (int i = 0; i < usuarios.size(); i++) {
                        cout << i + 1 << ". " << usuarios[i]->getNombre() << endl;
                    }
                    cout << "Seleccione el usuario: ";
                    int usuarioIdx;
                    cin >> usuarioIdx;
                    cout << "Libros disponibles:\n";
                    for (int i = 0; i < libros.size(); i++) {
                        cout << i + 1 << ". " << libros[i]->getTitulo()
                            << " (Ejemplares: " << libros[i]->getCantidad() << ")\n";
                    }
                    cout << "Seleccione el libro a prestar: ";
                    int libroIdx;
                    cin >> libroIdx;
                    if (usuarioIdx >= 1 && usuarioIdx <= usuarios.size() &&
                        libroIdx >= 1 && libroIdx <= libros.size()) {
                        usuarios[usuarioIdx - 1]->prestarLibro(libros[libroIdx - 1]);
                        opc2 = -1;
                    }
                    else {
                        cout << "Seleccion invalida.\n";
                        opc2 = -1;
                    }
                }
                if (opc2 == 2) {
                    cout << "Usuarios disponibles:\n";
                    for (int i = 0; i < usuarios.size(); i++) {
                        cout << i + 1 << ". " << usuarios[i]->getNombre() << endl;
                    }
                    cout << "Seleccione el usuario: ";
                    int usuarioIdx;
                    cin >> usuarioIdx;
                    cout << "Libros disponibles:\n";
                    for (int i = 0; i < libros.size(); i++) {
                        cout << i + 1 << ". " << libros[i]->getTitulo()
                            << " (Ejemplares: " << libros[i]->getCantidad() << ")\n";
                    }
                    cout << "Seleccione el libro a devolver: ";
                    int libroIdx;
                    cin >> libroIdx;
                    if (usuarioIdx >= 1 && usuarioIdx <= usuarios.size() &&
                        libroIdx >= 1 && libroIdx <= libros.size()) {
                        usuarios[usuarioIdx - 1]->devolverLibro(libros[libroIdx - 1]);
                        opc2 = -1;
                    }
                    else {
                        cout << "Seleccion invalida.\n";
                        opc2 = -1;
                    }
                }
                if (opc2 == 3) {
                    opc = -1;
                    opc2 = 2;
                }
            }
        }
        
        if (opc == 4) {
            cout << "Informacion de la biblioteca: ";
            cout << "\nAutores (" << autores.size() << "):\n";
            for (auto autor : autores) {
                cout << "- " << autor->getNombre()
                    << " (" << autor->getNacionalidad() << ")\n";
            }

            cout << "\nLibros (" << libros.size() << "):\n";
            for (auto libro : libros) {
                cout << "- " << libro->getTitulo()
                    << " (ISBN: " << libro->getISBN()
                    << ", Autor: " << libro->getAutor()->getNombre()
                    << ", Ejemplares: " << libro->getCantidad() << ")\n";
            }

            cout << "\nUsuarios (" << usuarios.size() << "):\n";
            for (auto usuario : usuarios) {
                usuario->mostrarLibros();
            }
            opc = -1;
       
        }
        if (opc == 5) {
            opc = 2;
      }
    }


}
