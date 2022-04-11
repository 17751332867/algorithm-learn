
//
// Created by wyl on 2022/1/9.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 110;
int n;
int sx,sy,tx,ty;
int turn[4][2]={{-1,0},{0,-1},{0,1},{1,0}};
char g[N][N];
void dfs(int x,int y){

    g[x][y]='#';
    for(int i=0;i<4;i++){
        int tx = x+turn[i][0],ty=y+turn[i][1];
        if(tx>=0&&tx<n&&ty>=0&&ty<n&&g[tx][ty]=='.'){
            dfs(tx,ty);
        }
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%s",g[i]);
        }
        scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
        if(g[tx][ty]=='#'||g[sx][sy]=='#')puts("NO");
        else{
            dfs(sx,sy);
            if(g[tx][ty]=='#'){
                puts("YES");
            }else{
                puts("NO");
            }
        }
    }
}