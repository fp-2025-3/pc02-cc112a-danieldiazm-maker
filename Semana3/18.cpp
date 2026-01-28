#include <iostream>
using namespace std;

int main() {
}
/*
1. Funciones de Clasificación (¿Qué es esto?)
Estas funciones devuelven un valor booleano (verdadero/falso). En C++, devuelven un entero distinto de cero si es cierto, y 0 si es falso.

isalpha(c): Verifica si es una letra (A-Z o a-z).

char car = 'G';
if (isalpha(car)) cout << "Es una letra"; //Como es verdad imprime 



isdigit(c): Verifica si es un número (0-9).

char n = '5';
if (isdigit(n)) cout << "Es un digito"; //Como es verdad imprime 



isalnum(c): Verifica si es alfanumérico (letra o número). Útil para nombres de usuario.

char id = '@';
if (!isalnum(id)) cout << "No es alfanumerico"; // El '@' fallaría aquí




islower (¿Es minúscula?):

char c = 'b';
if (islower(c)) cout << "Esta en minuscula";



isupper (¿Es mayúscula?):

char c = 'B';
if (isupper(c)) cout << "Esta en mayuscula";



isspace(c): Verifica "espacios en blanco" (espacio, \t, \n, \r).

char space = '\t';
if (isspace(space)) cout << "Es un espacio o tabulacion";



2. Funciones de Conversión (¡Cámbialo!)
Como bien notaste, estas funciones no modifican el original, sino que te entregan una "copia" transformada. Si no guardas el resultado, se pierde.

toupper(c): Pasa a MAYÚSCULA.

tolower(c): Pasa a minúscula.

Ejemplo de uso correcto vs. incorrecto:

char letra = 'a';

tolower(letra);            // INCORRECTO: El resultado se pierde. 'letra' sigue siendo 'a'.
letra = toupper(letra);    // CORRECTO: Ahora 'letra' vale 'A'.



CUIDADO: No modifican la variable original:

A menos que lo aclaremos: 

c = tolower(c);
*/