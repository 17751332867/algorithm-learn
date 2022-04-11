
//
// Created by wyl on 2022/3/20.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
int n,a[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        sort(a+1,a+n+1);
        printf("%d\n",a[n-1]+a[n]);
    }
}