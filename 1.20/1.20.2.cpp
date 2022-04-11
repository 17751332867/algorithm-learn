
//
// Created by wyl on 2022/1/20.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 5e6+10;
int n,m;
int sum[N];
int a[N];
int lowbit(int x){return x&-x;}
int add(int x,int k){
    for(int i=x;i<=n;i+= lowbit(i))sum[i]+=k;
}
int ask(int x){
    int res = 0;
    for(int i=x;i>0;i-= lowbit(i))res+=sum[i];
    return res;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        add(i,a[i]-a[i-1]);
    }
    while (m--){
        int l,r,k;
        scanf("%d%d%d",&l,&r,&k);
        add(l,k);add(r+1,-k);
    }
    int res = 0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        res = min(res, ask(i));
    }
    printf("%d",res);
}