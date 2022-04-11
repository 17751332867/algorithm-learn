
//
// Created by wyl on 2022/1/21.
//

#include<bits/stdc++.h>

using namespace std;
const int N = 1e6 + 10;
int n;
vector<int> primes;
bool used[N];

void get_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!used[i]) {
            primes.push_back(i);
            for (int j = 2; i * j <= n; j++) {
                used[i*j] = true;
            }
        }
    }
}

int main() {
    int n;
    get_primes(1e6);
    while (cin >> n && n) {
        for (int i = 0; i < primes.size(); i++) {
            int l = primes[i];
            int r = n - l;
            if (!used[l] && !used[r]) {
                printf("%d = %d + %d\n", n, l, r);
                break;
            }
        }
    }
}