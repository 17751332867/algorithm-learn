
//
// Created by wyl on 2022/3/11.
//

#include<bits/stdc++.h>

using namespace std;
const int N = 10010;
const int M = 100010;
vector<int> G[N], g[N];
int dfn[N], low[N], t;
stack<int> sta;
bool used[N];
int id[N], cnt, S[N], W[N], w[N];
int n, m;
int din[N],d[N];

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
            W[cnt] += w[y];
        } while (y != u);
    }
}
void top_sort(){
    queue<int> q;
    for(int i=1;i<=cnt;i++){
        if(din[i]==0){q.push(i);d[i]=W[i];}
    }
    while(q.size()){
        int t = q.front();q.pop();
        for(int i=0;i<g[t].size();i++){
            int v = g[t][i];
            d[v]=max(d[v],d[t]+W[v]);
            din[v]--;
            if(din[v]==0){
                q.push(v);
            }
        }
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }
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
                din[v]++;
                g[u].push_back(v);
            }
        }
    }
    top_sort();
    int res = 0;
    for(int i=1;i<=cnt;i++){
        res = max(res,d[i]);
    }
    cout<<res<<endl;
}