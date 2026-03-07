#include<iostream>
using namespace std;

int** crearMatriz(int n, int m){
    int **Matriz = new int*[n]; // *( *(Matriz + i) + j)
    for (int i = 0; i < n; ++i){
        Matriz[i] = new int[m]; // Se arreglo el error al guardar en todas las filas y no solo en una
    }
    return Matriz;
}
void llenarMatriz(int **M, int n, int m){
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            M[i][j] = (i + 1) * (j + 1);
        }
    }
}
int* sumaFilas(int** M, int n, int m){
    int *vector = new int[n]; // Error en la logica use () en vez de []

    for (int i = 0; i < n; ++i){ // Se reducio el bucle para que no haga una interacion de más
        vector[i] = 0;
        for (int j = 0; j < m; ++j){
            vector[i] += M[i][j];
        }
    }
    return vector;
}
void Imprimir(int* V, int n){
    cout << "El vector suma filas es: ";
    for(int i = 0; i < n;++ i){
        cout << V[i] << " ";
    }
    cout << endl;
}
void liberarMatriz(int** M, int n){ // Corrigiendo error al liberar memoria
    for(int i = 0; i < n; ++i){
        delete[] M[i]; // Primero liberamos memoria en cada fila
    }
    delete [] M; // Despues liberamos el principal
}

int main(){
    int n, m;
    cout << "Ingrese el numero de filas: ";
    cin >> n;
    cout << "Ingrese el numero de columnas: ";
    cin >> m;

    int** Matriz = crearMatriz(n,m); // Una recomendacion para un mejor ordenamiento y para poder comprender el codigo es asignado los valores de retorno a variables

    llenarMatriz(Matriz, n, m);

    int* Vector = sumaFilas(Matriz, n, m);

    Imprimir(Vector, n);

    liberarMatriz(Matriz, n);

    delete[] Vector;

    return 0;
}