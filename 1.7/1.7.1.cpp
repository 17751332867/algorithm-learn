
//
// Created by wyl on 2022/1/7.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
int turn[8][2]={{-1,-1},{-1,0},{-1,1},{0,1},{0,-1},{1,-1},{1,0},{1,1}};
char M[N][N];
int n,m,res=0;
void bfs(int a,int b){
    queue<pair<int,int> > q;
    q.push({a,b});
    M[a][b]='.';
    while(q.size()){
        auto t = q.front();q.pop();
        int x = t.first,y = t.second;
        for(int i=0;i<8;i++){
            int tx = x + turn[i][0], ty = y + turn[i][1];
            if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&M[tx][ty]=='W'){
                M[tx][ty]='.';
                q.push({tx,ty});
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s",M[i]+1);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(M[i][j]=='W'){
                bfs(i,j);
                res++;
            }
        }
    }
    printf("%d",res);
}