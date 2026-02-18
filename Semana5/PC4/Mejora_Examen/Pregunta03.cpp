#include <iostream>

using namespace std;

struct Producto{
    int codigo;
    char* nombre; // cadena dinamica
    double precio;
    int stock;
};

Producto crearProducto(int codigo, const char* nombre, double precio, int stock){
    Producto P1;
    P1.codigo = codigo;
    P1.precio = precio;
    P1.stock = stock;

    // Reservamos memoria dinámica para el nombre
    int tam = 0;
    while(nombre[tam] != '\0'){
        tam++; // Con esto sabemos la cantidad de caracteres en la palabra
    }

    P1.nombre = new char[tam + 1]; // Reservamos tam + 1 para incluir el carácter nulo \0

    for (int i = 0; i < tam; i++){ // Copiamos la cadena recibida
        P1.nombre[i] = nombre[i];
    }
    P1.nombre[tam] = '\0'; // Para finalizar la cadena

    return P1;
}

Producto* crearInventario(int n){
    Producto* inventario = new Producto[n]; // Reservamos memoria dinámica para n productos

    // Datos dados en el examen
    inventario[0] = crearProducto(100, "Procesador", 975.0, 12);
    inventario[1] = crearProducto(101, "Tarjeta Grafica", 1650.0, 18);
    inventario[2] = crearProducto(102, "Monitor", 275.0, 15);
    inventario[3] = crearProducto(103, "Laptop", 2050.0, 20);
    inventario[4] = crearProducto(104, "Impresora", 675.0, 25);

    return inventario;
}

Producto* buscarProducto(Producto* inventario, int n, int codigoBuscado){
    for(int i = 0; i < n; i++){
        if (inventario[i].codigo == codigoBuscado){

            return &inventario[i]; // Se retorna asi ya que nos pide retornar una referencia
        }
    }

    return nullptr; // Si no existe se retorna nullptr
}

void liberarInventario(Producto* inventario, int n){
    for(int i = 0; i < n; i++) {

        delete [] inventario[i].nombre; // Liberamos la memoria del nombre de cada producto
    }

    delete [] inventario; // Finalmente borramos el arreglo de los productos
}

void imprimir(Producto* inv, int n){
    cout << "INVENTARIO" << endl;
    for(int i = 0; i < n; i++){
        cout << "Codigo: " << inv[i].codigo << " | Nombre: " << inv[i].nombre << " | Precio: " << inv[i].precio << " | Stock: " << inv[i].stock << endl;
    }
}

int main() {
    int n = 5;
    
    Producto* miInventario = crearInventario(n);

    imprimir(miInventario, n);

    cout << "\nBuscando producto con codigo 104..." << endl;

    Producto* pEncontrado = buscarProducto(miInventario, n, 104); // Buscamos producto y recibimos puntero

    if(pEncontrado != nullptr){
        cout << "Producto encontrado: " << pEncontrado->nombre << " | Precio: " << pEncontrado->precio << endl;
    }
    else{
        cout << "ERROR: Producto no encontrado" << endl;
    }

    liberarInventario(miInventario, n); // Liberamos la memoria

    return 0;
}