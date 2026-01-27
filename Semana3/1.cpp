#include <iostream>
using namespace std;

int main() {
    char c1 = 'A';
    char c2 = 'a';
    char c3 = '0';

    cout << (int)c1 << endl; // Con (int)c1 me da el valor 'ASCII' del char c1
    cout << (int)c2 << endl;
    cout << (int)c3 << endl;

    char x = '9'; // En ASCII '9' == 57;

    if (x > '5') { // // En ASCII '5' == 53;
        cout <<"MAYOR"<<endl;
        cout << x <<endl; /*Aquí, no se comparan cifras, se comparan códigos ASCII

        */
    }
    
}