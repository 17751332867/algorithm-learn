
//
// Created by wyl on 2021/12/11.
//

#include<bits/stdc++.h>
using namespace std;
void solve(){
    int a,b,n;cin>>n>>a>>b;
    int up = n;
    int down = 1;
    if(n==2){
        if(a==0&&b==0){
            cout<<1<<" "<<2<<endl;
            return;
        }else{
            cout<<-1<<endl;
            return;
        }
    }
    if(a+b>n-2||abs(a-b)>1){
        cout<<-1<<endl;
        return;
    }
    if(a>b){
        while(a>0||b>0){
            cout<<down++<<" ";
            cout<<up--<<" ";
            a--;b--;
        }
        for(int i=up;i>=down;i--){
            cout<<i<<" ";
        }
    }else if(a<b){
        while(a>0||b>0){
            cout<<up--<<" ";
            cout<<down++<<" ";
            a--;b--;
        }
        for(int i=down;i<=up;i++){
            cout<<i<<" ";
        }
    }else{
        while(a>0||b>0){
            cout<<up--<<" ";
            cout<<down++<<" ";
            a--;b--;
        }
        for(int i=up;i>=down;i--){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}