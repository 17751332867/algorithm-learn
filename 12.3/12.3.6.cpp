
//
// Created by wyl on 2021/12/3.
//

#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5+10;
const int M = 1e5+10;
const int INF = 0x3f3f3f3f;
vector<PII> g[N];
queue<int> q;
int dist[N],used[N];
int n,m;
void spfa(){
    for(int i=0;i<=n;i++){dist[i]=INF;}
    dist[1]=0;
    q.push(1);used[1]=true;
    while(!q.empty()){
        int t = q.front();q.pop();
        used[t]=false;
        for(int i=0;i<g[t].size();i++){
            int pos = g[t][i].first;int dis = g[t][i].second;
            if(dist[pos]>dist[t]+dis){
                dist[pos]=dist[t]+dis;
                if(!used[pos]){
                    q.push(pos);
                    used[pos]=true;
                }
            }
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        g[a].push_back({b,c});
    }
    spfa();
    if(dist[n]==INF){
        cout<<"impossible"<<endl;
    }else{
        cout<<dist[n]<<endl;
    }
}