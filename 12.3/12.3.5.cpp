
//
// Created by wyl on 2021/12/3.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 550;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
struct edge{int from,to,cost;};
edge ez[M];
int n,m,k;
int dist[N],backup[N];
void back(){
    for(int i=0;i<=n;i++){backup[i]=dist[i];}
}
void bellman_ford(){
    for(int i=0;i<=n;i++){dist[i]=INF;}
    dist[1]=0;
    for(int i=0;i<k;i++){
        back();
        for(int j=0;j<m;j++){
            int from = ez[j].from,to=ez[j].to,cost=ez[j].cost;
            dist[to]=min(dist[to],backup[from]+cost);
        }
    }
}
int main(){
    cin.sync_with_stdio(false);
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        ez[i]={a,b,c};
    }
    bellman_ford();
    if(dist[n]>=INF){
        cout<<"impossible"<<endl;
    }else{
        cout<<dist[n]<<endl;
    }
}