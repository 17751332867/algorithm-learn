
//
// Created by wyl on 2022/3/10.
//

#include<bits/stdc++.h>
using namespace std;
struct node{
    int u,v,w;
    const bool operator<(const node& n) const{
        return w<n.w;
    }
}ez[10010];
int par[10010];
int n,m,k;
int find(int x){
    if(x==par[x])return x;
    else return par[x]=find(par[x]);
}
void kruskal(){
    int res = 0,cnt = 0;
    for(int i=1;i<=m&&cnt<n-k;i++){
        int u = ez[i].u, v = ez[i].v;
        u = find(u),v=find(v);
        if(u==v)continue;
        par[u]=v;
        cnt++;
        res+=ez[i].w;
    }
    if(cnt<n-k){ puts("No Answer");}
    else cout<<res<<endl;
}
int main(){

    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)par[i]=i;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&ez[i].u,&ez[i].v,&ez[i].w);
    }
    sort(ez+1,ez+m+1);
    kruskal();
}