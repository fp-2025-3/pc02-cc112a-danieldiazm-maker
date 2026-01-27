#include <iostream>

using namespace std;

int main() {
    int A[] = {9, -3, 5, -2, -8, -6, 1, 3};
    int n = 8;
    int auxiliar[8]; // Arreglo temporal
    int contador = 0;

    cout << "Arreglo Original: ";
    for(int i=0; i<n; i++) cout << A[i] << " ";
    cout << endl;

    // PASO 1: Copiar los NEGATIVOS al auxiliar
    for (int i = 0; i < n; i++) {
        if (A[i] < 0) {
            auxiliar[contador] = A[i];
            contador++;
        }
    }

    // PASO 2: Copiar los POSITIVOS al auxiliar
    for (int i = 0; i < n; i++) {
        if (A[i] >= 0) {
            auxiliar[contador] = A[i];
            contador++;
        }
    }

    // PASO 3: Copiar de vuelta al original (opcional, para mostrar que A cambió)
    for (int i = 0; i < n; i++) {
        A[i] = auxiliar[i];
    }

    cout << "Arreglo Segregado: ";
    for(int i=0; i<n; i++) cout << A[i] << " ";
    cout << endl;

    return 0;
}