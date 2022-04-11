
//
// Created by wyl on 2021/12/27.
//

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
int t,n,k;
int data[N];

ll solve(){
    map<int,int> m;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&data[i]);
    }
    ll res = 0;
    sort(data+1,data+n+1);
    for(int i=1;i<=n-2*k;i++){
        res += data[i];
    }
//    cout<<"res->"<<res<<endl;
    for(int i=n-2*k+1;i<=n;i++){
        m[data[i]]++;
    }
    int maxn = 0;
    for(auto a:m){
        maxn = max(a.second,maxn);
    }
    res += max((maxn-(2*k-maxn))/2,0);
    return res;
}
int main(){
    scanf("%d",&t);
    while(t--){
        ll res = solve();
        cout<<res<<endl;
    }
}