#include<iostream>
using namespace std;

struct Item{
    char* descripcion; // memoria dinamica
    int cantidad;
    double precioUnitario;
};

struct Pedido{
    int numeroPedido; 
    char* nombreCliente; // memoria dinamica
    Item* items; // arreglo dinamico de items
    double cantidadItems;
};

Pedido* crearPedido(int numero, const char* cliente, int cantidadItems){
    Pedido *P1 = new Pedido;
    P1->nombreCliente = new char[20];
    P1->items = new Item;
    // P1->items = Item crearItem(const char* descripcion, int cantidad, double precio); ;
}

int main(){

    return 0;
}
