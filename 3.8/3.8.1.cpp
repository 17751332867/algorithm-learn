
//
// Created by wyl on 2022/3/8.
//

#include<bits/stdc++.h>
using namespace std;
struct state {
    int len, link,firstpos;
    std::map<char, int> next;
};
const int MAXLEN = 100000;
state st[MAXLEN * 2];
int sz, last;

void sam_init() {
    st[0].len = 0;
    st[0].link = -1;
    sz++;
    last = 0;
}
void sam_extend(char c) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    st[cur].firstpos = st[cur].len-1;
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
            st[clone].firstpos = st[q].firstpos;
        }
    }
    last = cur;
}
int main(){
    string s;cin>>s;
    sam_init();
    for(int i=0;i<s.size();i++){
        sam_extend(s[i]);
    }
    while(cin>>s){
        int u = 0;
        for(int i=0;i<s.size();i++){
            u = st[u].next[s[i]];
        }
        cout<<st[u].firstpos-s.size()+1<<endl;
    }
}