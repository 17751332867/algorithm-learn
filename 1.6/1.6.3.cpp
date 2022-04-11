
//
// Created by wyl on 2022/1/6.
//

#include<bits/stdc++.h>

using namespace std;
const int N = 110;
int G[N][N];
int value[N];
bool used[N];
int dist[N];
int n, m;

int dijkstra(int l, int r) {
    memset(dist, 0x3f, sizeof dist);
    memset(used, false, sizeof used);
    dist[0] = 0;
    for (int i = 0; i <= n; i++) {
        int t = -1;
        for (int j = 0; j <= n; j++)
            if (!used[j] && (t == -1 || dist[j] < dist[t]))t = j;
        used[t] = true;
        for (int j = 0; j <= n; j++) {
            if (value[j] >= l && value[j] <= r) {
                dist[j] = min(dist[j], dist[t] + G[t][j]);
            }
        }
    }
    return dist[1];
}

int main() {
    cin>>n>>m;

}