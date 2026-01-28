#include <iostream>
using namespace std;

int main() {
    char arr1[6] = {'H','o','l','a','!'}; /*    Una cadena válida debe terminar en '\0'. 
                                                Espacio en blanco es igual a '\0'?        */
    char arr2[5] = "Hola";

    char palabra[] = "UNI";
    /*
    "UNI" tiene 3 caracteres visibles

    pero 4 posiciones en memoria

    La cadena termina cuando aparece el cero (caracter nulo '\0')
    */

    cout<<arr1<<endl;
    cout<<arr2<<endl;
    cout<<palabra<<endl;
}