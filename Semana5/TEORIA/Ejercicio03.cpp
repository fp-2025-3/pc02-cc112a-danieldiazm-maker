#include<iostream>
using namespace std;

struct Producto{
    int codigo;
    float precio;
    Producto *sgt;
};


int main(){

    Producto* cabeza = nullptr; // Puntero llamado cabeza a tipo "Producto" inicializamos en nullptr porque es puntero
    
    // Insertar producto al inicio

    for (int i = 0; i < 2; ++i){
        Producto* nuevo = new Producto;
        cout << "Ingrese codigo: "; cin >> nuevo -> codigo;
        cout << "Ingrese Precio: "; cin >> nuevo -> precio;
        nuevo -> sgt = cabeza;
        cabeza = nuevo;
    }

    // Mostrar los productoas
    Producto* actual = cabeza; // Empezamos por el principio
    while (actual != nullptr) { // Mientras no lleguemos al final (tierra)
        cout << "Codigo: " << actual -> codigo << endl;
        actual = actual -> sgt; // Saltamos al siguiente nodo usando el puntero
    }

    while (cabeza != nullptr){ // 2 24 &1 // 1 12 nullptr  //temp apunta a 2 --> cabeza se va a 1 --> se libera con delete temp --> cabeza se va a nullptr --> se libera con delete temp
        Producto* temp = cabeza;
        cabeza = cabeza -> sgt;
        delete temp;
    }

    return 0;
}