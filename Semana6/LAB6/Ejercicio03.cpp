#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Producto {
    int id;                  // Identificador único
    char nombre[30];         // Nombre del producto
    double precio;           // Precio unitario
    int stock;               // Cantidad disponible
    bool activo;             // true = activo, false = eliminado lógicamente
};

// Función para verificar si un ID ya existe (usada en registrar)
int buscarProductoPorID(const char* nombreArchivo, int idBuscado) {
    ifstream archivo(nombreArchivo, ios::binary);
    if (!archivo) return -1;

    Producto p;
    int pos = 0;
    // Leemos registro por registro
    while (archivo.read(reinterpret_cast<char*>(&p), sizeof(Producto))) {
        if (p.id == idBuscado && p.activo) {
            archivo.close();
            return pos; // Devuelve la posición física (0, 1, 2...)
        }
        pos++;
    }
    archivo.close();
    return -1;
}

// --- Funciones Principales ---

// a) Registrar Producto
void registrarProducto(const char* nombreArchivo) {
    ofstream archivo(nombreArchivo, ios::binary | ios::app);
    if (!archivo) return;

    Producto p;
    cout << "Ingrese ID: "; cin >> p.id;

    // Validación de ID único
    if (buscarProductoPorID(nombreArchivo, p.id) != -1) {
        cout << "Error: El ID ya existe.\n";
        archivo.close();
        return;
    }

    cout << "Nombre: "; cin.ignore(); cin.getline(p.nombre, 30);
    
    do {
        cout << "Precio (>0): "; cin >> p.precio;
    } while (p.precio <= 0);

    do {
        cout << "Stock (>=0): "; cin >> p.stock;
    } while (p.stock < 0);

    p.activo = true;

    // Guardar la estructura completa como bloque (Teoría punto 7)
    archivo.write(reinterpret_cast<char*>(&p), sizeof(Producto));
    archivo.close();
    cout << "Producto registrado con exito.\n";
}

// b) Mostrar Productos
void mostrarProductos(const char* nombreArchivo) {
    ifstream archivo(nombreArchivo, ios::binary);
    if (!archivo) return;

    Producto p;
    int pos = 0;
    cout << "\n--- INVENTARIO ---\n";
    while (archivo.read(reinterpret_cast<char*>(&p), sizeof(Producto))) {
        if (p.activo) {
            cout << "Pos: " << pos << " | ID: " << p.id 
                 << " | Nom: " << p.nombre << " | Prc: " << p.precio 
                 << " | Cant: " << p.stock << endl;
        }
        pos++;
    }
    archivo.close();
}

// d) Modificar Precio (Acceso Aleatorio)
void modificarPrecio(const char* nombreArchivo, int id, double nuevoPrecio) {
    // Abrir en modo lectura/escritura (Teoría punto 8)
    fstream archivo(nombreArchivo, ios::in | ios::out | ios::binary);
    if (!archivo) return;

    int pos = buscarProductoPorID(nombreArchivo, id);
    if (pos == -1) {
        cout << "Producto no encontrado.\n";
    } else {
        Producto p;
        // Ubicarse en el registro exacto
        archivo.seekg(pos * sizeof(Producto));
        archivo.read(reinterpret_cast<char*>(&p), sizeof(Producto));

        p.precio = nuevoPrecio;

        // Regresar a la misma posición para sobreescribir
        archivo.seekp(pos * sizeof(Producto));
        archivo.write(reinterpret_cast<char*>(&p), sizeof(Producto));
        cout << "Precio actualizado.\n";
    }
    archivo.close();
}

// e) Eliminar Producto (Lógico)
void eliminarProducto(const char* nombreArchivo, int id) {
    fstream archivo(nombreArchivo, ios::in | ios::out | ios::binary);
    if (!archivo) return;

    int pos = buscarProductoPorID(nombreArchivo, id);
    if (pos != -1) {
        Producto p;
        archivo.seekg(pos * sizeof(Producto));
        archivo.read(reinterpret_cast<char*>(&p), sizeof(Producto));

        p.activo = false; // Eliminación lógica

        archivo.seekp(pos * sizeof(Producto));
        archivo.write(reinterpret_cast<char*>(&p), sizeof(Producto));
        cout << "Producto eliminado (logicamente).\n";
    }
    archivo.close();
}

// f) Calcular Valor Total
double calcularValorInventario(const char* nombreArchivo) {
    ifstream archivo(nombreArchivo, ios::binary);
    if (!archivo) return 0;

    Producto p;
    double total = 0;
    while (archivo.read(reinterpret_cast<char*>(&p), sizeof(Producto))) {
        if (p.activo) {
            total += (p.precio * p.stock);
        }
    }
    archivo.close();
    return total;
}

int main() {
    const char* nombreArchivo = "inventario.txt";
    int opcion, id;
    double precio;

    do {
        cout << "\n1. Registrar\n2. Mostrar\n3. Buscar\n4. Modificar Precio\n5. Eliminar\n6. Valor Total\n7. Salir\nOpcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: registrarProducto(nombreArchivo); break;
            case 2: mostrarProductos(nombreArchivo); break;
            case 3: 
                cout << "ID a buscar: "; cin >> id;
                cout << "Encontrado en posicion: " << buscarProductoPorID(nombreArchivo, id) << endl;
                break;
            case 4:
                cout << "ID: "; cin >> id;
                cout << "Nuevo precio: "; cin >> precio;
                modificarPrecio(nombreArchivo, id, precio);
                break;
            case 5:
                cout << "ID a eliminar: "; cin >> id;
                eliminarProducto(nombreArchivo, id);
                break;
            case 6:
                cout << "Valor total del inventario: " << calcularValorInventario(nombreArchivo) << endl;
                break;
        }
    } while (opcion != 7);

    return 0;
}