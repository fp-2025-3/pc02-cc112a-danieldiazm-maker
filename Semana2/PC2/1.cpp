#include<iostream>
using namespace std;

int main(){
    int m[]={1,2,3,4,5};
    int (*arr)[5]= &m; //Apuntando a un matriz de 5 elementos enteros

    cout<<"Direccion del arreglo: "<<arr<<endl; //Me da la referencia (arreglo) (primer elemento)
    cout<<"Direccion del arreglo: "<<arr+1<<endl; //Me da la referencia (arreglo + cantidad de la unidad(20 byts)) (primer elemento + 20 byts)
    cout<<"Primer elemento del arreglo: "<<*arr<<endl; //Lo desreferencia y me da la referencia (primer elemento)
    cout<<"Primer elemento del arreglo: "<<*arr+5<<endl; //Lo desreferencia y me da la referencia (primer elemento + 5 unidades(4 byts))
    cout<<"Primer elemento del arreglo: "<<*(*arr+1)<<endl; //Lo desreferencia y me da el valor(lo desreferencia y me da la referencia (primer elemento))
    cout<<"Primer elemento del arreglo: "<<(*arr)[0]<<endl; //Lo desreferencia(arreglo) y me da el valor de posicion 0) 

    return 0;
}