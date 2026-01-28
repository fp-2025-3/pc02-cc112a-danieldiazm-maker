#include <iostream>
using namespace std;
int main(){
    char nombre[10];
    cin >> nombre;
    cout<<nombre<<endl;
    // El código puede detener el programa sin avisar
    /*
    Problemas:

    No controla tamaño

    Puede sobrescribir memoria

    Provoca buffer overflow
    */
}