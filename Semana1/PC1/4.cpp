#include <iostream>

using namespace std;

int main() {
    // Ejemplo del PDF: 16 números
    // Pares: 4, 7, 15, 24, 35, 40, 50, 55 (Ordenados)
    // Impares: 0, 8, 12, 25, 30, 44, 46, 60 (Ordenados)
    int n = 16;
    int lista[] = {4, 0, 7, 8, 15, 12, 24, 25, 35, 30, 40, 44, 50, 46, 55, 60};
    
    int buscado;
    cout << "Ingrese numero a buscar: ";
    cin >> buscado;

    int encontradoEnIndice = -1; // -1 significa "no encontrado"

    // --- BÚSQUEDA 1: EN ÍNDICES PARES (0, 2, 4...) ---
    // Consideramos que hay n/2 elementos pares (o (n+1)/2 si es impar)
    int inicio = 0;
    int fin = (n % 2 == 0) ? (n/2 - 1) : (n/2); // Cantidad de elementos pares - 1
    
    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;
        int indiceReal = 2 * medio; // Convertimos índice virtual a índice real par

        if (lista[indiceReal] == buscado) {
            encontradoEnIndice = indiceReal;
            break;
        }
        if (lista[indiceReal] < buscado) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }

    // --- BÚSQUEDA 2: EN ÍNDICES IMPARES (1, 3, 5...) ---
    // Solo si no lo encontramos en los pares
    if (encontradoEnIndice == -1) {
        inicio = 0;
        fin = (n / 2) - 1; // Cantidad de elementos impares - 1
        
        while (inicio <= fin) {
            int medio = inicio + (fin - inicio) / 2;
            int indiceReal = 2 * medio + 1; // Convertimos índice virtual a índice real impar

            if (lista[indiceReal] == buscado) {
                encontradoEnIndice = indiceReal;
                break;
            }
            if (lista[indiceReal] < buscado) {
                inicio = medio + 1;
            } else {
                fin = medio - 1;
            }
        }
    }

    // Resultado
    if (encontradoEnIndice != -1) {
        cout << "El numero se encuentra en el indice: " << encontradoEnIndice << endl;
    } else {
        cout << "El numero no se encuentra en la lista." << endl;
    }

    return 0;
}