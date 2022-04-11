
//
// Created by wyl on 2021/12/11.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int res[N];
int t,n,a,b;
void solve(){
    cin>>n>>a>>b;
    if(n<=2) {cout<<-1<<endl;return;}
    if(a>=(n+1)/2||b>=(n+1)/2||(a+b)>n-2||abs(a-b)>1){
        cout<<-1<<endl;return;
    }
    if(b>a){
        int cnt = 1;
        for(int i=2,numn=1;i<=n-1&&numn<=b;i+=2,numn++){
           // cout<<i<<" "<<cnt<<endl;
            res[i]=cnt++;
        }
        for(int i=3,numn=1;i<=n-1&&numn<=a;i+=2,numn++){
            res[i]=cnt++;
        }
        for(int i=a+b+2;i<=n;i++){
            res[i]=cnt++;
        }
        res[1]=cnt++;
    }else if(b<a){
        int cnt = 1;
        for(int i=n;i>=a+b+2;i--){
            res[i]=cnt++;
        }
        res[1]=cnt++;
        for(int i=3,numn=1;i<=n-1&&numn<=b;i+=2,numn++){
            res[i]=cnt++;
        }
        for(int i=2,numn=1;i<=n-1&&numn<=a;i+=2,numn++){
            res[i]=cnt++;
        }
    }else{
        int cnt = 1;
        res[1]=cnt++;
        for(int i=3,numn=1;i<=n-1&&numn<=a;i+=2,numn++){
            res[i]=cnt++;
        }
        for(int i=2,numn=1;i<=n-1&&numn<=b;i+=2,numn++){
            res[i]=cnt++;
        }
        for(int i=a+b+2;i<=n;i++){
            res[i]=cnt++;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
}
int main(){
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
    }
}