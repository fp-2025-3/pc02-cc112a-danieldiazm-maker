#include <iostream>
#include <string.h>

using namespace std;

int EstaBienEscrito(char *p) {
    int n = strlen(p);
    
    // Regla D: No espacios al inicio o final 
    if (*p == ' ') return 0;
    if (*(p + n - 1) == ' ') return n - 1;

    for (int i = 0; i < n; i++) {
        char c = *(p + i);

        // Regla A: Alfanuméricos o espacios
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == ' ')) {
            return i;
        }

        // Regla C: Solo un espacio entre palabras
        if (c == ' ' && *(p + i + 1) == ' ') return i + 1;

        // Regla B: Primera letra de cada palabra Mayúscula
        if (i == 0 || *(p + i - 1) == ' ') {
            if (c >= 'a' && c <= 'z') return i; // Debería ser mayúscula o número
        } else {
            // Caracteres internos de la palabra deben ser minúsculas
            if (c >= 'A' && c <= 'Z') return i;
        }
    }
    return -1; // Todo bien
}

int main() {
    char titulo[200];
    cout << "Ingrese titulo: ";
    cin.getline(titulo, 200);

    int pos = EstaBienEscrito(titulo);
    if (pos == -1) {
        cout << "Titulo bien escrito" << endl;
    } else {
        cout << "Error en la posicion " << pos << endl;
    }

    return 0;
}