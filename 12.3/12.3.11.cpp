
//
// Created by wyl on 2021/12/3.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
const int M = 2e5+10;
struct edge{
    int a,b,c;
}ez[M];
bool cmp(edge x,edge y){
    return x.c<y.c;
}
int n,m;
int par[N];
int find(int x){
    if(x==par[x])return par[x];
    else return par[x]=find(par[x]);
}
int kruskal(){
    int res=0,cnt=0;
    for(int i=0;i<m;i++){
        int x = ez[i].a, y =ez[i].b;
        x = find(x), y = find(y);
        if(x!=y){
            par[x]=y;cnt++;res+=ez[i].c;
        }
    }
    if(cnt<n-1){
        return 0x3f3f3f3f;
    }
    return res;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<=n;i++){par[i]=i;}
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        ez[i]={a,b,c};
    }
    sort(ez,ez+m,cmp);
    int res = kruskal();
    if(res==0x3f3f3f3f){
        cout<<"impossible"<<endl;
    }else{
        cout<<res<<endl;
    }
}
