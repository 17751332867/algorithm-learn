
//
// Created by wyl on 2022/1/10.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 25;
int n,w;
int a[N];
int sumn[N];
int res=N;
void dfs(int u,int used){
    if(used>=res)return;
    if(u==n){res = min(res,used);return;}
    for(int i=0;i<used;i++){
        if(sumn[i]+a[u]<=w){
            sumn[i]+=a[u];
            dfs(u+1,used);
            sumn[i]-=a[u];
        }
    }
    sumn[used]=a[u];
    dfs(u+1,used+1);
    sumn[used]=0;
}
int main(){
    scanf("%d%d",&n,&w);
    for(int i=0;i<n;i++){scanf("%d",&a[i]);}
    dfs(0,0);
    printf("%d\n",res);
}