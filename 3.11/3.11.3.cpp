
//
// Created by wyl on 2022/3/11.
//

#include<bits/stdc++.h>
using namespace std;
int n,m;
unordered_map<string ,int> maps;
string s;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        cin>>s;
        maps[s]++;
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        cin>>s;
        int res = maps[s]++;
        if(res==0){
            puts("WRONG");
        }else if(res==1){
            puts("OK");
        }else{
            puts("REPEAT");
        }
    }
}