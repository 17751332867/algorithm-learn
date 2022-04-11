
//
// Created by wyl on 2022/3/11.
//

#include<bits/stdc++.h>

using namespace std;
const int N = 5050;
const int M = 50050;
vector<int> G[N], g[N];
int dfn[N], low[N], t;
stack<int> sta;
bool used[N];
int id[N], cnt, S[N];
int n, m;
int din[N], d[N];
vector<int> res[N];

void tarjan(int u) {
    dfn[u] = low[u] = ++t;
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
        cnt++;
        int y;
        do {
            y = sta.top();
            sta.pop();
            used[y] = false;
            id[y] = cnt;
            S[cnt]++;
            res[cnt].push_back(y);
        } while (y != u);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        if (w == 1) {
            G[u].push_back(v);
        } else {
            G[u].push_back(v);
            G[v].push_back(u);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dfn[i] == 0) {
            tarjan(i);
        }
    }
    vector<int> temp;
    int maxn = 0;
    for (int i = 1; i <= cnt; i++) {
        if (S[i] > maxn) {
            maxn = S[i];
            temp = res[i];
        }
    }
    std::sort(temp.begin(), temp.end());
    printf("%d\n", maxn);
    for (int i = 0; i < temp.size(); i++) {
        printf("%d ",temp[i]);
    }
}