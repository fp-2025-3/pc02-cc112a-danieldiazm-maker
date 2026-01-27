#include<iostream>
using namespace std;

void duplicarvalor(int&);

int main(){
    int x = 0;
    cout<<"Digite el numero que desea duplicar: ";
    cin>>x;
    cout<<"\nEl numero a duplicar: "<<x<<endl;
    duplicarvalor(x);
    cout<<"Despues de llamar a la funcion: "<<x<<endl;
    return 0;
}
void duplicarvalor(int& x){
    x = x * 2;
    cout<<"Dentro de la funcion: "<< x <<endl;
}