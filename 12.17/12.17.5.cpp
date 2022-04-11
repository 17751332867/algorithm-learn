
//
// Created by wyl on 2021/12/17.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
int son[N][27],cnt[N],idx;
int fail[N];
int n,T;
queue<int> q;
string ss[N];
int ans[N];
string str;
void insert(string s,int v){
    int u = 0;
    for(int i=0;i<s.size();i++){
        int t = s[i]-'a';
        if(son[u][t]==0)son[u][t]=++idx;
        u = son[u][t];
    }
    cnt[u]=v;
}
void build(){
    for(int i=0;i<26;i++){
        if(son[0][i])fail[son[0][i]]=0,q.push(son[0][i]);
    }
    while(!q.empty()){
        int u = q.front();q.pop();
        for(int i=0;i<26;i++){
            if(son[u][i])fail[son[u][i]]=son[fail[u]][i],q.push(son[u][i]);
            else  son[u][i]=son[fail[u]][i];
        }
    }
}
int main(){
    while(cin>>n&&n){
        ios::sync_with_stdio(false);

        memset(son,0,sizeof son);
        memset(cnt,0,sizeof cnt);
        memset(fail,0,sizeof fail);
        memset(ans,0,sizeof ans);
        idx=0;
        for(int i=1;i<=n;i++){
            cin>>ss[i];insert(ss[i],i);
        }
        build();
        cin>>str;
        int res = 0;
        int now = 0;
        for(int i=0;i<str.size();i++){
            now = son[now][str[i]-'a'];
            for(int t=now;t;t=fail[t])ans[cnt[t]]++;
        }
        for(int i=1;i<=n;i++){
            printf("%d\n",ans[i]);
        }
    }
}