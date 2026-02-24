#include <iostream>
#include <fstream> 

using namespace std;

const int DIAS = 7; 

int main () {
    ofstream archivo("output/ventas.txt"); // Crear o abrir en archivo de salida "ventas.txt" el cual esta dentro de la carpeta outout

    if (!archivo) { // Verificar si el archivo abrio correctamente
        cout << "Error al abrir el archivo"; // Si no abrio, ingresamos al if y damos como salida este mensaje
        return 1; // Finalizamos
    }

    double total = 0.0; // Iniciamos variables
    double mayorVenta;
    double menorVenta;
    double venta;

    for (int i = 1; i <= DIAS; ++i) { 
        cout << "Ingrese la venta del dia " << i << ": ";
        cin >> venta;

        archivo << venta << endl; // Escribimos en el archivo la venta "i"
        
        total += venta; // Al total sumamos las ventas de los DIAS despues de la iteracion

        if (i == 1){ // AL inicio le damos esta condicion
            mayorVenta = venta;
            menorVenta = venta;
        }
        else{ // Esto se hace para definir la mayor y menor venta
            if (venta > mayorVenta) {
                mayorVenta = venta;
            }
            if (venta < menorVenta) {
                menorVenta = venta;
            }
        }
    }

    double promedio = total / DIAS;

    archivo << "-------------------------" << endl; // Escribimos en el archivo
    archivo << "RESUMEN" << endl;
    archivo << "Total: " << total << endl;
    archivo << "Promedio: " << promedio << endl;
    archivo << "Mayor venta: " << mayorVenta << endl;
    archivo << "Menor venta: " << menorVenta << endl;

    archivo.close(); // Cerramos el archivo 

    cout << "Resumen generado con exito en ventas.txt" << endl;

    return 0;
}   