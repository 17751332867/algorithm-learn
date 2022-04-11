
//
// Created by wyl on 2022/1/9.
//

#include<bits/stdc++.h>

using namespace std;
int n, m;
char g[30][30];
int turn[4][2] = {{-1, 0},
                  {0,  -1},
                  {1,  0},
                  {0,  1}};

void dfs(int x, int y) {
    g[x][y] = '*';
    for (int i = 0; i < 4; i++) {
        int tx = x + turn[i][0], ty = y + turn[i][1];
        if (tx >= 1 && tx <= n && ty >= 1 && ty <= m && g[tx][ty] == '.') {
            dfs(tx, ty);
        }
    }
}

int main() {
    while (scanf("%d%d", &m, &n)) {
        if (m == 0 && n == 0)break;
        for (int i = 1; i <= n; i++) {
            scanf("%s", g[i] + 1);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if(g[i][j]=='@'){
                    dfs(i, j);
                }
            }
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (g[i][j] == '*') {
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt);
    }
}