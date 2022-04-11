
//
// Created by wyl on 2022/1/21.
//

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 200907;

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
    int t;
    scanf("%d", &t);
    while (t--) {
        ll a, b, c, k;
        scanf("%lld%lld%lld%lld", &a, &b, &c, &k);
        if (2 * b == a + c) {
            ll d = b - a;
            ll a0 = a - d;
            ll res = a0 + k * d;
            printf("%lld\n", (res) % mod);
        } else {
            ll q = b / a;
            ll res = (a * qmi(q, k - 1)) % mod;
            printf("%lld\n", res);
        }
    }
}