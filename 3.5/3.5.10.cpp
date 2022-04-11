
//
// Created by wyl on 2022/3/5.
//

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;cin>>n;
        string s1,s2;cin>>s1>>s2;
        int a=0,b=0;//相同,不同
        int a0=0,a1=0,b1=0,b0=0;
        for(int i=0;i<n;i++){
            if(s1[i]==s2[i]){
                a++;
                if(s1[i]=='0')a0++;
                else a1++;
            }
            else{
                b++;
                if(s1[i]=='0')b0++;
                else b1++;
            }
        }
//        cout<<a<<" "<<b<<endl;
        int res = INT_MAX;
        if(a%2==1&&a1-a0==1){
            res = min(res,a);
        }
        if(b%2==0&&b1==b0){
            res = min(res,b);
        }
        if(res==INT_MAX){
            cout<<-1<<endl;
        }else{
            cout<<res<<endl;
        }
    }
}