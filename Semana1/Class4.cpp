#include<iostream>
using namespace std;

void ModificaArr(int[],int);

int main(){
    int arr[]={1,2,3,4,5};
    int tamano = sizeof(arr)/sizeof(arr[0]);
    ModificaArr(arr,tamano);
    
    cout<<"Array modificado: ";
    for(int i=0;i<tamano;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}

void ModificaArr(int arr[],int n){
    for(int i=0;i<n;i++){
        arr[i]*=2;
    }
}