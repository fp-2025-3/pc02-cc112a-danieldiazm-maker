#include<iostream>
using namespace std;

void burburja(int[],int);
void imprimir(int[],int);

int main(){
    int arr[]={10,2,23,45,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    burburja(arr,n);
    imprimir(arr,n);
    return 0;
}
void burburja(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
void imprimir(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}