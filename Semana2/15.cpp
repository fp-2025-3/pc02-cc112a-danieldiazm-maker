#include <iostream>
using namespace std;

int main() {
    int arr[3] = {10,20,30};
int* p = arr;

cout << *p+1 << endl;   // 11  (*p)+1
cout << *(p+1) << endl; // 20

}