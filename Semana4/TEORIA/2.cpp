#include<iostream>
using namespace std;
void f(int *y) {
    int x = 10;        // stack
    y = new int; // heap
    delete y;
    cout<<*y<<endl;
    cout<<x<<endl;
}
int main(){
    int p[] ={1,2,3,4,5};
    f(p);

    return 0;
}