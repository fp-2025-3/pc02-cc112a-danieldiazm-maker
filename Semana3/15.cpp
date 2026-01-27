#include <iostream>
using namespace std;

int main() {
    const char* paises[] = {"Peru","Chile","Brasil"}; //Es un arreglo que tiene como elementos a punteros char constantes
    cout<<*paises<<endl; //Desreferencia a "Peru" e imprime a todo "Peru" al ser tomado por el
}