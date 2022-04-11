
//
// Created by wyl on 2022/3/6.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 550;
int n,m,k;
int d[N],a[N],dp[N][N];
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)scanf("%d",&d[i]);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    d[++n]=m;
    memset(dp,0x3f,sizeof dp);
    dp[1][1]=0;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            for(int l=1;l<i;l++){
                dp[i][j]=min(dp[i][j],dp[l][j-1]+(d[i]-d[l])*a[l]);
            }
        }
    }
    int res = 0x3f3f3f3f;
    for(int i=0;i<=k;i++){
        res = min(res,dp[n][n-i]);
    }
    printf("%d",res);
}