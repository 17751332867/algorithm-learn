//
// Created by wyl on 2022/1/31.
//

#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> PII;
const int N = 1e5 + 10;
int n, m, mod;
vector<int> G[N], g[N];
int low[N], dfn[N], t;
stack<int> sta;
bool used[N];
int id[N], cnt, Size[N];
set<PII> table;
int f[N], h[N];

void tarjan(int u) {
    low[u] = dfn[u] = ++t;
    sta.push(u);
    used[u] = true;
    for (int i = 0; i < G[u].size(); i++) {
        int j = G[u][i];
        if (dfn[j] == 0) {
            tarjan(j);
            low[u] = min(low[u], low[j]);
        } else if (used[j])low[u] = min(low[u], dfn[j]);
    }
    if (dfn[u] == low[u]) {
        int y;
        cnt++;
        do {
            y = sta.top();
            sta.pop();
            used[y] = false;
            id[y] = cnt;
            Size[cnt]++;
        } while (y != u);
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &mod);
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        G[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) {
        if (dfn[i] == 0)tarjan(i);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < G[i].size(); j++) {
            int a = id[i], b = id[G[i][j]];
            if (a != b && table.count({a, b}) == 0) {
                g[a].push_back(b);
                table.insert({a, b});
            }
        }
    }
    for (int i = cnt; i ; i--) {
        if (f[i] == 0) {
            f[i] = Size[i];
            h[i] = 1;
        }
        for (int j = 0; j < g[i].size(); j++) {
            int k = g[i][j];
            if (f[i] + Size[k] > f[k]) {
                f[k] = f[i] + Size[k];
                h[k] = h[i];
            } else if (f[i] + Size[k] == f[k]) {
                h[k] = (h[k] + h[i])%mod;
            }
        }
    }
    int numn=0, sumn=0;
    for (int i = 1; i <= cnt; i++) {
        if (f[i] > numn) {
            numn = f[i];
            sumn = h[i];
        } else if (f[i] == numn) {
            sumn = (sumn + h[i])%mod;
        }
    }
    printf("%d\n%d",numn,sumn);
}