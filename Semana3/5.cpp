#include <iostream>
using namespace std;

int main() {
    char texto[] = "Hola";
    char* p = texto; // Puntero a un char (Solo obtiene la referencia de la primera letra)

    cout<< *(p+2) <<endl; // Solo imprime *(p+2) porque desreferencia a (p+2)
    cout<< texto << endl; // Imprime toda la cadena porque degrada a char*
    cout<< p <<endl; // Imprime toda la cadena ya que p = texto
}