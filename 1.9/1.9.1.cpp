
//
// Created by wyl on 2022/1/9.
//

#include<bits/stdc++.h>

using namespace std;
string ed = "12345678x";
string start;
int turn[4][2] = {{-1, 0},
                  {0,  -1},
                  {1,  0},
                  {0,  1}};

vector<pair<string,char>> move(string s) {
    char temp[4][4];
    int x, y;
    string chs="uldr";
    vector<pair<string,char>> res;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            temp[i][j] = s[(i - 1) * 3 + j-1];
            if (temp[i][j] == 'x') {
                x = i, y = j;
            }
        }
    }
    for (int t = 0; t < 4; t++) {
        int tx = turn[t][0] + x, ty = turn[t][1] + y;
        if(tx>=1&&tx<=3&&ty>=1&&ty<=3){
            string tt;
            swap(temp[x][y],temp[tx][ty]);
            for(int i=1;i<=3;i++){
                for(int j=1;j<=3;j++){
                    tt+=temp[i][j];
                }
            }
            res.push_back({tt,chs[t]});
            swap(temp[x][y],temp[tx][ty]);
        }
    }
    return res;
}

void bfs() {
    queue<string> q;
    unordered_map<string, int> dist;
    unordered_map<string,pair<string,char> > pre;
    q.push(start);
    dist[start] = 0;
    while (q.size()) {
        string t = q.front();
//        cout<<t<<endl;
        q.pop();
        if (t == ed)break;
        vector<pair<string,char> > states = move(t);
        for(int i=0;i<states.size();i++){
            if(dist.count(states[i].first)==0){
                dist[states[i].first]=dist[t]+1;
                q.push(states[i].first);
                pre[states[i].first]={t,states[i].second};
            }
        }
    }
    string res;
    while(ed!=start){
        res+=pre[ed].second;
        ed=pre[ed].first;
    }
    reverse(res.begin(),res.end());
    cout<<res<<endl;
}

int main() {
    for (int i = 0; i < 9; i++) {
        char c;
        cin>>c;
        start = start + c;
    }
    bfs();
}