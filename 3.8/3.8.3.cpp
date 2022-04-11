
//
// Created by wyl on 2022/3/8.
//

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        string s;char c;
        cin>>s>>c;
        bool flag = false;
        for(int i=0;i<s.size();i+=2){
            if(c==s[i]){
                flag = true;break;
            }
        }
        if(flag){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}