
//
// Created by wyl on 2022/1/15.
//

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N  = 2e5+10;

int n,k;
int a[N];
int s[N];
set<pair<int,int> > t;
int res = 0x3f3f3f3f;
signed main(){
    cin>>n>>k;
    cin.sync_with_stdio(false);
    for(int i=1;i<=n;i++){
        cin>>a[i];s[i]=s[i-1]+a[i];
        if(s[i]>=0)t.insert({s[i],i});
    }
    for(int i=1;i<=n;i++){
        pair<int,int> p  = *t.lower_bound({s[i-1]+k,i});
        if(p.second!=0){
            res = min(res,p.second-i+1);
        }
    }
    if(res==0x3f3f3f3f){
        cout<<-1<<endl;
    }else{
        cout<<res<<endl;
    }
}
