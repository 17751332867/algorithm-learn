
//
// Created by wyl on 2022/3/12.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
int n,m;
int a[N][N];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int x1,x2,y1,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        for(int i=x1;i<=x2;i++){
            a[i][y1]++;
            a[i][y2+1]--;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j]+=a[i][j-1];
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}