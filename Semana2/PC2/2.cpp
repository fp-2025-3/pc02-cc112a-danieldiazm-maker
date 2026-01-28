#include<iostream>
using namespace std;

int main(){
    int m[]={1,2,3,4,5}; // arr[i] == *(arr+i) & (*arr)[i] = *((*arr)+i)
    int *arr = m; //Apuntando a un entero (Primer valor) arr=Referencia *arr=Desreferenciando

    cout<<"Direccion del arreglo: "<<arr<<endl; //Me da la referencia (arreglo) (primer elemento)
    cout<<"Direccion del arreglo: "<<arr+1<<endl; //Me da la referencia (arreglo + cantidad de la unidad(20 byts)) (primer elemento + 20 byts)
    cout<<"Primer elemento del arreglo: "<<*arr<<endl; //Lo desreferencia y me da la referencia (primer elemento)
    cout<<"Primer elemento del arreglo: "<<*arr+4<<endl; //Lo desreferencia y me da la referencia (primer elemento + 5 unidades(4 byts))

    return 0;
}