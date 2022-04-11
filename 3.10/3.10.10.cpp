
//
// Created by wyl on 2022/3/10.
//

#include<bits/stdc++.h>

using namespace std;
const int N = 10010;
const int M = 50010;
vector<int> G[N];
int dfn[N], low[N], t;
stack<int> sta;
bool used[N];
int id[N], cnt, S[N];
int n, m;
int dout[N];

void tarjan(int u) {
    dfn[u] = low[u] = ++t;
    sta.push(u);
    used[u] = true;
    for (int i = 0; i < G[u].size(); i++) {
        int j = G[u][i];
        if (dfn[j] == 0) {
            tarjan(j);
            low[u] = min(low[u], low[j]);
        } else if (used[j]) low[u] = min(low[u], dfn[j]);
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
        } while (y != u);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (dfn[i] == 0) {
            tarjan(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < G[i].size(); j++) {
            int u = id[i], v = id[G[i][j]];
            if (u != v) {
                dout[u]++;
            }
        }
    }
    int zero = 0,sumn = 0;
    for (int i = 1; i <= cnt; i++) {
        if(dout[i]==0){
            zero++;
            sumn=S[i];
        }
    }
    if(zero==1){
        cout<<sumn<<endl;
    }else{
        cout<<0<<endl;
    };
}