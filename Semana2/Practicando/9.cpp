#include <iostream>
using namespace std;

int main() {
    int matriz[2][3] = {{1,2,3},{4,5,6}};
    int (*p)[2][3] = &matriz;    /*Siempre recordar declarar la columna por jerarquia   
    
    Apunto a la matriz
    p  == Referencia de la matriz
    *p == Ingreso en la matriz y obtengo la referencia del primer elemento(fila)
    **p == Ingreso en la fila y obtengo la refencia del primer elemento(Entero)
    ***p == Ingresi en la refencia y obtengo el valor del primer elemento (1)
    
    */
    for(int j=0;j<2;++j){
        for(int i=0;i<3;++i){
            cout << (*p)[j][i] << " ";
        }
        cout<<endl;
    }
    cout<<*(**p+1);
        
}