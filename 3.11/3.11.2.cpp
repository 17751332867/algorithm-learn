
//
// Created by wyl on 2022/3/11.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
struct Trie{
    int next[N][30];
    int used[N];
    int tot;
    void init(){tot=0;}
    void insert(string s){
        int u = 0;
        for(int i=0;i<s.size();i++){
            int p = s[i]-'a';
            if(next[u][p]==0)next[u][p]=++tot;
            u = next[u][p];
        }
        used[u]=1;
    }
    int query(string s){
        int u = 0;
        for(int i=0;i<s.size();i++){
            int p = s[i] - 'a';
            if(next[u][p]==0)return false;
            u = next[u][p];
        }
        return used[u]++;
    }
}trie;
int n,m;string s;
int main(){
    trie.init();
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        cin>>s;trie.insert(s);
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        cin>>s;
        int res = trie.query(s);
        if(res==0){
            puts("WRONG");
        }else if(res==1){
            puts("OK");
        }else{
            puts("REPEAT");
        }
    }
}