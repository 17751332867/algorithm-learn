
//
// Created by wyl on 2022/1/19.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 20010;

int n;
int tot  = 1, last = 1;
char str[N];
struct Node{
    int len,fa;
    int ch[26];
    vector<int> ids;
}node[N];
int ans[N],now[N];
vector<int> G[N];
void extend(int c,int idx){
    int p = last, np = last = ++tot;
    node[np].len = node[p].len + 1;
    node[np].ids.push_back(idx);
    for(;p&&!node[p].ch[c];p=node[p].fa)node[p].ch[c] = np;
    if(!p)node[np].fa=1;
    else{
        int q = node[p].ch[c];
        if(node[q].len == node[p].len+1)node[np].fa=q;
        else{
            int nq = ++tot;
            node[nq] = node[q],node[nq].len = node[p].len+1;
            node[nq].ids.push_back(idx);
            node[q].fa = node[np].fa = nq;
            for(;p&&node[p].ch[c]==q;p=node[p].fa)node[p].ch[c]=nq;
        }
    }
}
void add(int a,int b){
    G[a].push_back(b);
}
void dfs(int u){
    for(int i=0;i<G[u].size();i++){
        dfs(G[u][i]);
        now[u]=max(now[u],now[G[u][i]]);
    }
}
int main(){
    scanf("%d",&n);
    scanf("%s",str);
    for(int i=0;str[i];i++)extend(str[i]-'a',i);
    for(int i=1;i<=tot;i++)ans[i] = node[i].len;
    for(int i=2;i<=tot;i++)add(node[i].fa,i);
    for(int i=0;i<n-1;i++){
        scanf("%s",str);
        memset(now,0,sizeof now);
        int p = 1,t = 0;
        for(int j=0;str[j];j++){
            int c = str[j]-'a';
            while(p>1&&!node[p].ch[c])p=node[p].fa,t = node[p].len;
            if(node[p].ch[c])p = node[p].ch[c],t++;
            now[p]=max(now[p],t);
        }
        dfs(1);
        for(int j=1;j<=tot;j++)ans[j] = min(ans[j],now[j]);
    }
    int res = 0;
    for(int i=2;i<=tot;i++){
        res=max(res,ans[i]);
        printf("min:%d len:%d par:%d idx:",ans[i],node[i].len,node[i].fa);for(int j=0;j<node[i].ids.size();j++){ printf("%d ",node[i].ids[j]);}
        printf("\n");
    }
    printf("%d\n",res);
    return 0;
}