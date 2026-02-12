#include<iostream>
using namespace std;

int SuperDigito(int);

int main(){
    int n=0;
    cout<<"Digite el numero que desea obtener su Super Digito: ";
    cin>>n;
    
    cout<<"El Super Digito es: "<<SuperDigito(n)<<endl;

    return 0;
}
int SuperDigito(int n){
    if(n>=0 && n<10){
        return n;
    }
    return SuperDigito(n%10+SuperDigito(n/10));
/*
5926%10=6
5926/10=592
592%10=2
y asi ...

123%10=3
123/10=12
12%10=2


*/
}