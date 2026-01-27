#include<iostream>
using namespace std;

template<typename T>
void imprimirGenerico(const T&);

int main(){
    imprimirGenerico(5);
    imprimirGenerico(3.14);
    imprimirGenerico("Hola Mundo");
    return 0;
}

template<typename T>
void imprimirGenerico(const T& dato){
    cout<<"Dato: "<<dato<<endl;
}