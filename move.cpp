//
// Created by Ming Yu on 2022/3/16.
//



#include <iostream>

using namespace std;

int main() {
    int a = 1;
    int &aa = a;
    int b = 2;
    aa = b;
    aa = 3;
    cout << a << endl;
    cout << aa << endl;
    cout << b << endl;
    cout << aa << endl;
    cout << b << endl;

}
