#include<iostream>
using namespace std;

struct Producto{
    int codigo;
    char* nombre; // cadena dinamica
    double precio;
    int stock;
};

Producto crearProducto(int codigo, const char* nombre, double precio, int strock){
    Producto P1;
    P1.nombre = new char[20];
    return P1;
}
Producto* crarInventario(int n){
    Producto *P1;
    return P1;
}

int main(){

    return 0;
}
