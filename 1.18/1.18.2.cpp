
//
// Created by wyl on 2022/1/18.
//

#include<bits/stdc++.h>

using namespace std;
const int N = 50;
int w, n;
int ta[1<<25];
int tb[1<<25];
int cnta=0,cntb=0;
int a[N];
long long maxn = 0;

void dfs1(int u, int k, int s) {

    if (u > k) {
        ta[cnta++]=s;
        return;
    }
    if((long long)s+a[u]<=w)dfs1(u + 1, k, s + a[u]);
    dfs1(u + 1, k, s);
}
void dfs2(int u, int k, int s) {
    if (u > k) {
        tb[cntb++]=s;
        return;
    }
    if((long long)s+a[u]<=w)dfs2(u + 1, k, s + a[u]);
    dfs2(u + 1, k, s);
}

int main() {
    cin >> w >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, greater<int>());
    dfs1(1, (n+1) / 2, 0);
    dfs2(( n+1) / 2 + 1, n, 0);
    sort(ta, ta+cnta);
    sort(tb, tb+cntb, greater<int>());
    int i = 0, j = 0;
    while (i < cnta && j < cntb) {
        long long s = 1LL*ta[i] + 1LL*tb[j];
        if (s <= w) {
            maxn = max(maxn, s);
            i++;
        } else {
            j++;
        }
    }
    cout << maxn << endl;
}