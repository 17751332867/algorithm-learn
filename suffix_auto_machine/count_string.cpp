
//
// Created by wyl on 2022/3/14.
//

#include<bits/stdc++.h>
using namespace std;
struct state {
    int len, link;
    unordered_map<char, int> next;
};
const int MAXLEN = 10000000;
state st[MAXLEN * 2];
vector<int> G[MAXLEN];
int f[MAXLEN];
int sz, last;
void sam_init() {
    st[0].len = 0;
    st[0].link = -1;
    sz++;
    last = 0;
}
void sam_extend(char c) {
    int cur = sz++;
    f[cur]=1;
    st[cur].len = st[last].len + 1;
    int p = last;
    while (p != -1 && !st[p].next.count(c)) {
        st[p].next[c] = cur;
        p = st[p].link;
    }
    if (p == -1) {
        st[cur].link = 0;
    } else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len) {
            st[cur].link = q;
        } else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            while (p != -1 && st[p].next[c] == q) {
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}
void dfs(int u){
    for(int i=0;i<G[u].size();i++){
        dfs(G[u][i]);
        f[u]+=f[G[u][i]];
    }
}
int main(){
    string s;
    sam_init();
    cin>>s;
    for(int i=0;i<s.size();i++){sam_extend(s[i]);}
    for(int i=1;i<sz;i++)G[st[i].link].push_back(i);
    dfs(0);
    cin>>s;
    int u = 0,res = 0;
    for(int i=0;i<s.size();i++){
        u = st[u].next[s[i]],res = f[u];
        if(u==0){res=0;break;}
    }
    cout<<res<<endl;
}