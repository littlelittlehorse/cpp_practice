//
// Created by Ming Yu on 2022/3/18.
//

#include <iostream>

using namespace std;

const int maxn = 1e5 + 7;

int c[maxn];

int lowbit(int x) {
    return x & (-x);
}

void add(int x, int k) {
    while (x < maxn) {
        c[x] += k;
        x += lowbit(x);
    }
}

int getsum(int x) {
    int sum = 0;
    while (x > 0) {
        sum += c[x];
        x -= lowbit(x);
    }
    return sum;
}


