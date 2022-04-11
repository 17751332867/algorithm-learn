
//
// Created by wyl on 2022/3/13.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> G[N];
int n,m,din[N],dout[N],del[N];
stack<int> sta;
void dfs(int u){
    for(int i=del[u];i<G[u].size();i=del[u]){
        del[u]++;
        dfs(G[u][i]);
    }
    sta.push(u);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        dout[u]++;din[v]++;
    }
    for(int i=1;i<=n;i++)std::sort(G[i].begin(), G[i].end());
    bool flag = true;
    int in=0,out=0,s=1;
    for(int i=1;i<=n;i++){
        if(din[i]!=dout[i])flag = false;
        if(din[i]-dout[i]==1)in++;
        if(dout[i]-din[i]==1)out++,s=i;
    }
    if(flag== false&&!(in==1&&out==1)){ puts("No");return 0;}
    dfs(s);
    while(sta.size()){
        printf("%d ",sta.top());sta.pop();
    }
}