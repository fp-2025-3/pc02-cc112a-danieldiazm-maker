#include <iostream>
using namespace std;

void Imprimir(int (*Matriz)[5], int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(*(*(Matriz+i)+j) >= 0){
                cout<<" ";
            }
            cout<<*(*(Matriz+i)+j)<<"\t";
        }
        cout << endl;
    }
}

// Función que determina si una posición (i, j) es un pico
bool esPico(int (*Matriz)[5], int n, int m, int i, int j) {
    int actual = *(*(Matriz+i)+j);
    bool mayorOIgualAtodos = 1;
    bool estrictamenteMayorQueUno = 0;

    // Vecino Arriba (i-1, j)
    if (i > 0) {
        int arriba = *(*(Matriz+i-1)+j);
        if (actual < arriba) mayorOIgualAtodos = 0;
        if (actual > arriba) estrictamenteMayorQueUno = 1;
    }
    // Vecino Abajo (i+1, j)
    if (i < n - 1) {
        int abajo = *(*(Matriz+i+1)+j);
        if (actual < abajo) mayorOIgualAtodos = 0;
        if (actual > abajo) estrictamenteMayorQueUno = 1;
    }
    // Vecino Izquierda (i, j-1)
    if (j > 0) {
        int izquierda = *(*(Matriz+i)+j-1);
        if (actual < izquierda) mayorOIgualAtodos = 0;
        if (actual > izquierda) estrictamenteMayorQueUno = 1;
    }
    // Vecino Derecha (i, j+1)
    if (j < m - 1) {
        int derecha = *(*(Matriz+i)+j+1);
        if (actual < derecha) mayorOIgualAtodos = 0;
        if (actual > derecha) estrictamenteMayorQueUno = 1;
    }

    return mayorOIgualAtodos && estrictamenteMayorQueUno; //Return 1 si ambas son verdaderas Return 0 si ambas son falsas
}

// Función que recorre la matriz e imprime los picos
void imprimirPicos(int (*Matriz)[5], int n, int m) {
    cout << "Elementos pico:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (esPico(Matriz, n, m, i, j)==1) {
                cout << "Pico en (" << i << "," << j << "): " << *(*(Matriz+i)+j) << endl;
            }
        }
    }
}

int main() {
    int Matriz[][5] = {{3, 3, 3, 3, 3},{3, 4, 4, 2, 3},{3, 4, 5, 4, 3},{3, 3, 3, 3, 3}};
    int (*p)[5]=Matriz;
    int n = sizeof(Matriz)/sizeof(*Matriz);
    int m = sizeof(*p)/sizeof(*(*p));

    cout << "Matriz:" << endl;
    Imprimir(p, n, m);
    cout << endl;

    imprimirPicos(p, n, m);

    return 0;
}