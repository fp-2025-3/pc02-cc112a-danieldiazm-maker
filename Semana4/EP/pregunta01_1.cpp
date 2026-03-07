#include<iostream>
using namespace std;

void rellenar_arreglo(int arr[],int n){
    for(int i = 0;i < n; i++){
        cout<<"Digite el elemento "<<i+1<<": ";
        cin>>arr[i];
    }
}
void Burburja(int arr[],int n){
    for(int i = 0;i < n - 1; i++){
        for(int j = 0;j < n - 1 - i;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }   
    }
}
bool Esta_1(int arr[],int n, int k){
    for(int i = 0;i < n; i++){
        if(arr[i] == k){
            return true;
        }
    }
    return false;
}
int recursiva(int arr[],int n,int i,int Vseg){
    
    int k = 1;

    Vseg = Vseg * arr[i];
    i++;
    
    if(n == 1){
        return Vseg;
    }
    if(i == n){
        if(Esta_1(arr,n,k)){
            return (Vseg+1);
        }
        else{
            return Vseg;
        }
    }

    return recursiva(arr,n,i,Vseg);
}

int main(){
    int n = 0;
    int Vseg = 1;
    int i = 0;
    while(n < 1 || n > 15){
        cout<<"Digite el tamaño del arreglo: "; // 2 3 5 7 9 // 2 3 // 5 7 // 9 ; Valores --> //6 //35 //9 costo total --> // 6 + 35 + 9 = 50
        cin >> n;
        if(n < 1 || n > 15){
            cout<<"Error: El tamaño tiene que estar entre 1-15"<<endl;
        }
    }
    int* A = new int[n];
    rellenar_arreglo(A,n);
    Burburja(A,n);
    cout<<"Costo maximo: "<<recursiva(A,n,i,Vseg)<<endl;
    delete [] A;

    return 0;
}