
//
// Created by wyl on 2021/12/7.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int t,n;
int a[N],sum1[N],sum2[N];
int main(){
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        int res = INT_MAX;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            sum1[i]=sum1[i-1]+a[i];
        }
        for(int i=1;i<=n;i++){
            cin>>a[i];
            sum2[i]=sum2[i-1]+a[i];
        }

        int maxn = 0;
        for(int i=1;i<=n;i++){
//            cout<<sum1[n]-sum1[i]<<" "<<sum2[i-1]<<endl;
            maxn = max(sum1[n]-sum1[i],sum2[i-1]);
            res = min(maxn,res);
        }
        cout<<res<<endl;
    }
}