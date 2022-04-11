
//
// Created by wyl on 2022/3/6.
//

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+10;
int n,m,maxn=0;
vector<int> x[N],y[N];
int suan(vector<int> v){
    sort(v.begin(),v.end());
    int s = v.size();
    int sumn = 0;
    for(int i=0;i<v.size();i++){
        sumn+=v[i]*(i+1);
        sumn-=v[s-i-1]*(i+1);
    }
    return sumn;
}
signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int t;cin>>t;
            x[t].push_back(i);
            y[t].push_back(j);
            maxn = max(maxn,t);
        }
    }
    int res = 0;
    for(int t=1;t<=maxn;t++){
        res+=suan(x[t]);
        res+= suan(y[t]);
    }
    cout<<res<<endl;
}