
//
// Created by wyl on 2022/2/4.
//

#include<bits/stdc++.h>
using namespace std;
int t,n,m,res;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        if(m==1&&n!=1){ printf("-1\n");continue;}
        n-=m;m--;res=1;
        if(n>0){
            res+=((n+m-1)/m)*2;
        }
        printf("%d\n",res);
    }
}