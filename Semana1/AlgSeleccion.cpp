#include<iostream>
using namespace std;

void seleccion(int[],int);
void imprimir(int[],int);

int main(){
    int arr[]={10,2,23,45,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    seleccion(arr,n);
    imprimir(arr,n);
    return 0;
}
void seleccion(int arr[], int n){
    for(int i = 0; i < n - 1; ++i){
    int indMin = i;
        for(int j = i + 1; j < n; ++j){
            if(arr[j] < arr[indMin]){
                indMin = j;
            }
        }
    swap(arr[i], arr[indMin]);
    }
}
void imprimir(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}