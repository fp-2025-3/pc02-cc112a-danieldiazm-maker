#include<iostream>
using namespace std;

bool esVocal(char c){ // Función para verificar si un caracter es una vocal
    if (c >= 'A' && c <= 'Z'){
        c = c + 32; // De mayuscula a minuscula
    } 
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'); // Retorna 1 si se cumple una de las cinco condiciones, sino se cumple ninguna retorna 0
}

int contarVocalesInicio(char* cadena){
    char* p = cadena; // Puntero a caracter se iguala a la referencia de un caracter
    int contador = 0; // Contador de palabras que comienzan en vocal
    bool nuevaPalabra = true; // Para saber si estamos al inicio de una palabra(true) caso contrario(false)

    while (*p != '\0') {
        if (*p != ' '){ // Se ejecuta si no estamos en un espacio
            if (nuevaPalabra){ 
                if (esVocal(*p)){ // Verificamos si el caracter es un vocal o no
                    contador++;
                }
                nuevaPalabra = false; // Como ya estamos en la palabra no contamos el resto de las letras
            }
        } 
        else{
            nuevaPalabra = true; // Si encontramos un espacio sabemos, seguimos avanzando hasta encontrar el inicio de una palabra
        }
        p++; // Para ir avanzando en la palabra
    }
    return contador;// Imprimimos cuantas palabras encontramos
}

int main() {
    char cadena[] = "     Este es    un  ejemplo en C++   END";
    
    cout << "texto: " << cadena << endl;
    
    int resultado = contarVocalesInicio(cadena);
    
    cout << "Numero de palabras que comienzan en vocal: " << resultado << endl;

    return 0;
}