#include <iostream>
#include <fstream>

using namespace std;

struct Empleado {
    int id; // Comienza en 1
    char nombre[30];
    double salario;
};

int main() {
     // ios::in (lectura), ios::out (escritura), ios::binary (modo binario)
    fstream archivo("input/empleados.dat", ios::in | ios::out | ios::binary);

    if (!archivo) {
        cout << "Error: No se pudo abrir el archivo input/empleados.dat" << endl;
        return 1;
    }

    int idBusca;
    cout << "Ingrese ID de empleado: ";
    cin >> idBusca;

    // 1. CÁLCULO DE LA POSICIÓN (Acceso Directo)
    // El ID 1 está en el byte 0, el ID 2 en el byte 1 * sizeof(Empleado), etc.
    streampos posicion = (idBusca - 1) * sizeof(Empleado);

    // 2. MOVER PUNTERO DE LECTURA (seekg)
    archivo.seekg(posicion);

    Empleado E1;
    // Intentamos leer el registro completo
    if (archivo.read(reinterpret_cast<char*>(&E1), sizeof(Empleado))) {
        
        cout << "\n--- DATOS DEL EMPLEADO ---" << endl;
        cout << "ID: " << E1.id << endl;
        cout << "Nombre: " << E1.nombre << endl;
        cout << "Salario: " << E1.salario << endl;

        // 3. MODIFICACIÓN DEL SALARIO
        double nuevoSalario;
        cout << "\nIngrese nuevo salario: ";
        cin >> nuevoSalario;
        E1.salario = nuevoSalario;

        // 4. ACTUALIZACIÓN (Acceso Directo para escribir)
        // Debemos mover el puntero de escritura (seekp) a la misma posición
        archivo.seekp(posicion);
        archivo.write(reinterpret_cast<char*>(&E1), sizeof(Empleado));

        cout << "\nSalario actualizado correctamente." << endl;
    } else {
        cout << "Error: El ID " << idBusca << " no existe o esta fuera de rango." << endl;
    }

    archivo.close();
    return 0;
}