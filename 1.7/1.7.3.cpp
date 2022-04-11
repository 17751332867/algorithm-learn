
//
// Created by wyl on 2022/1/7.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 160;
char M[N][N];
int turn[8][2]={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
int n,m;
int sx,sy,tx,ty;
int res[N][N];
int bfs(){
    queue<pair<int,int> > q;
    q.push({sx,sy});
    while(q.size()){
        auto t = q.front();q.pop();
        for(int i=0;i<8;i++){
            int x = t.first+turn[i][0],y = t.second+turn[i][1];
            if(M[x][y]=='H')return res[t.first][t.second]+1;
            if(x>=1&&x<=n&&y>=1&&y<=m&&M[x][y]=='.'&&res[x][y]==0){
                res[x][y]=res[t.first][t.second]+1;
                q.push({x,y});
            }
        }
    }
}
int main(){
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++){
        scanf("%s",M[i]+1);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(M[i][j]=='K'){sx=i,sy=j;}
            if(M[i][j]=='H'){tx=i,ty=j;}
        }
    }
    printf("%d\n",bfs());
}