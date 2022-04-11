
//
// Created by wyl on 2022/1/30.
//

#include<bits/stdc++.h>

using namespace std;
const int N = 20010;
const int M = 100010;
vector<int> G[N];
int n, m;
int low[N], dfn[N], idx;
bool res[N];

void tarjan(int u, int fa) {
    low[u] = dfn[u] = ++idx;
    int child = 0;
    for (int i = 0; i < G[u].size(); i++) {
        int j = G[u][i];
        if (dfn[j]==0) {
            tarjan(j, fa);
            low[u] = min(low[u], low[j]);
            if (low[j] >= dfn[u] && u != fa) {
                res[u] = true;
            }
            if (u == fa)
                child++;
        }
        low[u] = min(low[u], dfn[j]);
    }
    if (child >= 2 && u == fa) {
        res[u] = true;
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (dfn[i] == 0) {
            tarjan(i, i);
        }
    }
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        if (res[i])tot++;
    }
    printf("%d\n", tot);
    for (int i = 1; i <= n; i++) {
        if(res[i])printf("%d ",i);
    }
}