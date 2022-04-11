
//
// Created by wyl on 2021/12/3.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
vector<PII> G[N];
priority_queue<PII,vector<PII>,greater<PII> > q;
bool used[N];int dist[N];
int n,m;
void dijkstra(){
    for(int i=0;i<=n;i++){
        dist[i]=INF;
    }

    dist[1]=0;
    q.push({0,1});
    while(!q.empty()){
        auto temp = q.top();q.pop();
        int t = temp.second;
        if(used[t]==true)continue;
        used[t]=true;
//        cout<<t<<endl;
        for(int i=0;i<G[t].size();i++){
            int pos = G[t][i].first;
            int dis = G[t][i].second;
            if(dist[pos]>dist[t]+dis){
                dist[pos]=dist[t]+dis;
                q.push({dist[pos],pos});
            }
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        G[a].push_back({b,c});
    }
    dijkstra();
    if(dist[n]==INF){
        cout<<"-1"<<endl;
    }else{
        cout<<dist[n]<<endl;
    }
}