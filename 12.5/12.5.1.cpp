
//
// Created by wyl on 2021/12/5.
//

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10;
int n,t,data[N];
const int mod = 998244353;
int A(int x){
    int res = 1;
    for(int i=1;i<=x;i++){
        res = (res*i)%mod;
    }
    return res;
}
signed main(){
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>data[i];
        }
        sort(data,data+n);
        int max1 = data[n-1],max2=data[n-2];
//        cout<<"debug"<<max1<<" "<<max2<<endl;
        if(max1-max2==0){
            cout<<A(n)<<endl;
        }else if(max1-max2>1){
            cout<<0<<endl;
        }else{
            int num1 = 0, num2 = 0, num3 = 0;
            for(int i=0;i<n;i++){
                if(data[i]==max1)num1++;
                else if(data[i]==max2)num2++;
                else num3++;
            }
            int res = (num2*A(num2))%mod;
            int temp = num1+num2;
            for(int i=0;i<num3;i++){
                res = (res*(++temp))%mod;
            }
            cout<<res<<endl;
        }
    }
}