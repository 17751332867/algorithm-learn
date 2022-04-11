//
// Created by wyl on 2021/12/4.
//

#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int g[1010][1010];
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&g[i][j]);
        }
    }
    for(int i=0;i<k;i++){
        int x=1,y;
        scanf("%d",&y);
        while(x<=n){
            int a = g[x][y];
            g[x][y]=2;
            if(a==1){y++;}
            if(a==2){x++;}
            if(a==3){y--;}
        }
        printf("%d ",y);
    }
}