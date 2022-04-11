
//
// Created by wyl on 2021/12/21.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 110;
const int M = 210;
int n,k,res;
int par[N];
struct edge{
    int a,b,c;
    bool operator< (const edge& t)const{
        return c<t.c;
    }
}ez[M];
int find(int x){
    if(x==par[x])return x;
    else return par[x]=find(par[x]);
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<k;i++){
        cin>>ez[i].a>>ez[i].b>>ez[i].c;
    }
    for(int i=1;i<=n;i++){par[i]=i;}
    sort(ez,ez+k);
    for(int i=0;i<k;i++){
        int a = find(ez[i].a),b=find(ez[i].b);
        if(a!=b)par[a]=b;
        else res+=ez[i].c;
    }
    printf("%d\n",res);
}