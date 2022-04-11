
//
// Created by wyl on 2022/3/4.
//

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,res=0,maxn=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            maxn = max(maxn,x);
            if(maxn==i)res++;
        }
        printf("%d\n",res);
    }
}