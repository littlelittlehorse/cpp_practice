//
// Created by Ming Yu on 2022/3/14.
//

#include <iostream>

using namespace std;

class A {
public:
    A() {
        cout << "A's constructor" << endl;
    }

    ~A() {
        cout << "A's destructor" << endl;
    }

    void show() {
        cout << "num:" << num << endl;
    }


public:
    int num;
};

int main() {
    char mem[100];
    mem[0] = 'B';
    mem[1] = '\0';
    mem[2] = '\0';
    mem[3] = '\0';
    cout << mem << endl;


    cout << (void *) mem << endl;
    A *p = new(mem) A;
    A *pp = new(mem) A;

    cout << p << endl;
    p->show();
    p->~A();
    p->num = 65;

    cout << pp << endl;
    pp->show();
    pp->~A();

    cout << mem << endl;
    cout << "!!!" << endl;
}

/*
 * placement new 实现的是在给定地址上，申请对象的内存，但没有管理内存。
 * 即:
 *  A *p = new(mem) A;
 *  A *pp = new(mem) A;
 *  pp 会覆盖 p。
 */
