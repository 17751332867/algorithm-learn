
//
// Created by wyl on 2022/3/13.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 550;
int m,n;
int G[N][N],du[N];
stack<int> sta;
void dfs(int u){
    for(int i=1;i<=n;i++){
        if(G[u][i]){
            G[u][i]--;
            G[i][u]--;
            dfs(i);
        }
    }
    sta.push(u);
}
int main(){
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u][v]++;
        G[v][u]++;
        du[v]++;
        du[u]++;
        n = max(max(u,v),n);
    }
    int s=1;
    for(int i=1;i<=n;i++){
        if(du[i]%2==1){s=i;break;}
    }
    dfs(s);
    while(sta.size()){
        printf("%d\n",sta.top());sta.pop();
    }
}