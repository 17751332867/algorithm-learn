
//
// Created by wyl on 2022/3/9.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
typedef pair<int,int> PII;
priority_queue<PII,vector<PII>,greater<PII>> q;
vector<PII> G[N];
int n,m,s,t;
int dist[N];
bool used[N];
void dijkstra(){
    memset(dist,0x3f,sizeof dist);
    dist[s]=0;
    q.push({0,s});
    while(q.size()){
        int t = q.top().second;q.pop();
        if(used[t]==true)continue;
        used[t]=true;
        for(int i=0;i<G[t].size();i++){
            int dis = G[t][i].second;
            int pos = G[t][i].first;
            if(dis+dist[t]<dist[pos]){
                dist[pos]=dis+dist[t];
                q.push({dist[pos],pos});
            }
        }
    }
}
int main(){
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    dijkstra();
    cout<<dist[t]<<endl;
}