
//
// Created by wyl on 2022/3/4.
//

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+10;
ll n,x,y,a[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%lld %lld %lld",&n,&x,&y);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            x=x^a[i];
        }
        if(x%2==y%2){
            printf("Alice\n");
        }else{
            printf("Bob\n");
        }
    }
}