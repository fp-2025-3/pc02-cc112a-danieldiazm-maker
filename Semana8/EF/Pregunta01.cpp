#include<iostream>
using namespace std;

int** crearMatriz(int n, int m){
    int **Matriz = new int*[n]; // *( *(Matriz + i) + j)
    *Matriz = new int[m];
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
    int *vector = new int(n);

    for (int i = 0; i < n; ++i){
        vector[i] = 0;
    }

    for (int i = 0; i < n; ++i){
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
void liberarMatriz(int** M, int n){
    delete [] M[n];
    delete [] M;
}

int main(){
    int n, m;
    cout << "Ingrese el numero de filas: ";
    cin >> n;
    cout << "Ingrese el numero de columnas: ";
    cin >> m;
    llenarMatriz(crearMatriz(n,m), n, m);
    Imprimir(sumaFilas(crearMatriz(n,m), n, m), n);
    liberarMatriz(crearMatriz(n,m), n);
    return 0;
}