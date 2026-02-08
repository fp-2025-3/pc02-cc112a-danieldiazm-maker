#include<iostream>
using namespace std;

// Parte 1
void CreateVector(int*& vec,int size){
    vec = new int[size];
}
void ReadArray(int* vec, int size){
    for (int i = 0; i < size; i++){
        cout << "Ingrese el valor para el elemento "<<i+1<<" del arreglo: ";
        cin >> *(vec+i);
    }
}
void PrintArray(int* vec,int size){
    for (int i = 0; i < size; i++){
        if(i == size-1){
            cout << *(vec+i);
        }
        else{
            cout << *(vec+i) << " ";
        }
    }
}
void DestroyVector(int*& vec){ // Se pone & ya que estamos cambio la referencia del puntero y queremos que se devuelva como nullptr
    delete [] vec;
    vec = nullptr;
}

// Parte 2
void Intercambiar(int*& vec1,int*& vec2){ // Se pone & ya que estamos cambiando la referencia del puntero por la del otro y deseamos que conserve la referencia
    swap(vec1,vec2);
}

// Parte 3
void intercambiar(int& vec1,int& vec2){ // Se pone & ya que estamos cambiando el valor del int por la del otro y deseamos que conserve el valor
    swap(vec1,vec2);
}
void BurbujaRecursivo(int* arr, int n, int tamano_orignial){ // 1 5 8 9 14 1 2 4 5 6
    static char p = ' ';
    if(n == tamano_orignial){
        while(p != 'A' && p && 'a' && p != 'D' && p != 'd'){
            cout<<"Ordenamiento Ascendente o Descendente A/D: ";
            cin>>p;
            if(p != 'A' && p && 'a' && p != 'D' && p != 'd'){
                cout<<"Error: Opcion no valida. Intente denuevo. "<<endl;
            }
        }
    }

    if(n <= 1){
        return;
    }

    for(int j = 1; j < n; ++j){
        if(p == 'A' || p == 'a'){
            if( arr[j] < arr[0] ){ // 1 3 2 5 // 1 3 2 5 // 1 3 2 5 // 3 2 5 // 2 3 5 // 2 3 5 // 3 5 // 3 5 --> 1 2 3 5 Ascendente
                intercambiar(arr[0], arr[j]);
            }
        }
        else if(p == 'D' || p == 'd'){
            if( arr[j] > arr[0] ){ // 1 3 2 5 // 3 1 2 5 // 5 1 2 3 // 1 2 3 // 2 1 3 // 3 1 2 // 1 2 // 2 1 --> 5 3 2 1 Descendente
                intercambiar(arr[0], arr[j]);
            }
        }
    }
    BurbujaRecursivo(arr+1, n-1, tamano_orignial);
}


int main(){
    int *vec1 = nullptr, size = 10;
    int *vec2 = nullptr;
    CreateVector(vec1, size); // Crear la memoria para este puntero
    cout<<"Primer arreglo"<<endl;
    ReadArray(vec1, size); // Lee los datos desde el cin
    BurbujaRecursivo(vec1, size, size); // Funcion definida arriba
    cout<<"Primer arreglo ordenado: "<<endl;
    PrintArray(vec1, size); // Imprime los datos en el cout
    cout<<"\n\n";
    CreateVector(vec2, size); // Crear la memoria para este puntero
    cout<<"\nSegundo arreglo"<<endl;
    ReadArray(vec2, size); // Lee los datos desde el cin
    BurbujaRecursivo(vec2, size, size); // Funcion definida arriba
    cout<<"Segundo arreglo ordenado: "<<endl;
    PrintArray(vec2, size);
    cout<<"\n\n";

    Intercambiar(vec1, vec2); // Parte 2 del ejercicio
    cout<<"\nNuevo primer arreglo intercambiado: "<<endl;
    PrintArray(vec1, size);
    cout<<"\nNuevo segundo arreglo intercambiado: "<<endl;
    PrintArray(vec2, size);
    cout<<endl;
    DestroyVector(vec1); // Destruye el vector y deja en nullptr vec1
    DestroyVector(vec2); // Destruye el vector y deja en nullptr vec2

    return 0;
}