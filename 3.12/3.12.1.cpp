
//
// Created by wyl on 2022/3/12.
//

#include<bits/stdc++.h>

using namespace std;
const int N = 17;
typedef pair<double, double> PDD;
PDD p[N];
double d[N][N];
double dp[N][1 << N];
int n;

double dist(PDD p1, PDD p2) {
    int x = p1.first - p2.first;
    int y = p1.second - p2.second;
    return sqrt(x * x + y * y);
}

int main() {
    scanf("%d", &n);
    p[0] = {0, 0};
    memset(dp,127,sizeof dp);
    double res = dp[0][0];
    for (int i = 1; i <= n; i++) {
        scanf("%lf%lf", &p[i].first, &p[i].second);
    }
    for(int i=0;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            d[i][j]=dist(p[i],p[j]);
            d[j][i]=d[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        dp[i][1 << (i - 1)] = d[0][i];
    }
    for (int k = 1; k < (1 << n) ; k++) {
        for (int i = 1; i <= n; i++) {
            if((k & (1 << (i - 1))) == 0)continue;
            for (int j = 1; j <= n; j++) {
                if (i == j)continue;
                if ((k & (1 << (j - 1))) == 0)continue;
                dp[i][k] = min(dp[i][k], dp[j][k - (1 << (i - 1))] + d[i][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        res = min(res, dp[i][(1 << n) - 1]);
    }
    printf("%.2lf", res);
}