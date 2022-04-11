
//
// Created by wyl on 2022/1/8.
//

#include<bits/stdc++.h>

using namespace std;
unordered_map<string, int> dist;
unordered_map<string, pair<char, string> > res;
string ans;
string s, ed;

string move0(string str) {
    for (int i = 0; i < 4; i++) { swap(str[i], str[7 - i]); }
    return str;
}

string move1(string str) {
    for (int i = 0; i < 3; i++) { swap(str[i], str[3]); }
    for (int i = 4; i < 7; i++) { swap(str[i], str[i+1]); }
    return str;
}

string move2(string str) {
    swap(str[1], str[2]);
    swap(str[5], str[6]);
    swap(str[1], str[5]);
    return str;
}

void bfs() {
    queue<string> q;
    if(s==ed)return;
    q.push(s);
    while (q.size()) {
        string t = q.front();
        q.pop();
        if(t==ed)return;
        string m[3];
        m[0] = move0(t);
        m[1] = move1(t);
        m[2] = move2(t);
        for (int i = 0; i < 3; i++) {
            if (dist.count(m[i]) == 0) {
                q.push(m[i]);
                dist[m[i]] = dist[t] + 1;
//                cout<<m[i]<<"->"<<dist[m[i]]<<endl;
                res[m[i]] = {'A' + i, t};
            }
        }
    }
}

int main() {
    for (int i = 0; i < 8; i++) {
        int temp;
        cin >> temp;
        ed += char(temp + '0');
        s += char(i + '1');
    }
    bfs();
    printf("%d\n", dist[ed]);
    if(dist[ed]!=0){
        while (ed != s) {
            ans += res[ed].first;
            ed = res[ed].second;
        }
        reverse(ans.begin(),ans.end());
        cout<<ans<<endl;
    }
}