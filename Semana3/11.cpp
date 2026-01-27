#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char destino[5];
    char origen[] = "Programacion";

    strcpy(destino, origen);//Copia hasta encontra '\0', en este caso la cadena "agarra mucho" o sea se desborda
}
/*
destino es un arreglo de 5 caracteres. Puede almacenar máximo 4 caracteres visibles + '\0'

Copia hasta encontrar '\0'. No verifica tamaño. Resultado: Desbordamiento de memoria
*/