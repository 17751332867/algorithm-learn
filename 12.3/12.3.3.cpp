
//
// Created by wyl on 2021/12/3.
//
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n,m;
vector<int> g[N];
bool used[N];
int ans = N;
int dfs(int s){
    used[s]=true;
    int sum=1,res=0;
    for(int i=0;i<g[s].size();i++){
        int j = g[s][i];
        if(!used[j]){
            int s = dfs(j);
            sum+=s;
            res=max(res,s);
        }
    }
    res = max(res,n-sum);
    ans = min(res,ans);
    return sum;
}

int main(){
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
    cout<<ans<<endl;
}