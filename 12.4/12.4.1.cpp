
//
// Created by wyl on 2021/12/4.
//

#include<bits/stdc++.h>
using namespace std;
int n;
int ex_gcd(int a,int b,int &x,int &y){
    if(b==0){
        x = 1,y = 0;
        return a;
    }else{
        int d = ex_gcd(b,a%b,y,x);
        y = y - (a/b)*x;
        return d;
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b,x,y;cin>>a>>b;
        ex_gcd(a,b,x,y);
        cout<<x<<" "<<y<<endl;
    }
}