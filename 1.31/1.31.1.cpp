//
// Created by wyl on 2022/1/31.
//

#include<bits/stdc++.h>

using namespace std;
const int N = 110;
int low[N], dfn[N], idx;
vector<int> G[N];
int dout[N], din[N];
stack<int> sta;
bool used[N];
int n;
int id[N], cnt, Size[N];

void tarjan(int u) {
    dfn[u] = low[u] = ++idx;
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
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int u;
        while (scanf("%d", &u) && u != 0) {
            G[i].push_back(u);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dfn[i] == 0)tarjan(i);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < G[i].size(); j++) {
            int a = id[i], b = id[G[i][j]];
//            cout<<a<<" "<<b<<endl;
            if (a != b) {
                dout[a]++;
                din[b]++;
            }
        }
    }
    int a = 0, b = 0;
    for(int i = 1; i <= cnt; i++){
        if(din[i]==0)a++;
        if(dout[i]==0)b++;
    }
    printf("%d\n",a);
    if(cnt==1)printf("0");
    else printf("%d",max(a,b));
}