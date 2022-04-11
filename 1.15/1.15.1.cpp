
//
// Created by wyl on 2022/1/15.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 15;
char X[N],Y[N];
int len;
bool flag= false;
int main(){
    cin>>X>>Y;
    len = strlen(X);
    while(prev_permutation(X,X+len)){
        if(X[0]=='0')break;
    }
    next_permutation(X,X+len);
    if(strcmp(X,Y)==0){
        flag = true;
    }
    if(flag==true){
        puts("YES");
    }else{
        puts("NO");
    }
}