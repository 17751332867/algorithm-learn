
//
// Created by wyl on 2021/12/3.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 210;
const int INF = 0x3f3f3f3f;
int n,m,q;
int d[N][N];
void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
}
int main(){
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            d[i][j]=INF;
        }
        d[i][i]=0;
    }
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        d[a][b]=min(d[a][b],c);
    }
    floyd();
    for(int i=0;i<q;i++){
        int a,b;cin>>a>>b;
        if(d[a][b]>INF/2) cout<<"impossible"<<endl;
        else cout<<d[a][b]<<endl;
    }
    return 0;
}