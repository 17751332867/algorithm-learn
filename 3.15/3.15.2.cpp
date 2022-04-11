
//
// Created by wyl on 2022/3/31.
//

#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        sort(a+1,a+n+1);
        if(a[n]-a[n-1]<=1){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}