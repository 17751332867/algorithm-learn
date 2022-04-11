
//
// Created by wyl on 2022/1/21.
//

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 100003;

ll qmi(ll a, ll q) {
    ll res = 1;
    while (q) {
        if (q % 2 == 1)res = (res * a) % mod;
        a = (a * a) % mod;
        q /= 2;
    }
    return res;
}

int main() {
    ll m, n;
    scanf("%lld%lld", &m, &n);
    ll tot = qmi(m, n);
    ll sumn = (m * qmi(m - 1, n - 1)) % mod;
    ll res = (tot - sumn + mod) % mod;
    printf("%lld", res);
}