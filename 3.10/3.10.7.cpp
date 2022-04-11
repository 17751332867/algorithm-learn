
//
// Created by wyl on 2022/3/10.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 2020;
typedef pair<int,int> PII;
int n,c;
PII p[N];
int G[N][N],d[N];
bool used[N];
int dist(PII p1,PII p2){
    int x = p1.first - p2.first;
    int y = p1.second - p2.second;
    return x*x+y*y;
}
int prim(){
    memset(d,0x3f,sizeof d);
    d[1]=0;
    int res = 0;
    for(int i=1;i<=n;i++){
        int t = -1;
        for(int j=1;j<=n;j++){
            if(!used[j]&&(t==-1||d[j]<d[t])){
                t = j;
            }
        }
//        cout<<d[t]<<endl;
        if(d[t]==0x3f3f3f3f)return -1;
        used[t]=true;
        res+=d[t];
        for(int j=1;j<=n;j++){
            d[j]=min(d[j],G[t][j]);
        }
    }
    return res;
}
int main(){
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&p[i].first,&p[i].second);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int dis = dist(p[i],p[j]);
            if(dis>=c)G[i][j]=dis;
            else G[i][j]=0x3f3f3f3f;
        }
        G[i][i]=0;
    }
    cout<<prim()<<endl;
}