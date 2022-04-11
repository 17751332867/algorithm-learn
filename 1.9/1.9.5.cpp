
//
// Created by wyl on 2022/1/9.
//

#include<bits/stdc++.h>

using namespace std;
const int N = 10;
bool used[N][N];
int m, n, sx, sy;
int res = 0;
int turn[8][2] = {{-2, -1},
                  {-1, -2},
                  {1,  -2},
                  {-2, 1},
                  {-1, 2},
                  {2,  -1},
                  {1,  2},
                  {2,  1}};

void dfs(int x, int y, int cnt) {
//    cout<<x<<" "<<y<<" "<<cnt<<endl;
//    for(int i=0;i<n;i++){
//        for(int j=0;j<m;j++){
//            cout<<used[i][j]<<" ";
//        }
//        cout<<endl;
//    }
//    cout<<"-----------------"<<endl;
    if (cnt == n * m) {
        res++;return;
    }
    for (int i = 0; i < 8; i++) {
        int tx = x + turn[i][0], ty = y + turn[i][1];
        if(tx>=0&&tx<n&&ty>=0&&ty<m&&!used[tx][ty]){
            used[tx][ty]=true;
            dfs(tx,ty,cnt+1);
            used[tx][ty]= false;
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        res = 0;
        scanf("%d%d%d%d", &n, &m, &sx, &sy);
        used[sx][sy] = true;
        dfs(sx, sy, 1);
        used[sx][sy] = false;
        printf("%d\n",res);
    }

}