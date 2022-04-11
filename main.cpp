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
int main(){
    vector<int> v;
}