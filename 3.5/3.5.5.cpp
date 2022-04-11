
//
// Created by wyl on 2022/3/5.
//

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        string s;
        cin>>s;
        int r=0,g=0,b=0;
        bool flag = true;
        for(int i=0;i<s.size();i++){
            if(s[i]=='r')r++;
            if(s[i]=='g')g++;
            if(s[i]=='b')b++;
            if(s[i]=='R')r--;
            if(s[i]=='G')g--;
            if(s[i]=='B')b--;
            if(r<0||g<0||b<0){
                flag = false;break;
            }
        }
        if(flag){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
}