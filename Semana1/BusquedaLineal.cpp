#include<iostream>
using namespace std;

int busquedaLineal(int[],int,int);

int main(){
    int arr[]={10,2,23,45,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int valor = 0;

    cout<<"Digite el numero que desea saber si esta en el arreglo: ";
    cin>>valor;

    if(busquedaLineal(arr,n,valor)==-1){
        cout<<"El numero no se encuenta en el arreglo";
    }
    else{
        cout<<"El numero si se encuentra en el arreglo y esta en la posicion: "<<busquedaLineal(arr,n,valor);
    }

    return 0;
}
int busquedaLineal(int arr[], int n, int valor){
    for(int i = 0; i < n; ++i){
        if(valor == arr[i]){
        return i;
        }
    }
    return -1;
}