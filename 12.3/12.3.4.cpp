
//
// Created by wyl on 2021/12/3.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
const int M = 1e5+10;
int n,m;
vector<int> g[N];
queue<int> q;
int dist[N];
int bfs(){
    for(int i=0;i<=n;i++){dist[i]=-1;}
    dist[1]=0;
    q.push(1);
    while(!q.empty()){
        int t = q.front();q.pop();
        for(int i=0;i<g[t].size();i++){
            int j= g[t][i];
            if(dist[j]==-1){
                dist[j]=dist[t]+1;
                q.push(j);
            }
        }
    }
    return dist[n];
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
    }
    cout<<bfs()<<endl;
}