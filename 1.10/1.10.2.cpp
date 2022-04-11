
//
// Created by wyl on 2022/1/10.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 10;
char s1[N];
char s2[N];
int len;
int find(char ch){
    for(int i=0;i<len;i++){
        if(s1[i]==ch)return i;
    }
}
void dfs(int l1,int r1,int l2,int r2){
    int m = find(s2[r2]);
    putchar(s2[r2]);
    if(m>l1)dfs(l1,m-1,l2,l2+(m-1-l1));
    if(m<r1)dfs(m+1,r1,l2+(m-l1),r2-1);
}
int main(){
    cin>>s1>>s2;
    len= strlen(s1);
    dfs(0,len-1,0,len-1);
}