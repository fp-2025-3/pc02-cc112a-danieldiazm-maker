#include<iostream>
using namespace std;

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
        
    if(i == n){
        if(Esta_1(arr,n,k)){
            return (Vseg+1);
        }
        else{
            return Vseg;
        }
    }

    if(n == 1){
        return Vseg;
    }
    return recursiva(arr,n,i,Vseg);
}

int main(){
    int A[] = {2,1,3};
    int n = sizeof(A)/sizeof(A[0]); // 3
    int Vseg = 1;
    int i = 0;

    Burburja(A,n);
    cout<<"Costo maximo: "<<recursiva(A,n,i,Vseg)<<endl;

    return 0;
}