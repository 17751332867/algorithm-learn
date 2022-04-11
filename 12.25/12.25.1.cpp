
//
// Created by wyl on 2021/12/25.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int k = 11;
int n = 19;
string strs[N];
vector<string> ss;
map<string,int> MAP;int idx=0;map<int,string> RMAP;
vector<int> G[N];
int del[N];
int dout[N],din[N];
set<string> strSet;
stack<int> res;
void dfs(int x){
    for(int i = del[x];i<G[x].size();i=del[x]){
        del[x]++;
        dfs(G[x][i]);
    };
    res.push(x);
}
int main(){
//    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>strs[i];
    }
    for(int i=0;i<n;i++){
        for(int l=0;l<=strs[i].size()-k;l++){
            string ss = strs[i].substr(l,k);
            string s1 = ss.substr(0,k-1),s2 = ss.substr(1,k-1);
            if(MAP[s1]==0){MAP[s1]=++idx;RMAP[idx]=s1;}
            if(MAP[s2]==0){MAP[s2]=++idx;RMAP[idx]=s2;}
            int u = MAP[s1];
            int v = MAP[s2];
            cout<<RMAP[u]<<" "<<RMAP[v]<<endl;
            strSet.insert(RMAP[u]);
            strSet.insert(RMAP[v]);
            if(std::find(G[u].begin(), G[u].end(), v)==G[u].end()){
                dout[u]++;din[v]++;
                G[u].push_back(v);
            }
        }
    }
    cout<<strSet.size()<<endl;
    cout<<idx<<endl;
    for(auto a:strSet){
        cout<<a<<endl;
    }
    int start=1,in=0,out=0;bool flag = true;
    for(int i=1;i<=idx;i++){
        if(dout[i]!=din[i])flag=false;
        if(dout[i]-din[i]==1)start=i,out++;
        if(din[i]-dout[i]==1)in++;
    }
    dfs(start);
    string s = RMAP[res.top()].substr(0,k-1);
    cout<<s;
    while(res.size()){
        int temp = res.top();
        string s = RMAP[temp];
        cout<<s[s.size()-1];
        res.pop();
    }
}