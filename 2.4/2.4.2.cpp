
//
// Created by wyl on 2022/2/4.
//

#include<bits/stdc++.h>

using namespace std;
const int N = 10;
int turn[4][2] = {{-1, 0},
                  {1,  0},
                  {0,  -1},
                  {0,  1}};
char M[N][N];
bool used[N][N];
int n, res = 0;

void dfs(int x, int y, int l, int r) {
//    cout<<x<<" "<<y<<" "<<l<<" "<<r<<endl;
    if (l == r) { res=max(res,2*l); return;}
    for (int i = 0; i < 4; i++) {
        int tx = x + turn[i][0], ty = y + turn[i][1];
        if (tx >= 1 && tx <= n && ty >= 1 && ty <= n && used[tx][ty] == false) {
            if(r>0&&M[tx][ty]=='(')continue;
            used[tx][ty]=true;
            if(M[tx][ty]=='(')dfs(tx,ty,l+1,r);
            else dfs(tx,ty,l,r+1);
            used[tx][ty]= false;
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", M[i] + 1);
    }
    if(M[1][1]=='('){
        used[1][1] = true;
        dfs(1, 1, 1, 0);
    }
    printf("%d",res);
}