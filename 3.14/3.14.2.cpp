
//
// Created by wyl on 2022/3/14.
//

#include<bits/stdc++.h>

using namespace std;
int n, m;
int l[1010],r[1010],u[1010],d[1010];
int M[1010][1010];
int main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>M[i][j];
        }
    }
    memset(l,0x3f,sizeof l);
    memset(u,0x3f,sizeof u);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(M[i][j]==1){
                l[i]=min(l[i],j);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
            if(M[i][j]==1){
                r[i]=max(r[i],j);
            }
        }
    }
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            if(M[i][j]==1){
                u[j]=min(u[j],i);
            }
        }
    }
    for(int j=1;j<=m;j++){
        for(int i=n;i>=1;i--){
            if(M[i][j]==1){
                d[j]=max(d[j],i);
            }
        }
    }
    int res = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(M[i][j]==0){
                if(j>l[i])res++;
                if(j<r[i])res++;
                if(i>u[j])res++;
                if(i<d[j])res++;
            }
        }
    }
    cout<<res<<endl;
}