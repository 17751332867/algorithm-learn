
//
// Created by wyl on 2021/12/3.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 2e3+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
typedef  pair<int,int> PII;
vector<PII> g[N];
int n,m;
int dist[N],cnt[N],used[N];
queue<int> q;
bool spfa(){
    for(int i=1;i<=n;i++){
        used[i]=true;q.push(i);
    }
    while(q.size()){
        int t = q.front();q.pop();used[t]=false;
        for(int i=0;i<g[t].size();i++){
            int j = g[t][i].first;int dis = g[t][i].second;
            if(dist[j]>dist[t]+dis){
                dist[j]=dist[t]+dis;
                cnt[j]=cnt[t]+1;
                if(cnt[j]>=n)return true;
                if(!used[j]){
                    q.push(j);
                    used[j]=true;
                }
            }
        }
    }
    return false;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        g[a].push_back({b,c});
    }
    cout<<(spfa()?"Yes":"No")<<endl;
    return 0;
}