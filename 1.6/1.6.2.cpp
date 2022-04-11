
//
// Created by wyl.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 510;
int G[N][N];
int dist[N];
bool used[N];
int m,n;
int stop[N];
string line;
void dijkstra(){
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    for(int i=0;i<n;i++){
        int t = -1;
        for(int j=1;j<=n;j++){
            if(!used[j]&&(t==-1||dist[j]<dist[t]))t=j;
        }
        used[t]=true;
        for(int j=1;j<=n;j++){
            dist[j]=min(dist[j],dist[t]+G[t][j]);
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){

    }

}