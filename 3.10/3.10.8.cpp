
//
// Created by wyl on 2022/3/10.
//

#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> PII;
const int N = 1510;
int din[N];
int d[N],cf[N];
vector<PII> G[N];
int n,m;
void top_sort(){
    d[n]=-1;
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(din[i]==0){q.push(i);}
    }
    while(q.size()){
        int t = q.front();
        q.pop();
        for(int i=0;i<G[t].size();i++){
            int pos = G[t][i].first,dis = G[t][i].second;
            din[pos]--;
            if(cf[t]==1){
                d[pos] = max(d[pos],d[t]+dis);
                cf[pos]=1;
            }
            if(din[pos]==0)q.push(pos);
        }
    }
}
signed main(){
    scanf("%lld%lld",&n,&m);
    if(n==1){cout<<0<<endl;return 0;}
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        G[u].push_back({v,w});
        din[v]++;
    }
    cf[1]=1;
    top_sort();
    cout<<d[n]<<endl;
}