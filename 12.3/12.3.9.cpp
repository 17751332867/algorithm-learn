
//
// Created by wyl on 2021/12/3.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 510;
const int INF = 0x3f3f3f3f;
int n,m;
int g[N][N];
int dist[N];
int used[N];
int prim(){
    memset(dist,0x3f,sizeof dist);
    int res = 0;
    for(int i=0;i<n;i++){
        int t = -1;
        for(int j=1;j<=n;j++){
            if(!used[j]&&(t==-1||dist[t]>dist[j])){
                t=j;
            }
        }
        if(i&&dist[t]==INF)return INF;
        if(i)res+=dist[t];
        for(int j=1;j<=n;j++){
            dist[j]=min(dist[j],g[t][j]);
        }
        used[t]=true;
    }
    return res;
}
int main(){
    cin>>n>>m;
    memset(g,0x3f,sizeof g);
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        g[a][b]=g[b][a]=min(g[a][b],c);
    }
    int res = prim();
    if(res==0x3f3f3f3f){
        cout<<"impossible"<<endl;
    }else{
        cout<<res<<endl;
    }
}