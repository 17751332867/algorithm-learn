
//
// Created by wyl on 2022/3/9.
//

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
typedef pair<int,int> PII;
vector<PII> G[N];
vector<PII> g[N];
int n,m;
int dist[N],used[N];
void dijkstra(vector<PII> G[]){
    fill(dist,dist+N,0x3f3f3f3f);
    fill(used,used+N,false);
    dist[1]=0;
    priority_queue<PII,vector<PII>,greater<PII>> q;
    q.push({0,1});
    while(q.size()){
        int t = q.top().second;q.pop();
        if(used[t])continue;
        used[t]=true;
        for(int i=0;i<G[t].size();i++){
            int dis = G[t][i].second;
            int pos = G[t][i].first;
            if(dist[pos]>dist[t]+dis){
                dist[pos]=dist[t]+dis;
                q.push({dist[pos],pos});
            }
        }
    }
}
signed main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        G[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    int res = 0;
    dijkstra(G);
    for(int i=1;i<=n;i++){
        res+=dist[i];
    }
    dijkstra(g);
    for(int i=1;i<=n;i++){res+=dist[i];}
    cout<<res<<endl;
}