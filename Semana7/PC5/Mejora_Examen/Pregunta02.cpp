#include <iostream>
#include <fstream>

using namespace std;

struct Empleado{
    int id; // Comienza en 1
    char nombre[30];
    double salario;
};

int main(){
    fstream archivo("input/empleados.dat", ios::in | ios::out | ios::binary); // Recordar: ios::in (lectura), ios::out (escritura), ios::binary (modo binario)

    if (!archivo){
        cout << "Error: No se pudo abrir el archivo" << endl;
        return 1;
    }

    int ID;
    cout << "Ingrese ID de empleado: ";
    cin >> ID;

    long desplazamiento = (ID - 1) * sizeof(Empleado); // Desplazamiento que se dara

    archivo.seekg(desplazamiento); // Lo buscamos para leer (seekg)

    Empleado E1;
    if(archivo.read(reinterpret_cast<char*>(&E1), sizeof(Empleado))){ // Leemos usando la forma para binario
        
        cout << "\n--- DATOS DEL EMPLEADO ---" << endl;
        cout << "ID: " << E1.id << endl;
        cout << "Nombre: " << E1.nombre << endl;
        cout << "Salario: " << E1.salario << endl;

        double nuevoSalario;
        cout << "\nIngrese nuevo salario: ";
        cin >> nuevoSalario; // Modificamos el salario
        E1.salario = nuevoSalario;

        archivo.seekp(desplazamiento); // Volvemos para escribir (seekp)
        archivo.write(reinterpret_cast<char*>(&E1), sizeof(Empleado));

        cout << "\nSalario actualizado correctamente." << endl;
    }
    else{ // Caso contrario se imprime:
        cout << "Error: El ID no existe." << endl;
    }

    archivo.close();
    return 0;
}