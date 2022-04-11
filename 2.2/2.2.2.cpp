
//
// Created by wyl on 2022/2/2.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int a[N],s[N];
int n,k;
int main(){
    scanf("%d%d",&n,&k);
    while(k--){
        int l,r;
        scanf("%d%d",&l,&r);
        a[l]+=1;
        a[r+1]-=1;
    }
    for(int i=1;i<=n;i++){s[i]=s[i-1]+a[i];}
    sort(s+1,s+n+1);
    printf("%d",s[(n+1)/2]);
}