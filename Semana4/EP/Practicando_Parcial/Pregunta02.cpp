#include <iostream>
using namespace std;

// Función para crear matriz dinámica (Sesión 9)
int** crearMatriz(int n) {
    int** M = new int*[n];
    for (int i = 0; i < n; i++) {
        *(M + i) = new int[n];
    }
    return M;
}

// Función para liberar memoria (Evitar leaks según Valgrind)
void liberarMatriz(int** M, int n) {
    for (int i = 0; i < n; i++) {
        delete[] *(M + i);
    }
    delete[] M;
}

// Función para obtener la submatriz Mij (eliminando fila 'f' y columna 'c')
void obtenerSubmatriz(int** M, int** sub, int f, int c, int n) {
    int filaSub = 0;
    for (int i = 0; i < n; i++) {
        if (i == f) continue; // Saltamos la fila elegida
        int colSub = 0;
        for (int j = 0; j < n; j++) {
            if (j == c) continue; // Saltamos la columna del elemento
            *(*(sub + filaSub) + colSub) = *(*(M + i) + j);
            colSub++;
        }
        filaSub++;
    }
}

// Función recursiva para el determinante
int calcularDeterminante(int** M, int n) {
    // Caso base: matriz 1x1
    if (n == 1) return **M;
    
    // Caso base: matriz 2x2 (opcional por eficiencia)
    if (n == 2) {
        return (*(*(M + 0) + 0) * *(*(M + 1) + 1)) - (*(*(M + 0) + 1) * *(*(M + 1) + 0));
    }

    // 1. Seleccionar automáticamente la fila con más ceros
    int filaElegida = 0;
    int maxCeros = -1;

    for (int i = 0; i < n; i++) {
        int cerosEnFila = 0;
        for (int j = 0; j < n; j++) {
            if (*(*(M + i) + j) == 0) cerosEnFila++;
        }
        
        // Regla: Si alguna fila es nula, determinante es 0
        if (cerosEnFila == n) return 0;

        if (cerosEnFila > maxCeros) {
            maxCeros = cerosEnFila;
            filaElegida = i;
        }
    }

    int det = 0;
    int signo = (filaElegida % 2 == 0) ? 1 : -1; // Ajuste de signo inicial según la fila

    // 2. Expansión por cofactores en la fila elegida
    for (int j = 0; j < n; j++) {
        int elemento = *(*(M + filaElegida) + j);
        
        // Si el elemento es 0, no llamamos a la recursión (optimización)
        if (elemento != 0) {
            int** sub = crearMatriz(n - 1);
            obtenerSubmatriz(M, sub, filaElegida, j, n);
            
            // Signo del cofactor: (-1)^(i+j)
            int signoCofactor = ((filaElegida + j) % 2 == 0) ? 1 : -1;
            
            det += signoCofactor * elemento * calcularDeterminante(sub, n - 1);
            
            liberarMatriz(sub, n - 1);
        }
    }

    return det;
}

int main() {
    int n;
    cout << "Ingrese el tamano de la matriz (maximo 10): ";
    cin >> n;

    if (n <= 0 || n > 10) {
        cout << "Tamano no valido." << endl;
        return 1;
    }

    int** A = crearMatriz(n);

    cout << "Ingrese los elementos de la matriz:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> *(*(A + i) + j);
        }
    }

    int resultado = calcularDeterminante(A, n);
    cout << "Determinante = " << resultado << endl;

    liberarMatriz(A, n);

    return 0;
}