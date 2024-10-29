#include <iostream>
using namespace std;

int main() {
    int x = 10; // bits: 1010
    int y = 15; // bits: 1111
    int b = 3; // bits 0011

    int z = x >> 1; // 1010 -> 0101
    cout << z << endl;

    int a = z ^ b;
    cout << a;
}