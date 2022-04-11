
//
// Created by wyl on 2021/12/15.
//

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+10;
struct node{
    int l,r,v;
}tr[4*N];

void build(int x,int l,int r){
    tr[x]={l,r};
    if(l==r)return;
    int mid=(l+r)/2;
    build(2*x,l,mid);build(2*x+1,mid+1,r);
}
int query(int u,int l,int r){
    if(tr[u].l>=l&&tr[u].r<=r){return tr[u].v;}
    int mid = (tr[u].l+tr[u].r)/2;
    int v = 0;
    if(l<=mid){ v = query(2*u,l,r);}
    if(r>mid){ v = max(v,query(2*u+1,l,r)); }
    return v;
}

void modify(int u,int x,int v){
    if(tr[u].l==tr[u].r) tr[u].v=v;
    else{
        int mid = (tr[u].l+tr[u].r)/2;
        if(x<=mid){ modify(2*u,x,v);}
        else modify(2*u+1,x,v);
        tr[u].v = max(tr[2*u].v,tr[2*u+1].v);
    }
}
signed main(){
    int n=0,last=0;
    int m,q;
    cin>>m>>q;
    build(1,1,m);
    string op;
    for(int i=1;i<=m;i++){
        cin>>op;
        if(op=="A"){
            int a;cin>>a;
            modify(1,n+1,(a+last)%q);n++;
        }else{
            int t;cin>>t;
            last = query(1,n-t+1,n);
            cout<<last<<endl;
        }
    }
}