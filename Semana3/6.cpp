#include <iostream>
using namespace std;

int main() {
    char palabra[] = "PERU";
    char* p = palabra;

    cout<< p <<endl;
    cout<< *(p + 1) <<endl;
    /*
    p apunta a 'P' pero en cout p apuntara a "PERU" e imprima toda la cadena ya que lo toma como un char* y recorre todo

    p + 1 apunta a 'E'

    Se avanza 1 byte (sizeof(char))

    Sumar a un puntero es avanzar posiciones, no sumar números.
    */
}