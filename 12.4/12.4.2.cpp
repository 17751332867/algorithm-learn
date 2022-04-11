
//
// Created by wyl on 2021/12/4.
//

#include<bits/stdc++.h>
using namespace std;
int exgcd(int a,int b,int &x,int &y){
    if(b==0){
        x = 1,y=0;
        return a;
    }else{
        int d = exgcd(b,a%b,y,x);
        y = y - (a/b) * x;
        return d;
    }
}

int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int a,b,m,x,y;cin>>a>>b>>m;
        int d = exgcd(a,m,x,y);
        if(b%d){
            cout<<"impossible"<<endl;
        }else{
            cout<<x*(b/d)%m<<endl;
        }
    }
    return 0;
}