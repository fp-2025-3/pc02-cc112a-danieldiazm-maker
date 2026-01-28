#include <iostream>
#include <string.h> // Necesario para usar texto (nombres)

using namespace std;

struct Alumno {
    string nombre;
    int nota;
};

int main() {
    int n;
    cout << "Ingrese la cantidad de alumnos (max 30): ";
    cin >> n;

    Alumno lista[30]; // Arreglo estático como pide la regla

    // 1. Lectura de datos
    for (int i = 0; i < n; i++) {
        cout << "Alumno " << i + 1 << " Nombre: ";
        cin >> lista[i].nombre;
        cout << "Alumno " << i + 1 << " Nota: ";
        cin >> lista[i].nota;
    }

    // 2. Ordenamiento Burbuja (Con doble criterio)
    // Queremos ordenar alfabéticamente (A-Z)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            bool intercambiar = false;

            // Criterio 1: Por Nombre (Ascendente)
            if (lista[j].nombre > lista[j+1].nombre) {
                intercambiar = true;
            }
            // Criterio 2: Si los nombres son iguales, desempatar por Nota (Ascendente)
            else if (lista[j].nombre == lista[j+1].nombre) {
                if (lista[j].nota > lista[j+1].nota) {
                    intercambiar = true;
                }
            }

            // Si se cumple alguna condición, hacemos el swap
            if (intercambiar) {
                Alumno temp = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = temp;
            }
        }
    }

    // 3. Imprimir resultados
    cout << "\n--- LISTA ORDENADA ---" << endl;
    cout << "Nombre\tNota" << endl;
    for (int i = 0; i < n; i++) {
        cout << lista[i].nombre << "\t" << lista[i].nota << endl;
    }

    return 0;
}