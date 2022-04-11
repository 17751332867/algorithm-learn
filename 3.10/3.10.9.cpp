
//
// Created by wyl on 2022/3/10.
//

#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> PII;
const int N = 1010;
int n, m, c;
int S[N];
vector<PII> G[N];
int d[N], din[N];

void top_sort() {
    queue<int> q;
//    memset(d, 0x3f, sizeof d);
    for (int i = 1; i <= n; i++) {
        if (din[i] == 0) {
            q.push(i);
            d[i]=S[i];
        }
    }
    while (q.size()) {
        int t = q.front();q.pop();
        for(int i=0;i<G[t].size();i++){
            int pos = G[t][i].first;
            int dis = G[t][i].second;
            d[pos]=max(d[pos],d[t]+dis);
            d[pos]=max(d[pos],S[pos]);
            din[pos]--;
            if(din[pos]==0){
                q.push(pos);
            }
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &c);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &S[i]);
    }
    for (int i = 1; i <= c; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        G[u].push_back({v, w});
        din[v]++;
    }
    top_sort();
    for(int i=1;i<=n;i++){
        cout<<d[i]<<endl;
    }
}