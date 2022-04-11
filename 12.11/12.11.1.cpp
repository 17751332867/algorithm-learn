
//
// Created by wyl on 2021/12/11.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int t,n;
vector<pair<int,int> > d;
unordered_map<int,int> par;
int a[N],b[N],c[N];
int find(int x){
    if(x==par[x])return par[x];
    else return par[x]=find(par[x]);
}
bool solve(){
    d.clear();
    par.clear();
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
        par[a[i]]=a[i];
        par[b[i]]=b[i];
        if(c[i]==0){
            d.push_back({a[i],b[i]});
        }
    }
    for(int i=1;i<=n;i++){
        if(c[i]==1){
            a[i]=find(a[i]);
            b[i]=find(b[i]);
            par[a[i]]=b[i];
//            cout<<find(a[i])<<" "<<find(b[i])<<endl;
        }
    }
    for(auto a:d){
        int x=a.first,y=a.second;
        x=find(x);
        y=find(y);
        if(x==y){
            return false;
        }
    }
    return true;
}

int main(){
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        printf("%s\n",(solve()?"YES":"NO"));
    }
}