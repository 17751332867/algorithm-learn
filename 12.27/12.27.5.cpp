
//
// Created by wyl on 2021/12/27.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n,par[N],rak[N],res[N],a[N];
void solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&par[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);rak[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        if(rak[i]<rak[par[i]]){
            printf("-1\n");return;
        }
    }
    for(int i=1;i<=n;i++){
        res[a[i]] = i - rak[par[a[i]]];
    }
    for(int i=1;i<=n;i++){
        printf("%d ",res[i]);
    }
    printf("\n");
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}