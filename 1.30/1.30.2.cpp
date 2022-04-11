
//
// Created by wyl on 2022/1/30.
//

#include<bits/stdc++.h>

using namespace std;
const int N = 10010;
const int M = 50010;
int n, m;
vector<int> G[N];
int dfn[N], low[N], t;
stack<int> sta;
bool used[N],vis[N];
int id[N], S[N], cnt;

void tarjan(int u) {
    dfn[u] = low[u] = ++t;
    sta.push(u);
    used[u] = true;
    for (int i = 0; i < G[u].size(); i++) {
        int j = G[u][i];
        if (dfn[j] == 0) {
            tarjan(j);
            low[u] = min(low[u], low[j]);
        } else if (used[j]) {
            low[u] = min(low[u], dfn[j]);
        }
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
        }while(y != u);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        G[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) {
        if (dfn[i] == 0) {
            tarjan(i);
        }
    }
    int res = 0;
    for (int i = 1; i <= cnt; i++) {
        if (S[i] > 1)res++;
//        printf("%d ",S[i]);
    }
    printf("%d", res);
}