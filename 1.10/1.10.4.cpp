
//
// Created by wyl on 2022/1/10.
//

#include<bits/stdc++.h>
using namespace std;
double eps=1e-6;
const int N = 100;

double a[N],b[N];

void solve(){
    int res = 1e9;
    int n;cin>>n;
    for(int i=1;i<=n;i++){cin>>a[i];}
    if(n==1||n==2){cout<<0<<endl;return;}
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            double q = (a[j]-a[i])/(j-i);
            double a0 = a[i] - i*q;
            for(int k=1;k<=n;k++){
                b[k] = a0+k*q;
//                cout<<b[i]<<" ";
            }
//            cout<<endl;
            int cnt = 0;
            for(int k=1;k<=n;k++){
//                cout<<a[k]<<" "<<b[k]<<" "<<fabs(a[k]-b[k])<<endl;
                if(fabs(a[k]-b[k])>eps){
                    cnt++;
                }
            }
            res = min(res,cnt);
        }
    }
    cout<<res<<endl;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}