#include <iostream>
using namespace std;

struct Item{
    char* descripcion; // memoria dinámica
    int cantidad;
    double precioUnitario;
};

struct Pedido{
    int numeroPedido; // memoria dinámica
    char* nombreCliente; // arreglo dinámico de items
    Item* items;
    int cantidadItems;
};

Item crearItem(const char* d, int c, double p){
    Item I1; // Rellenado datos de I1
    int t = 0; 
    while(d[t] != '\0'){ // Calculado la cantidad caracteres
        t++;
    }
    I1.descripcion = new char[t + 1]; // Reservando memoria con lo calculado
    for(int i = 0; i <= t; i++){
        I1.descripcion[i] = d[i]; // Copiando la descripcion
    }
    I1.cantidad = c; 
    I1.precioUnitario = p;
    return I1;
}

Pedido* crearPedido(int n, const char* c, int cant){
    Pedido* p = new Pedido;
    p->numeroPedido = n; 
    p->cantidadItems = cant;
    int t = 0; 
    while(c[t] != '\0'){  // Calculado la cantidad caracteres
        t++;
    }
    p->nombreCliente = new char[t + 1]; // Reservando memoria con lo calculado
    for(int i = 0; i <= t; i++){
        p->nombreCliente[i] = c[i]; // Copiando el nombre
    }
    
    p->items = new Item[cant]; // Reservamos memoria para un arreglo de Items
    p->items[0] = crearItem("Procesador", 3, 975.0);
    p->items[1] = crearItem("Monitoe", 3, 275.0);
    p->items[2] = crearItem("Tarjeta Grafica", 3, 1600.0);
    return p;
}

double calcularTotal(const Pedido* p){
    double total = 0;
    for(int i = 0; i < p->cantidadItems; i++){ // Siplemente se usa la formula Sumatoria (cantidad  * precio_unitario)
        total += (p->items[i].cantidad * p->items[i].precioUnitario);
    }
    return total;
}

Item* itemMasCaro(Pedido* p){
    int mc = 0;
    for(int i = 1; i < p->cantidadItems; i++){
        if(p->items[i].precioUnitario > p->items[mc].precioUnitario){ // En caso mc sea mayor nos quedamos en esa pos y retornamos la referencia simplente
            mc = i;
        }
    }
    return &p->items[mc];
}

void liberarPedido(Pedido* p){ // Liberamos de forma correcta
    for(int i = 0; i < p->cantidadItems; i++){
        delete[] p->items[i].descripcion;
    }
    delete[] p->items;
    delete[] p->nombreCliente;
    delete p;
}

int main() {
    Pedido* p = crearPedido(192, "Daniel Diaz", 3);
    
    cout << "Pedido N°: " << p->numeroPedido << endl;
    cout << "Cliente: " << p->nombreCliente << endl;
    cout << "\nItems:" << endl;
    for(int i = 0; i < p->cantidadItems; i++){
        cout << "- "<< p->items[i].descripcion << " | Cant: " << p->items[i].cantidad << " | Precio: " << p->items[i].precioUnitario << endl;
    }
    
    cout << "\nTotal: " << calcularTotal(p) << endl;
    
    Item* m = itemMasCaro(p);
    cout << "\nItem mas caro: " << m->descripcion << " | " << " Precio: " << m->precioUnitario << endl;

    liberarPedido(p);
    return 0;
}