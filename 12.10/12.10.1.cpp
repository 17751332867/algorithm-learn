
//
// Created by wyl on 2021/12/10.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
struct edge{int c,d;}es[N];
int par[N],f[N];
vector<edge> d;
int u[N],v[N];
int n,m,w;
bool used[N];
int find(int x){
    if(x==par[x])return par[x];
    else par[x]=find(par[x]);
}
int main(){
    cin>>n>>m>>w;
    for(int i=1;i<=n;i++){
        par[i]=i;
        cin>>es[i].c>>es[i].d;
    }
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        u = find(u);
        v = find(v);
        par[u]=v;
    }
    for(int i=1;i<=n;i++){
        int x = find(i);
        u[x]+=es[i].c;
        v[x]+=es[i].d;
    }
    for(int i=1;i<=n;i++){
        if(u[i]!=0&&v[i]!=0){
            d.push_back({u[i],v[i]});
        }
    }
    for(int i=0;i<d.size();i++){
        for(int j=w;j>=d[i].c;j--){
            f[j]=max(f[j],f[j-d[i].c]+d[i].d);
        }
    }
    cout<<f[w]<<endl;
}