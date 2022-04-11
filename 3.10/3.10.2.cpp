
//
// Created by wyl on 2022/3/10.
//

#include<bits/stdc++.h>
using namespace std;
typedef pair<int,double> PID;
typedef pair<double,int> PDI;
vector<PID> G[2020];
priority_queue<PDI,vector<PDI>,greater<PDI>> q;
double dist[2020];
bool used[2020];
int n,m,s,t;
void dijkstra(){
    for(int i=1;i<=n;i++)dist[i]=1e9;
    dist[t]=100;
    q.push({100,t});
    while(q.size()){
        auto t = q.top().second;q.pop();
        if(used[t])continue;
        used[t]=true;
        for(int i=0;i<G[t].size();i++){
            double dis = G[t][i].second;
            int pos = G[t][i].first;
            if(dist[pos]>dist[t]/dis){
                dist[pos]=dist[t]/dis;
                q.push({dist[pos],pos});
            }
        }
    }
    printf("%.8lf",dist[s]);
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;double w;
        cin>>u>>v>>w;
        G[u].push_back({v,(100-w)/100});
        G[v].push_back({u,(100-w)/100});
    }
    cin>>s>>t;
    dijkstra();
}