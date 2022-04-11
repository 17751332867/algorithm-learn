
//
// Created by wyl on 2022/2/4.
//

#include<bits/stdc++.h>

using namespace std;
const int mod = 998244353;
const int N = 1e5 + 10;
int n;
int a[N], dp[N][10];

int get(int x) {
    while (x >= 10) {
        int t = 0;
        while (x) {
            t += x % 10;
            x /= 10;
        }
        x = t;
    }
    return x;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        a[i] = get(x);
    }
    for (int i = 1; i <= n; i++) {
        dp[i][a[i]]++;
        for (int j = 1; j <= 9; j++) {
            dp[i][j] = (dp[i][j] + dp[i - 1][j])%mod;
            dp[i][get(j + a[i])] = (dp[i][get(j + a[i])] + dp[i - 1][j])%mod;
        }
    }
    for(int i=1;i<=9;i++){
        printf("%d ",dp[n][i]);
    }
}