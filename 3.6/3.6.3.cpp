
//
// Created by wyl on 2022/3/6.
//

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+10;
int a[N],n;
signed main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        bool flag = true;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]!=0){
                flag = false;
            }
        }
        if(flag == true){
            cout<<0<<endl;continue;
        }
        sort(a+1,a+n+1);
        int sumn = 0;
        for(int i=1;i<n;i++){
            sumn+=a[i];
        }
        if(a[n]-sumn<=1){
            cout<<1<<endl;
        }else{
            cout<<a[n]-sumn<<endl;
        }
    }
}