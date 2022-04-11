
//
// Created by wyl on 2021/12/6.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int t,n;
char str[N],temp[N];
int solve(){
    cin>>n;
    cin>>str;
    int res = 0x3f3f3f3f;
    for(char c = 'a';c<='z';c++){
        int l=0,r=n-1;
        bool tag = true;
        int cnt = 0;
        while(l<=r){
            //cout<<c<<" "<<str[l]<<" "<<str[r]<<endl;
            if(str[l]==str[r]){
                l++,r--;
            }else{
                if(str[l]==c){
                    cnt++;l++;
                }else if(str[r]==c){
                    cnt++;r--;
                }else{
                    tag= false;break;
                }
            }
        }
        if(tag== true){
            res = min(cnt,res);
        }
    }
    if(res==0x3f3f3f3f)return -1;
    return res;
}
int main(){
    cin>>t;
    for(int i=0;i<t;i++){
        cout<<solve()<<endl;
    }
}