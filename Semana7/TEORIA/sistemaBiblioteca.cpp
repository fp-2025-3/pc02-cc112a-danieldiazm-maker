#include <iostream>
using namespace std;

const int MAX_LIBROS = 100;

struct Libro {
    int codigo;
    char titulo[50];
    bool prestado;
};

// Funciones a implementar

void registrarLibro(Libro *libros, int &n){
    if (n >= MAX_LIBROS){
        cout << "Capacidad maxima alcanzada\n";
        return;
    }

    for (int i = 0; i < n; i++){
        cout << "Codigo: ";
        cin >> libros[i].codigo;

        cin.ignore();

        cout << "Titulo: ";
        cin.getline(libros[i].titulo,50);

        libros[i].prestado = false;
    }

}

int buscarLibro(Libro libros[], int n, int codigo);

void prestarLibro(Libro libros[],int n);

void devolverLibro(Libro libros[], int n);

void guardarEnArchivo(Libro libros[], int n);

void cargarDesdeArchivo(Libro libros[], int n);

void mostrarLibros(Libro libros[], int n);

int main(){
    int n;

    cout << "Digite la cantidad de libros a regitrar: ";
    cin >> n;
    Libro *libros =  new Libro[n];

    registrarLibro(libros,n);

    return 0;
}