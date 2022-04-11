
//
// Created by wyl on 2022/1/22.
//

#include<bits/stdc++.h>

using namespace std;
const int N = 5e5 + 10;
typedef long long ll;
struct point {
    int idx, val;
} p[N];

int n;
ll res = 0;
int tr[N], rk[N];

int lowbit(int x) { return x & -x; }

void add(int x, int k) {
    for (int i = x; i <= n; i += lowbit(i))tr[i] += k;
}

ll ask(int x) {
    ll res = 0;
    for (int i = x; i > 0; i -= lowbit(i))res += tr[i];
    return res;
}

bool cmp(point p1, point p2) {
    if (p1.val == p2.val)
        return p1.idx < p2.idx;
    return p1.val < p2.val;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i].val);
        p[i].idx = i;

    }
    sort(p + 1, p + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        rk[p[i].idx] = i;
    }
    for (int i = 1; i <= n; i++) {
        res += i - 1 - ask(rk[i]);
        add(rk[i], 1);
    }
    printf("%lld", res);
}