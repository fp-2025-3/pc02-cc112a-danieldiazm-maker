#include<iostream>
using namespace std;

void rellenar_arreglo(int arr[], int n){
    for(int i = 0; i < n; i++){
        do{ // Implementamos funcion do-while primero actua luego piensa 
            cout << "Digite el elemento " << i+1 << ": ";
            cin >> arr[i];
            if(arr[i] < 1){
                cout << "Error: Debe ser un entero positivo." << endl;
            }
        }while(arr[i] < 1);
    }
}

// Elimine el ordenamiento Burbuja ya que no es necesaria y solo hace mas dificil todo

int recursiva(int arr[], int n, int pos){
    if (pos == n){
        return 0;
    }

    int costoMaximo = 0;
    int Vseg = 1;

    for (int j = pos; j < n; j++){
        Vseg *= arr[j];

        int Esta_1 = Vseg + recursiva(arr, n, j + 1);

        // Guardamos el mayor valor
        if (Esta_1 > costoMaximo){
            costoMaximo = Esta_1;
        }
    }

    return costoMaximo;
}

int main(){
    int n = 0;
    
    while(n < 1 || n > 15){
        cout << "Digite el tamaño del arreglo: "; 
        cin >> n;
        if(n < 1 || n > 15){
            cout << "Error: El tamaño tiene que estar entre 1-15" << endl;
        }
    }

    int* A = new int[n];
    rellenar_arreglo(A, n);
    
    cout << "Costo maximo: " << recursiva(A, n, 0) << endl;

    delete [] A;

    return 0;
}