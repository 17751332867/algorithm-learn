
//
// Created by wyl on 2021/12/13.
//

#include<iostream>
#include<cstdio>
using namespace std;
const int N = 2e5+10;
int tr[N],a[N],low[N],great[N];
int n;
long long resA,resB;
int lowbit(int x){
    return x&-x;
}
void add(int x,int k){
    for(int i=x;i<=n;i+= lowbit(i))tr[i]+=k;
}
int ask(int x){
    int sumn=0;
    for(int i=x;i>0;i-= lowbit(i))sumn+=tr[i];
    return sumn;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        low[i]= ask(a[i]-1);
        great[i]=ask(n)-ask(a[i]);
        add(a[i],1);
    }
    for(int i=0;i<=n;i++)tr[i]=0;
    for(int i=n;i>=1;i--){
        resA+=low[i]*ask(a[i]-1);
        resB+=great[i]*(ask(n)-ask(a[i]));
        add(a[i],1);
    }
    printf("%lld %lld",resB,resA);
}