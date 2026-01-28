#include <iostream>
using namespace std;

// & con eso se pasaba con referencia pero ahora con ---* = &---- podremos pasar punteros (apuntan)

int main() {
    int a = 42;  // Variable en la memoria stack
    int* ptr = &a; // ptr guarda la dirección de a //&a Doy la direccion de a,
    double d = 3.14;
    
    cout << "Valor de a: " << a << endl; //
    cout << "Dirección de a: " << &a << endl; //&a me da la direccion de a
    cout << "Valor desde el puntero: " << *ptr << endl; //*X me da el valor almacenado en la direccion de X
    cout << "Direccion de a: " << ptr <<endl; //Direccion de a solo con la variable a

    cout << "\n";

    double* pd;    // puntero sin inicializar (cuidado)
    pd = &d;       // ahora apunta a d

    cout << "Direccion de pd: " << pd <<endl;
    cout << "Valor de d: "<< *pd <<endl; // (*pd valor) (pd direccion) cuando ----* pd = &(alguna variable)

    cout << "\n";

    int y = 5;
    int* py = &y;

    cout << "Dirección de y: " << &y << endl;
    cout << "Valor de y via puntero: " << *py << endl;
    *py = 10;  // cambia y a través del puntero 
    //(generamos un *py=10 el cual es un puntero y reemplazamos el valor de la direccion de y)
    cout << "Nuevo valor de y: " << y << endl;
   
    return 0;
}