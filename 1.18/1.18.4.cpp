
//
// Created by wyl on 2022/1/18.
//

#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> PII;
const int N = 155;
const double INF = 1e20;

char G[N][N];
double d[N][N];
PII p[N];
double maxd[N];
int n;
double res1 = 0;
double res2 = INF;
double get_distance(int i, int j) {
    int x = p[i].first - p[j].first;
    int y = p[i].second - p[j].second;
    return sqrt(x * x + y * y);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) { scanf("%d%d", &p[i].first, &p[i].second); }
    for (int i = 0; i < n; i++)scanf("%s", G[i]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (G[i][j] == '1') {
                d[i][j] = get_distance(i, j);
            } else { d[i][j] = INF; }
        }
        d[i][i] = 0;
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                d[i][j] = min(d[i][k]+d[k][j],d[i][j]);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(d[i][j]!=INF){
                maxd[i]=max(maxd[i],d[i][j]);
            }
        }
        res1 = max(res1,maxd[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(d[i][j]>=INF){
                res2 = min(res2,maxd[i]+maxd[j]+ get_distance(i,j));
            }
        }
    }
    printf("%.6lf",max(res1,res2));
}