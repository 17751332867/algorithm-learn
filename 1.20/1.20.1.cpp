
//
// Created by wyl on 2022/1/20.
//

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e7+10;
int n,m;
ll tr[N];
int lowbit(int x){return x&-x;}
void add(int x,int k){
    for(int i=x;i<=n;i+= lowbit(i))tr[i]+=k;
}
ll ask(int x){
    ll res = 0;
    for(int i=x;i>0;i-= lowbit(i))res+=tr[i];
    return res;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int c;
        scanf("%d",&c);
        if(c==0){
            int l,r;
            scanf("%d%d",&l,&r);
            add(l,1);add(r+1,-1);
        }else{
            int k;
            scanf("%d",&k);
            printf("%lld\n", ask(k));
        }
    }
}