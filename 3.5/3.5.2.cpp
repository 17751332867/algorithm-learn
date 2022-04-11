
//
// Created by wyl on 2022/3/5.
//

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,s;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%lld %lld",&n,&s);
        printf("%lld\n",s/(n*n));
    }
}