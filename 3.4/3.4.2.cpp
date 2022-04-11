
//
// Created by wyl on 2022/3/4.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n,a[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        if(n==3&&(a[2]%2==1)){printf("-1\n");continue;}
        bool flag = true;long long res = 0;
        for(int i=2;i<=n-1;i++){
            if(a[i]!=1){flag= false;}
            res+=(a[i]+1)/2;
        }
        if(flag== true){printf("-1\n");continue;}
        else{ printf("%lld\n",res);}
    }
}