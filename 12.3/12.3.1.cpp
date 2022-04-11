
//
// Created by wyl on 2021/12/3.
//
#include<bits/stdc++.h>
using namespace std;
const int N = 510;
int g[N][N];
int n,m;
int d[N];
bool used[N];
void dijkstra(){
    for(int i=0;i<=n;i++){d[i]=0x3f3f3f;used[i]= false;}
    d[1]=0;
    for(int i=0;i<n;i++){
        int t=-1;
        for(int j=1;j<=n;j++){
            if(used[j]== false&&(t==-1||d[j]<d[t])){
                t=j;
            }
        }
        used[t]=true;
        for(int j=1;j<=n;j++){
            d[j]=min(d[j],d[t]+g[t][j]);
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            g[i][j]=0x3f3f3f;
        }
    }
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        g[a][b]=min(g[a][b],c);
    }
    dijkstra();
    if(d[n]==0x3f3f3f){
        cout<<"-1"<<endl;
    }else{
        cout<<d[n]<<endl;
    }
}
