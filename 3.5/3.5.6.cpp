
//
// Created by wyl on 2022/3/5.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 110;
int n,a[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(n==3){
            printf("3 2 1\n"
                   "1 3 2\n"
                   "3 1 2\n");continue;
        }
        for(int i=1;i<=n;i++){
            a[i]=n-i+1;
            a[n+i]=a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<i+n;j++){
                printf("%d ",a[j]);
            }
            printf("\n");
        }
    }
}