#include <iostream>
using namespace std;

int main() {
    char c = 'D'; // Guarda el valor del caracter 'D' 68
    c = c + ('a' - 'A'); // Aritmetica de valores 68 + (97 - 65) == 68 + 32 == 100 
    cout<< c <<endl ; // c == 100 == 'd';
    //'a' - 'A' = 32
}