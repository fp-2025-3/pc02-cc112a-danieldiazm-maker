#include <iostream>
using namespace std;

int main() {
    char paises[3][10] = { "Peru", "Chile","Brasil"};
    char (*p)[10]=paises;
    cout<<(*paises)<<endl; /*
    En paises[] ="Peru"; cou<<paises imprime: Peru
    En este caso *paises desreferencia y obtenemos "Peru" lo cual al cout<<*paises imprime: Peru
    */
    cout<<*(paises+1)<<endl;
    cout<<*(paises+2)<<endl;
    cout<<*p<<endl;
    /*
    paises es la referencia del primer elemento "Peru"
    *paises entro en la primera refencia y obtengo la refencia de P con lo que cout lo toma como char*
    e imprime toda la palabra Peru
    p es la referencia de "Peru"
    */
}