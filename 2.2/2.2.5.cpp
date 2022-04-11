
//
// Created by wyl on 2022/2/2.
//

#include<bits/stdc++.h>

using namespace std;
typedef pair<int, pair<int, int>> PIII;
const int N = 1005;
int turn[4][2] = {{0, 1},
                  {0, -1},
                  {1, 0},
                  {-1, 0}};
int n, sx, sy;
int M[N][N], used[N][N], dist[N][N];

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

struct cmp {
    bool operator()(const PIII &p1, const PIII &p2) const {
        return p1.first > p2.first;
    }
};

void dijkstra() {
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            dist[i][j]=0x3f3f3f3f;
    dist[sx][sy] = 0;
    priority_queue<PIII, vector<PIII>, cmp> q;
    q.push({0, {sx, sy}});
    while (q.size()) {
        auto t = q.top().second;
        q.pop();
        int x = t.first, y = t.second;
        if (used[x][y])continue;
        used[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int tx = x + turn[i][0], ty = y + turn[i][1];
            if (tx >= 0 && tx < N && ty >= 0 && ty < N) {
                int w = M[tx][ty];
                if (dist[tx][ty] > dist[x][y] + w) {
                    dist[tx][ty] = dist[x][y] + w;
                    q.push({dist[tx][ty], {tx, ty}});
                }
            }
        }
    }
    printf("%d", dist[0][0]);
}

int main() {
    n = read(), sx = read(), sy = read();
    for (int i = 0; i < n; i++) {
        int x, y;
        x = read(), y = read();
        M[x][y] = 1;
    }
    dijkstra();
}