
//
// Created by wyl on 2022/2/2.
//

#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> PII;
const int N = 1020;
int turn[4][2] = {{-1, 0},
                  {1,  0},
                  {0,  1},
                  {0,  -1}};

int M[N][N], used[N][N], d[N][N];
int n, sx, sy;
deque<PII> q;

int bfs() {
    q.push_back({sx, sy});
    memset(d, 0x3f, sizeof d);
    d[sx][sy] = 0;
    while (q.size()) {
        auto t = q.front();q.pop_front();
        int x = t.first, y = t.second;
        if (used[x][y])continue;
        used[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int tx = x + turn[i][0], ty = y + turn[i][1];
            if (tx >= 0 && tx < N && ty >= 0 && ty < N) {
                int w = M[tx][ty];
                if (d[x][y] + w < d[tx][ty]) {
                    d[tx][ty] = d[x][y] + w;
                    if (w == 0)q.push_front({tx, ty});
                    else q.push_back({tx, ty});
                }
            }
        }
    }
    return d[0][0];
}

int main() {
    scanf("%d%d%d", &n, &sx, &sy);
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        M[a][b] = 1;
    }
    printf("%d",bfs());
}