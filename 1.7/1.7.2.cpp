
//
// Created by wyl on 2022/1/7.
//

#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;
const int N = 1010;
int turn[4][2] = {{1,  0},
                  {0,  1},
                  {-1, 0},
                  {0,  -1}};

PII res[N][N];
int M[N][N];
bool used[N][N];
int n;

void bfs(int a, int b) {
    queue<PII> q;
    q.push({a, b});
    used[a][b] = true;
    while (q.size()) {
        auto t = q.front();
        q.pop();
        int x = t.first, y = t.second;
        for (int i = 0; i < 4; i++) {
            int tx = x + turn[i][0], ty = y + turn[i][1];
            if(tx>=1&&tx<=n&&ty>=1&&ty<=n&&used[tx][ty]==false&&M[tx][ty]==0){
                used[tx][ty]=true;
                q.push({tx,ty});
                res[tx][ty]=t;
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &M[i][j]);
        }
    }
    bfs(n,n);
    int tx = 1,ty = 1;
    printf("%d %d\n",tx-1,ty-1);
    while(!(tx==n&&ty==n)){
        auto t = res[tx][ty];
        tx = t.first, ty = t.second;
        printf("%d %d\n",tx-1,ty-1);
    }
}