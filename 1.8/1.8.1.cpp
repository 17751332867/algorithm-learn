
//
// Created by wyl on 2022/1/8.
//

#include<bits/stdc++.h>

using namespace std;
const int N = 1010;

typedef pair<int, int> PII;
queue<PII> q;
char G[N][N];
int dist[N][N];
int n, m;
int turn[4][2] = {{-1, 0},
                  {0, -1},
                  {1,  0},
                  {0,  1}};

void bfs() {
    memset(dist, -1, sizeof dist);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (G[i][j] == '1') {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }
    while (q.size()) {
        auto t = q.front();q.pop();
        int x = t.first, y = t.second;
//        cout<<x<<" "<<y<<endl;
        for (int i = 0; i < 4; i++) {
            int tx = x + turn[i][0], ty = y + turn[i][1];
            if (tx >= 1 && tx <= n && ty >= 1 && ty <= m && dist[tx][ty] == -1) {
                dist[tx][ty] = dist[x][y] + 1;
                q.push({tx, ty});
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", G[i] + 1);
    }
    bfs();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d ",dist[i][j]);
        }
        printf("\n");
    }


}