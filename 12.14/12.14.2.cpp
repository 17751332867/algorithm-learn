
//
// Created by wyl on 2021/12/14.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int tr[N],a[N],ans[N];
int n;
int lowbit(int x){return x&-x;}
int add(int x,int k){
    for(int i=x;i<=n;i+= lowbit(i))tr[i]+=k;
}
int ask(int x){
    int res = 0;
    for(int i=x;i>0;i-=lowbit(i))res+=tr[i];
    return res;
}
int main(){
    scanf("%d",&n);
    for(int i=2;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)tr[i]= lowbit(i);
    for(int i=n;i>=1;i--){
        int k = a[i]+1;
        int l=1,r=n;
        while(l<r){
            int mid = (l+r)/2;
            if(ask(mid)>=k)r=mid;
            else l=mid+1;
        }
        ans[i]=l;
        add(l,-1);
    }
    for(int i=1;i<=n;i++){
        printf("%d\n",ans[i]);
    }
}