
//
// Created by wyl on 2022/3/14.
//

#include<bits/stdc++.h>
using namespace std;
int table[256];
string s;
void init(){
    table['0']=0;table['1']=1;table['2']=1;table['3']=2;
    table['4']=1;table['5']=2;table['6']=2;table['7']=3;
    table['8']=1;table['9']=2;table['a']=2;table['b']=3;
    table['c']=2;table['d']=3;table['e']=3;table['f']=4;
}
int main(){
    cin>>s;
    init();
    int res = 0;
    for(int i=2;i<s.size();i++){
        res+=table[s[i]];
    }
    cout<<res<<endl;
}