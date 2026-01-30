/*
Ejercicio 01
Implementar un programa que:

Identifique todas las palabras en un arreglo char texto[].

Almacene punteros al inicio de cada palabra en un arreglo char* palabras[].

Clasifique las palabras en dos grupos:

palabras cortas (longitud ≤ 3)
palabras largas (longitud > 3)
Imprima ambos grupos ordenados alfabéticamente.
*/

#include <iostream>
using namespace std;



//swap(v[j], v[j+1]); // EJERCICIO, implementar su propia funcion intercambio

int separar_palabras(char* texto, char* palabras[]) {

    int i = 0;  // contador de palabras
    char *p = texto; // almacena la dirección del primer caracter en texto

    while (*p != '\0') {
        if ((p==texto && *p != ' ') || (*(p-1) == ' ' && *p != ' ' ) ){ // Se usa p==texto guarda la direccion de la primera letra de cada palabra
            palabras[i] = p;                                            

            i++;
        }

        p++;

    }

    return i;
}


int longitud_palabra(const char *p){
    int longitud = 0;

    while (*p != ' ' && *p != '\0') {
        longitud++; // Va viajando en la palabra y me retorna su longitud 
        p++;
    }

    return longitud;

}

void clasificar(char* palabras[], int n, char* cortas[], int& nc, char* largas[], int& nl){

    // recorrer el arreglo de punteros palabras
    // Clasificar segun su longitud 

    int  indLargas = 0 , indCortas = 0; // Inicializamos en 0 como buena practica de programacion

    for (int i = 0; i < n ; ++i){ //

        int longitud = longitud_palabra(palabras[i]); // Me da la longitud de la palabra de pos i 

        if (longitud <= 3) {
            cortas[indCortas] = palabras[i];
            indCortas++;
            nc++;

        } else {
            largas[indLargas] = palabras[i];
            indLargas++;
            nl++;

        }
    }

}

int comparar_palabras(const char* a, const char* b) {

    int i = 0;

    while (a[i] != ' ' && a[i] != '\0' && b[i] != ' ' && b[i] != '\0') { // Corre en ambas palabras y compara letra por letra hasta que se termine una completamento o ' ' 
        
        if (a[i] != b[i]) {
            return a[i] - b[i]; 
        }

        i++;
    }

    if ((a[i] == ' ' || a[i] == '\0') && (b[i] == ' ' || b[i] == '\0')) { // Compara si despues de terminar haya '\0' o ' '
        return 0;
    }

    if ((b[i] == ' ' || b[i] == '\0')) { // Mira si b tiene como final ' ' o '\0' en caso sea asi dice que esta es menor entonces retorna un numero positivo
        return 1;
    }

    return -1; // Caso contrario retorna un numero negativo diciendo que a termina en ' ' o '\0' o sea que es más corta  

}
/*
char letra = 'A';
cout << letra;        // Imprime: A
cout << (int)letra;   // Imprime: 65

No olvidar
*/

void intercambio(char* &a,char* &b){
    char *p = a;
    a=b;
    b=p;
}

void ordenar(char* v[], int n) {

    for (int i = 0; i < n - 1; ++i) { // numero de pasadas                       // Algr Burbuja 
        for (int j = 0; j < n - i - 1; ++j) { // intercambios
            if (comparar_palabras(v[j], v[j+1]) > 0) {
                intercambio(v[j],v[j+1]);
            }
        }
    }

}



void imprimir_grupo(const char* titulo, char* v[], int n) {
    cout << "Palabras " << titulo << endl;
    for (int i = 0; i < n; ++i) {
        char* p = v[i];

        while (*p != ' ' && *p != '\0'){ // Esto ahce que recorra la palabra y que cuando encuentre un espacio pare e imprima la siguiente palabra p++ simplemente hace que se mueva en la palabra
            cout << *p; 
            p++;
        }
        cout << endl; // Salto de linea para separar palabras
    }
}



int main(){

    char texto[300] = "Programar en C++ requiere logica C++ exige disciplina";
    char* palabras[60];
    char* cortas[60];
    char* largas[60];

    int  n = separar_palabras(texto, palabras);
    int nc = 0, nl = 0;


    imprimir_grupo("Originales:", palabras, n);

    clasificar(palabras, n, cortas, nc, largas, nl);

    cout << "\nCadena original texto:\n";
    cout << texto << endl;

    cout << endl;
    ordenar(cortas, nc);
    imprimir_grupo("Cortas:", cortas, nc);

    cout << endl;
    ordenar(largas, nl);
    imprimir_grupo("Largas:", largas, nl);

    return 0;
}