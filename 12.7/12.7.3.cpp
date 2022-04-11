
//
// Created by wyl on 2021/12/7.
//

#include<bits/stdc++.h>
using namespace std;
int t;
char str[15],temp[15];
void copy(int len){
    for(int i=1;i<=len;i++){
        temp[i]=str[i];
    }
}
void solve(){
    cin>>str+1;
    int len = strlen(str+1);
    copy(len);
    int s1=0,s2=0;
    int res = 10;
    for(int i=1;i<=len;i++){
        if(i%2==1){
            if(str[i]=='1')s1++;
            if(str[i]=='?')s1++;
        }else{
            if(str[i]=='1')s2++;
        }
        if(s1>s2){
            if(s1-s2>(len-i+1)/2){
                res = min(res,i);
                break;
            }
        }
        if(s2>s1){
            if(s2-s1>(len-i)/2){
                res = min(res,i);
                break;
            }
        }
    }
    s1 = s2 = 0;
    for(int i=1;i<=len;i++){
        if(i%2==1){
            if(str[i]=='1')s1++;
        }else{
            if(str[i]=='1')s2++;
            if(str[i]=='?')s2++;
        }
        if(s1>s2){
            if(s1-s2>(len-i+1)/2){
                res = min(res,i);
                break;
            }
        }
        if(s2>s1){
            if(s2-s1>(len-i)/2){
                res = min(res,i);
                break;
            }
        }
    }
    cout<<res<<endl;
}
int main(){
    scanf("%d",&t);
    while(t--){
        solve();
    }
}