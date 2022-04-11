
//
// Created by wyl on 2022/3/6.
//

#include<bits/stdc++.h>
using namespace std;
int n,a[110];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        int i1 = -1,i2 = -1;
        for(int i=n;i>=1;i--){
            if(a[i]!=1)break;
            i1=i;
        }
        for(int i=1;i<=n;i++){
            if(a[i]!=1)break;
            i2 = i;
        }
        if(i1-i2>=0)cout<<i1-i2<<endl;
        else cout<<0<<endl;
    }
}