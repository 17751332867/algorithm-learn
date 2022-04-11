
//
// Created by wyl on 2022/1/20.
//

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 50;
const int mod = 1 << 31;
ll f[N];
int n;
string res;

int main() {
    f[2] = f[1] = 1;
    cin >> n;
//    cout<<res<<endl;
    for (int i = 3; i <= n; i++) {
        f[i] = (f[i - 1] + f[i - 2])%mod;
    }
    ll t = f[n];
    cout<<t<<"=";
    for(int i=2;i*i<=t;i++){
        while(t%i==0){
            if(t!=i)cout<<i<<"*";
            else cout<<i;
            t = t/i;
        }
    }
    if(t==1){

    }else{
        cout<<t<<endl;
    }

}