
//
// Created by wyl on 2021/12/27.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int p[N][30],sumn[30];
void init(){
    for(int i=1;i<=N;i++){
        int t = i;
        for(int j=0;j<30;j++){
            p[i][j] = p[i-1][j]+(t>>j)%2;
        }
    }
}
int solve(){
    int l,r;
    scanf("%d%d",&l,&r);
    int maxn = 0;
    for(int i=0;i<30;i++){
        sumn[i]=p[r][i]-p[l-1][i];
        maxn = max(maxn,sumn[i]);
    }
    return r-l+1-maxn;
}
int main(){
    init();
    int t;
    scanf("%d",&t);
    while(t--){
        int res = solve();
        cout<<res<<endl;
    }
}