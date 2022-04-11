
//
// Created by wyl on 2021/12/21.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 110;
int n;
int G[N][N];
int dist[N];
bool used[N];
int prim(){
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    int res = 0;
    for(int i=0;i<n;i++){
        int t = -1;
        for(int j=1;j<=n;j++){
            if(!used[j]&&(t==-1||dist[j]<dist[t])) {
                t = j;
            }
        }
        res += dist[t];
        used[t]=true;
        for(int j=1;j<=n;j++){
            dist[j]=min(dist[j],G[t][j]);
        }
    }
    return res;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&G[i][j]);
        }
    }
    printf("%d\n",prim());
}