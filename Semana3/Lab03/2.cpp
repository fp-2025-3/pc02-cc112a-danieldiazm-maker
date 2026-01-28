/*
Implementar un programa que:

Identifique cada palabra dentro del arreglo frase.
Guarde punteros al inicio de cada palabra, sin copiar caracteres.
Use un arreglo de punteros a char (char* palabras[]).
Ordene las palabras alfabéticamente, intercambiando solo punteros.
Imprima las palabras ordenadas leyendo desde los punteros.
*/
#include<iostream>
using namespace std;

int separar_palabras(char* frase, char* palabras[]){
    char *p=frase;
    int i = 0;
    while(*p != '\0'){
        if( (p == frase && *p == ' ') || (*(p-1) == ' ' && *p != ' ')){
            *(palabras+i)= p;
        }
    }



}
int comparar(const char* a, const char* b);
void ordenar(char* palabras[], int n);
void imprimir(char* palabras[], int n);

int main(){
    char frase[] = "aprender punteros exige mucha logica y practica";
    char* palabras[50];  // arreglo de punteros a palabras


    return 0;
}