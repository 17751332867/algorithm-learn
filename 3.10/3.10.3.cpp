
//
// Created by wyl on 2022/3/10.
//

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2020;

typedef pair<int, int> PII;
vector<PII> G[N];
int dist[N], cnt[N];
bool used[N];
int n, m;
bool cmp(PII p1,PII p2){
    return p1.first==p2.first;
}
void dijkstra() {
    priority_queue<PII, vector<PII>, greater<PII> > q;
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;cnt[1]=1;
    q.push({0, 1});
    while (q.size()) {
        int t = q.top().second;
        q.pop();
        if (used[t])continue;
        used[t] = true;
        for (int i = 0; i < G[t].size(); i++) {
            int pos = G[t][i].first;
            int dis = G[t][i].second;
            if (dist[pos] < dis + dist[t]) {
                continue;
            } else if (dist[pos] == dis + dist[t]) {
                cnt[pos] = cnt[pos] + cnt[t];
            } else {
                cnt[pos] = cnt[t];
                dist[pos] = dis + dist[t];
                q.push({dist[pos], pos});
            }
        }
    }
}

signed main() {
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%lld%lld%lld", &u, &v, &w);
        G[u].push_back({v, w});
    }
    for(int i=1;i<=n;i++){std::sort(G[i].begin(), G[i].end());G[i].erase(unique(G[i].begin(),G[i].end(),cmp),G[i].end());}
    dijkstra();
    if(cnt[n]!=0)
    printf("%lld %lld",dist[n],cnt[n]);
    else puts("No answer");
}