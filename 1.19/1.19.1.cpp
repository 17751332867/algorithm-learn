
//
// Created by wyl on 2022/1/19.
//

#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
const int N = 2000010;

int tot = 1, last = 1;
struct Node {
    int len, fa;
    int ch[26];
} node[N];
char str[N];
LL f[N], ans;
vector<int> G[N];

void extend(int c,int pos) {
    int p = last, np = last = ++tot;
    f[tot] = 1;
    node[np].len = node[p].len + 1;
    for (; p && !node[p].ch[c]; p = node[p].fa) node[p].ch[c] = np;
    if (!p)node[np].fa = 1;
    else {
        int q = node[p].ch[c];
        if (node[q].len == node[p].len + 1)node[np].fa = q;
        else {
            int nq = ++tot;
            node[nq] = node[q], node[nq].len = node[p].len + 1;
            node[q].fa = node[np].fa = nq;
            for (; p && node[p].ch[c] == q; p = node[p].fa)node[p].ch[c] = nq;
        }
    }
}

void add(int a,int b){
    G[a].push_back(b);
}

void dfs(int u) {
    for (int i = 0; i<G[u].size(); i++) {
        dfs(G[u][i]);
        f[u] += f[G[u][i]];
    }
}

int main() {
    scanf("%s",str);
    for(int i=0;str[i];i++)extend(str[i]-'a',i);
    for(int i=2;i<=tot;i++)add(node[i].fa,i);
    dfs(1);
    string s;cin>>s;
    int u = 1;
    for(int i=0;i<s.size();i++){
        u = node[u].ch[s[i]-'a'];
    }
    printf("%d",f[u]);
    return 0;
}