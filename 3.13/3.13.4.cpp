
//
// Created by wyl on 2022/3/13.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int n;
int kmp[N];
char s[N];
int main(){
    scanf("%d%s",&n,s+1);
    for(int i=2,j=0;i<=n;i++){
        while(j&&s[i]!=s[j+1])j=kmp[j];
        if(s[i]==s[j+1])j++;
        kmp[i]=j;
    }
    printf("%d",n-kmp[n]);
}