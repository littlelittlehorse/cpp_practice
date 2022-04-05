#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> odd, even;

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        if (i & 1) odd.push_back(i);
        else even.push_back(i);
    }
    int d = 1, need = 1;
    vector<int> ans;
    while (n >= need) {
        if (d & 1) {
            int sz = min(need, int(even.size()));
            for (int i = 0; i < sz; i++) {
                ans.push_back(even.back());
                even.pop_back();
            }
            for (int i = sz + 1; i <= need; i++) {
                ans.push_back(odd.back());
                odd.pop_back();
            }

        } else {
            int sz = min(need, int(odd.size()));
            for (int i = 0; i < sz; i++) {
                ans.push_back(odd.back());
                odd.pop_back();
            }
            for (int i = sz + 1; i <= need; i++) {
                ans.push_back(even.back());
                even.pop_back();
            }
        }
        n -= need;
        need *= 2;
        d += 1;
    }
    while (!even.empty()) {
        ans.push_back(even.back());
        even.pop_back();
    }

    while (!odd.empty()) {
        ans.push_back(odd.back());
        odd.pop_back();
    }

    for (int i = 0; i < int(ans.size()); i++) {
        printf("%d%c", ans[i], i == int(ans.size()) - 1 ? '\n' : ' ');
    }


    string s1, s2;
    if (s1 == s2) {
        
    }
}
