
//
// Created by wyl on 2021/12/21.
//

#include<bits/stdc++.h>
using namespace std;
const int N  = 1e6 + 10;
int n,m;
vector<int> G[N];
int del[N];
int dout[N],din[N];
stack<int> res;
void dfs(int x){
    for(int i = del[x];i<G[x].size();i=del[x]){
        del[x]++;
        dfs(G[x][i]);
    };
    res.push(x);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v);dout[u]++;din[v]++;G[u].push_back(v);
    }
    for(int i=1;i<=n;i++){sort(G[i].begin(),G[i].end());}
    int start=1,in=0,out=0;bool flag = true;
    for(int i=1;i<=n;i++){
//        cout<<dout[i]<<" "<<din[i]<<endl;
        if(dout[i]!=din[i])flag=false;
        if(dout[i]-din[i]==1)start=i,out++;
        if(din[i]-dout[i]==1)in++;
    }
//    cout<<out<<" "<<in<<" "<<start<<endl;
    if((!flag)&&!(out==1&&in==1)){ printf("No");return 0;}
    dfs(start);
    while(res.size()){ printf("%d ",res.top());res.pop();}
}