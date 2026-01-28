#include<iostream>
using namespace std;

double areaRectangulo(double,double);

int main(){
    double base = 0,altura = 0;
    cout<<"Digite la longitud de la base del rectangulo: ";
    cin>>base;
    cout<<"Digite la longitud de la altura del rectangulo: ";
    cin>>altura;
    cout<<"El area del rectangulo es: "<<areaRectangulo(base,altura);

    return 0;
}
double areaRectangulo(double base,double altura){
    return base * altura;
}