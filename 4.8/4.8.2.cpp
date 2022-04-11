#include<bits/stdc++.h>
using namespace std;
int p[100000];
int n,m;
int G[1010][1010];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>p[i];
    for(int i=1;i<=m;i++){
        int u,v,w;cin>>u>>v>>w;
        G[u][v]=G[v][u]=w;
    }
}