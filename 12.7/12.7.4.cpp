
//
// Created by wyl on 2021/12/7.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int q;
char s[N],t[N];
int main(){
    cin.sync_with_stdio(false);
    cin>>q;
    while(q--){
        cin>>s>>t;
        int lens = strlen(s), lent = strlen(t);
        int i=0,j=0;
        if(lens%2!=lent%2){
            i=1;
        }
        for(;i<lens;i++){
            if(s[i]==t[j])j++;
            else i++;
        }
        if(j==lent)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}