
//
// Created by wyl on 2022/3/10.
//

#include<bits/stdc++.h>

using namespace std;
const int N = 5050;
int n, m, cnt;
int G[N][N];
int dist[N];
bool used[N];

int prim() {
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++) {
            if (!used[j] && (t == -1 || dist[j] < dist[t])){
                t=j;
            }
        }
        if(dist[t]==0x3f3f3f3f){cnt++;continue;}
        else res += dist[t];
        used[t] = true;
        for (int j = 1; j <= n; j++) {
            dist[j]=min(dist[j],G[t][j]);
        }
    }
    return res;
}

int main() {
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &G[i][j]);
            if(G[i][j]==0){G[i][j]=0x3f3f3f3f;}
        }
        G[i][i]=0;
    }
    cout<<prim()+(cnt+1)*m<<endl;
}