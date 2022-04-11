
//
// Created by wyl on 2021/12/9.
//

#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N = 220;
int n,m;
PII x,y;
PII par[N][N];
PII find(int x,int y){
    if(par[x][y]== make_pair(x,y)){
        return {x,y};
    }
    else return par[x][y]=find(par[x][y].first,par[x][y].second);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            par[i][j]={i,j};
        }
    }
    int res = -1;
    for(int i=1;i<=m;i++){
        int a,b;char c;
        cin>>a>>b>>c;
        if(c=='D'){
            x = find(a,b);
            y = find(a+1,b);
        }else{
            x = find(a,b);
            y = find(a,b+1);
        }
//        cout<<x.first<<" "<<x.second<<" "<<y.first<<" "<<y.second<<endl;
        if(x==y){
            res = i;break;
        }
        par[x.first][x.second] = y;
    }
    if(res == -1)cout<<"draw"<<endl;
    else cout<<res<<endl;
}