
//
// Created by wyl on 2021/12/17.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 550010;
const int M = 1e6+10;
int son[N][26],cnt[N],idx=0;
int fail[N];
char str[M];
queue<int>q;
int n,m,T;
void insert(char s[]){
    int p = 0;
    for(int i=0;s[i];i++){
        int t = s[i]-'a';
        if(son[p][t]==0)son[p][t]=++idx;
        p = son[p][t];
    }
    cnt[p]++;
}
void build(){
    for(int i=0;i<26;i++){
        if(son[0][i])fail[son[0][i]]=0,q.push(son[0][i]);
    }
    while(!q.empty()){
        int u = q.front();q.pop();
        for(int i=0;i<26;i++){
            if(son[u][i])fail[son[u][i]]=son[fail[u]][i],q.push(son[u][i]);
            else son[u][i]=son[fail[u]][i];
        }
    }
}
int main(){
    scanf("%d",&T);
    while(T--){
        idx=0;
        scanf("%d",&n);
        memset(son,0,sizeof son);
        memset(cnt,0,sizeof cnt);
        memset(fail,0,sizeof fail);
//        scanf("%d",&n);
        for(int i=0;i<n;i++){scanf("%s",str);insert(str);}
        build();
        scanf("%s",str);
        int len = strlen(str);
        int res = 0;
        int now = 0;
        for(int i=0;i<len;i++){
            now = son[now][str[i]-'a'];
            for(int t = now;t!=0&&cnt[t]!=-1;t=fail[t])res+=cnt[t],cnt[t]=-1;
        }
        printf("%d\n",res);
    }
}