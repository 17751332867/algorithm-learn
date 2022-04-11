
//
// Created by wyl on 2022/3/13.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int nex[N];
int n,m;
char s[N],t[N];
int main(){
    scanf("%s",s+1);
    scanf("%s",t+1);
    n = strlen(s+1); m = strlen(t+1);
    for(int i=2,j=0;i<=m;i++){
        while(j&&t[j+1]!=t[i])j=nex[j];
        if(t[j+1]==t[i])j++;
        nex[i]=j;
    }
    for(int i=1,j=0;i<=n;i++){
        while(j&&s[i]!=t[j+1])j=nex[j];
        if(s[i]==t[j+1])j++;
        if(j==m){
            printf("%d\n",i-m+1);
        }
    }
    for(int i=1;i<=m;i++){
        printf("%d ",nex[i]);
    }
}