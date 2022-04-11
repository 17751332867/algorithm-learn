
//
// Created by wyl on 2022/2/2.
//

#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> PII;
int turn[4][2] = {{-1, 0},
                  {1,  0},
                  {0,  -1},
                  {0,  1}};

char M[100][100];
int res[100][100];
int n, m, cnt;
queue<PII> q;

void dfs(int x, int y) {
    M[x][y] = '0' + cnt;
    q.push({x, y});
    for (int i = 0; i < 4; i++) {
        int tx = turn[i][0] + x;
        int ty = turn[i][1] + y;
        if (tx >= 1 && tx <= n && ty >= 1 && ty <= m && M[tx][ty] == 'X') {
            dfs(tx, ty);
        }
    }
}

int bfs() {
    while (q.size()) {
        auto t = q.front();q.pop();
        int x = t.first, y = t.second;
        for (int i = 0; i < 4; i++) {
            int tx = x + turn[i][0];
            int ty = y + turn[i][1];
            if (tx >= 1 && tx <= n && ty >= 1 && ty <= m && M[tx][ty] != M[x][y]) {
                if (M[tx][ty] == '.') {
                    res[tx][ty] = res[x][y] + 1;
                    M[tx][ty]=M[x][y];
                    q.push({tx,ty});
                } else {
                    return res[tx][ty] + res[x][y];
                }
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", M[i] + 1);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (M[i][j] == 'X') {
                cnt++;
                dfs(i, j);
            }
        }
    }
    printf("%d",bfs());
}