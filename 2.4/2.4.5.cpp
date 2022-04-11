
//
// Created by wyl on 2022/2/4.
//

#include<bits/stdc++.h>

using namespace std;
map<int, int> s;
int n, start=0;

int main() {
    cin.sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, l, r;
        char c;
        cin >> a >> c;
        if (c == 'L') {
            s[start] --;
            start -= a;
            s[start] ++;
        } else {
            s[start] ++;
            start += a;
            s[start] --;
        }

    }
    int res = 0, sumn = 0, last;
    for (auto a: s) {
        if (sumn > 1) {
            res += a.first - last;
        }
        sumn += a.second;
        last = a.first;
    }
    cout << res << endl;
}