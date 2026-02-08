#include<iostream>
using namespace std;

void tamaño(int &n){ 
    cout << "Digite el numero de elementos para el arreglo: ";
    cin >> n; // El usuario escribe 5, 100, o 1 millón.
}

void dinamica(int* &arreglo, int n){ 
    arreglo = new int[n]; /* usamos [n]. 
    Esto era imposible con arreglos estáticos.
    arreglo es un puntero que apunta al primer elemento de ese bloque en el Heap.*/
}

void rellenar(int* arreglo, int n){
    for(int i = 0;i < n; i++){
        cout<<"Rellene el arreglo en la pos "<<i<<": ";
        cin>>arreglo[i];
    }
}

int main(){
    int n; 
    tamaño(n);
    
    int* arreglo = nullptr; // Buena práctica: inicializar en null
    
    // Solo llamamos si n es válido
    if (n > 0) {
        dinamica(arreglo, n); // Ahora 'arreglo' apuntará al Heap de verdad
        rellenar(arreglo, n);
        cout << "El primer valor es: " << arreglo[0] << endl; 
        
        delete[] arreglo; // Borras correctamente
        arreglo = nullptr; // Buena práctica: terminar en null
    }

    return 0;
}