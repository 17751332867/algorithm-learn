
//
// Created by wyl on 2022/1/6.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 500+10;
int G[N][N];
int dist[N];
int n,m;
int stop[N];
string line;
void bfs(){
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    queue<int> q;
    q.push(1);
    while(q.size()){
        int t = q.front();q.pop();
        for(int i=1;i<=n;i++){
            if(G[t][i]>0){
                if(dist[i]>dist[t]+G[t][i]){
                    dist[i]=dist[t]+G[t][i];
                    q.push(i);
                }
            }
        }
    }
}
int main(){
    scanf("%d%d",&m,&n);
    getline(cin,line);
    while(m--){
        getline(cin,line);
        stringstream ss(line);
        int cnt=0,p;
        while(ss>>p)stop[cnt++]=p;
        for(int i=0;i<cnt;i++){
            for(int j=i+1;j<cnt;j++){
                G[stop[i]][stop[j]]=1;
            }
        }
    }
    bfs();
    if(dist[n]==0x3f3f3f3f){
        puts("NO");
    }else{
        cout<<max(dist[n]-1,0)<<endl;
    }
}