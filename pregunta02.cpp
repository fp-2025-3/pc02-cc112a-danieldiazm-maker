#include <iostream>
using namespace std;

// Complete la funcion de busqueda
int* buscar(
    int* inicio,                 // Estos dos primeros parametros
    int* fin,                    // delimitan el rango de busqueda a [inicio, fin)
    bool (*equivale)(int, int),  // equivale es una funcion que determina cuando dos enteros se condideran equivalentes
    int clave                    // clave es el valor a buscar segun el criterio indicado
) {
    // Complete aqui 
    for(int* i = inicio; i < fin ; ++i){
        if(1 == equivale(clave , *i)){
            return i;
        }
    }
    return 0;
}
bool igual(int A,int B){
    return A==B; //Verdadero =1, Falso=0;
}
bool mismaParidad(int A,int B){
    return ( A%2==B%2 || -A%2==B%2); //Verdadero =1, Falso=0;
}
bool divide(int A,int B){
    return (A%B==0); //Verdadero =1, Falso=0;
}
bool CantidadDigitos(int A,int B){
    return ( A/B >= 0 && A/B <= 9); //Verdadero =1, Falso=0;
}
bool mismoResiduoMod5(int A,int B){
    return ( A%5==B%5); //Verdadero =1, Falso=0;
}

// Implemente aqui los Criterios de equivalencia
// y si es necesario algunas funciones adicionales para reproducir el ejemplo de salida



int main() {
    int A[] = { -1, 21, 2, -2, 8, 13, 25 };
    int* inicio = A;
    int* fin = A + 7;

    int clave = 13;

    // Imprima el arreglo
    cout << "Arreglo: ";
    for(int i=0;i<7;i++){
        cout << *(inicio+i) << " ";
    }
    cout << "\n\nClave: " << clave << "\n\n";

    // Llame a la funcion buscar para cada criterio implementado

    
    cout<<"Igualdad exacta: encontrado valor: "<<*buscar(inicio,fin,igual,clave)<<" Pos: "<<buscar(inicio,fin,igual,clave)<<endl;
    cout<<"Misma paridad: encontrado valor: "<<*buscar(inicio,fin,mismaParidad,clave)<<" Pos: "<<buscar(inicio,fin,mismaParidad,clave)<<endl;
    cout<<"Divide a: encontrado valor: "<<*buscar(inicio,fin,divide,clave)<<" Pos: "<<buscar(inicio,fin,divide,clave)<<endl;
    cout<<"Misma cantidad de digitos: encontrado valor: "<<*buscar(inicio,fin,CantidadDigitos,clave)<<" Pos: "<<buscar(inicio,fin,CantidadDigitos,clave)<<endl;
    cout<<"Mismo residuo modulo 5: encontrado valor: "<<*buscar(inicio,fin,mismoResiduoMod5,clave)<<" Pos: "<<buscar(inicio,fin,mismoResiduoMod5,clave)<<endl;

    return 0;
}
