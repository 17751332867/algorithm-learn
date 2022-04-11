
//
// Created by wyl on 2022/3/5.
//

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
const int N = 2e5+10;
int c[N],r[N],x[N],y[N];
int n,m,k,q;
void solve(){
    int nc=0,nr=0;
    memset(c,0,sizeof c);
    memset(r,0,sizeof r);
    scanf("%d%d%d%d",&n,&m,&k,&q);
    for(int i=1;i<=q;i++){
        scanf("%d %d",&x[i],&y[i]);
    }
    ll res = 1;
    for(int i=q;i>0;i--){
        if(c[x[i]]&&r[y[i]]||nc==n||nr==m)continue;
        if(c[x[i]]==false){
            c[x[i]]=true;
            nc++;
        }
        if(r[y[i]]== false){
            r[y[i]]=true;
            nr++;
        }
        res = (res*k)%mod;
    }
    printf("%d\n",res);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}