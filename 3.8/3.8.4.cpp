
//
// Created by wyl on 2022/3/8.
//

#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int t;
    scanf("%lld",&t);
    while(t--){
        int l,r,a;
        cin>>l>>r>>a;
        int i = (r+1)/a * a -1;
        if(l<=i){
            cout<<i/a+i%a<<endl;
        }else{
            cout<<r/a+r%a<<endl;
        }
    }
}