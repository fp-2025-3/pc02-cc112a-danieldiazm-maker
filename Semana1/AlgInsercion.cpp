#include<iostream>
using namespace std;

void insercion(int[],int);
void imprimir(int[],int);

int main(){
    int arr[]={10,2,23,45,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    insercion(arr,n);
    imprimir(arr,n);
    return 0;
}
void insercion(int arr[], int n){
    for(int i = 1; i < n ; ++i){
        int temp = arr[i];
        int j = i-1;
        while(j>=0 && arr[j] > temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}
void imprimir(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}