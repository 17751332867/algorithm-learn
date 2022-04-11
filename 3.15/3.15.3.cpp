
//
// Created by wyl on 2022/3/31.
//

#include<bits/stdc++.h>
using namespace std;
string s;
int a[200010];
bool used[30];

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        cin>>s;
        stack<char> sta;
        memset(used,false,sizeof used);
        int res = 0;
        for(int i=0;i<s.size();i++){
            if(!used[s[i]-'a']){sta.push(s[i]),used[s[i]-'a']=true;}
            else{
                res+=2;while(!sta.empty())sta.pop();
                memset(used, false,sizeof used);
            }
        }
        cout<<s.size()-res<<endl;
    }
}