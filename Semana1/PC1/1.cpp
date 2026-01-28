#include <iostream>

using namespace std;

// Declaramos la matriz como global o con un tamaño fijo grande para no usar vectores.
// El problema dice n máximo de 7 o similar, ponemos 20 para estar seguros.
int matriz[20][20]; 

// Función Recursiva con "Memoria"
int calcularPascal(int i, int j) {
    // Caso Base 1: Primera columna (j=0) o Diagonal principal (i=j) siempre son 1
    if (j == 0 || j == i) {
        return 1;
    }
    
    // Caso Base 2: Si j > i, estamos por encima de la diagonal, debe ser 0
    if (j > i) {
        return 0;
    }

    // EL TRUCO (Memoización): 
    // Si la celda matriz[i][j] ya tiene un valor (es mayor a 0), 
    // NO entramos a la recursión, simplemente devolvemos el valor guardado.
    if (matriz[i][j] != 0) {
        return matriz[i][j];
    }

    // Paso Recursivo:
    // La suma del número de la fila anterior a la izquierda + el de la fila anterior arriba
    // Guardamos el resultado en la matriz para usarlo después.
    matriz[i][j] = calcularPascal(i - 1, j - 1) + calcularPascal(i - 1, j);
    
    return matriz[i][j];
}

int main() {
    int n;
    
    cout << "Ingrese el valor de n: ";
    cin >> n;

    // Inicializamos la matriz en 0 (muy importante para que funcione la memoria)
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            matriz[i][j] = 0;
        }
    }

    cout << "Matriz generada:" << endl;

    // Recorremos la matriz para imprimir y llamar a la función
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j > i) {
                // Si estamos arriba de la diagonal, imprimimos 0 directamente
                cout << "0\t"; 
            } else {
                // Si estamos dentro del triángulo, calculamos (o recuperamos) el valor
                cout << calcularPascal(i, j) << "\t";
            }
        }
        cout << endl; // Salto de línea al terminar la fila
    }

    return 0;
}