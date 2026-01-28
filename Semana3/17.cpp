#include <iostream>
using namespace std;

int main() {
    char palabra[] = "Hola"; //const char* p = "Hola"; para si deseamos que no se pueda tocar esta cadena 
    palabra[0] = 'h';   // correcto
    cout<<palabra<<endl;
}