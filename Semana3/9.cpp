#include <iostream>
using namespace std;
int main(){
    int m;
    cin>>m;
    cin.ignore();
    char frase[50];
    cin.getline(frase, 50);
    cout<<m<<endl;
    cout<<frase<<endl;
    /*
    Lee hasta 49 caracteres (Aun asi pongas más, se detiene y solo lee 49 y agrega '\0')

    Agrega '\0'

    Es más segura

    Si el buffer está sucio, puede leer vacío. (use cin.ignore() para limpiar el buffer)
    */
}