#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char texto[20] = "Hola";
    cout << strlen(texto) << endl; //Va contanto a cadena de caracteres hasta '\0'
}
/*
Cuenta caracteres antes de '\0'. No incluye el terminador

Si no hay '\0' produce comportamiento indefinido

strlen no sabe de tamaños, solo busca el caracter nulo.

*/