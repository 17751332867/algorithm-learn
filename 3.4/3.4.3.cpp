
//
// Created by wyl on 2022/3/4.
//

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
ll a[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        if(a[n-1]<=a[n]&&a[n]>=0){
            printf("%d\n",n-2);
            for(int i=1;i<=n-2;i++){
                printf("%d %d %d\n",i,n-1,n);
            }
        }else if(is_sorted(a+1,a+n+1)){ printf("0\n");}
        else{ printf("-1\n");}
    }
}