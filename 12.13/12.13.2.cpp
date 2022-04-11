
//
// Created by wyl on 2021/12/13.
//

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100010;
int n,m;
LL d[N],a[N];
int lowbit(int x){
    return x&-x;
}
int add(int x,int k){
    for(int i=x;i<=n;i+= lowbit(i))d[i]+=k;
}
LL ask(int x){
    LL res = 0;
    for(int i=x;i>0;i-= lowbit(i))res+=d[i];
    return res;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        add(i,a[i]-a[i-1]);
    }
    for(int i=1;i<=m;i++){
        char ch;scanf("%s",&ch);
        if(ch=='C'){
            int l,r,d;scanf("%d%d%d",&l,&r,&d);
            add(l,d);add(r+1,-d);
        }else{
            int x;scanf("%d",&x);
            printf("%lld\n",ask(x));
        }
    }
}