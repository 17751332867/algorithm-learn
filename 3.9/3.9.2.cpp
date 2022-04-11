
//
// Created by wyl on 2021/12/21.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 5050;
int n,m;
int G[N][N];
int dist[N];
bool used[N];
int prim(){
    memset(dist,0x3f,sizeof dist);
    dist[2]=0;
    int res = 0;
    for(int i=0;i<n;i++){
        int t = -1;
        for(int j=1;j<=n;j++){
            if(!used[j]&&(t==-1||dist[j]<dist[t])) {
                t = j;
            }
        }
        res += dist[t];
        used[t]=true;
        for(int j=1;j<=n;j++){
            dist[j]=min(dist[j],G[t][j]);
        }
    }
    return res;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            G[i][j]=0x3f3f3f3f;
        }
        G[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        G[u][v]=w;
        G[v][u]=w;
    }
    printf("%d\n",prim());
}