
//
// Created by wyl on 2021/12/14.
//

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+10;
ll tr1[N],tr2[N],a[N];
int n,m;
int lowbit(int x){return x&-x;}
int add(ll tr[],int x,ll k)
{
    for(int i=x;i<=n;i+= lowbit(i)){tr[i]+=k;}
}
ll ask(ll tr[],int x){
    ll res = 0;
    for(int i=x;i>0;i-= lowbit(i)){res+=tr[i];}
    return res;
}

int main(){
    cin.sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++){cin>>a[i];}
    for(int i=1;i<=n;i++){
        add(tr1,i,a[i]-a[i-1]);
        add(tr2,i,i*(a[i]-a[i-1]));
    }
    for(int i=1;i<=m;i++){
        char c;cin>>c;
        if(c=='Q'){
            int l,r;
            cin>>l>>r;
            cout<<(ask(tr1,r)*(r+1)-ask(tr2,r))-(ask(tr1,l-1)*(l)-ask(tr2,l-1))<<endl;
        }else{
            int l,r;ll d;
            cin>>l>>r>>d;
            add(tr1,l,d);add(tr1,r+1,-d);
            add(tr2,l,l*d);add(tr2,r+1,-(r+1)*d);
        }
    }
}