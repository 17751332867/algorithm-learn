
//
// Created by wyl on 2022/1/15.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
int n,k;
int a[N]={1,1};
int main(){
    cin>>n>>k;
    int mod = 2022*k;
    for(int i=2;i<=n;i++){
        a[i]=(a[i-1]+a[i-2])%mod;
        if(a[i]%k==1){
            a[i]=(a[i]+mod-1)%mod;
        }
    }
    cout<<(a[n])%mod<<endl;
}