
//
// Created by wyl on 2022/3/11.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
int n1,n2,m;
vector<int> G[N];
int match[N];
bool used[N];
bool find(int x){
    for(int i=0;i<G[x].size();i++){
        int j = G[x][i];
        if(!used[j]){
            used[j]=true;
            if(match[j]==0||find(match[j])){
                match[j]=x;
                return true;
            }
        }
    }
    return false;
}
int main(){
    scanf("%d%d%d",&n1,&n2,&m);
    for(int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
    }
    int res = 0;
    for(int i=1;i<=n1;i++){
        memset(used,false,sizeof used);
        if(find(i)){
            res++;
        }
    }
    printf("%d\n",res);
}