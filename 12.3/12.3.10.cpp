
//
// Created by wyl on 2021/12/3.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 510;
vector<int> g[N];
int used[N],match[N];
int n1,n2,m,res=0;
bool find(int x){
    for(int i=0;i<g[x].size();i++){
        int j = g[x][i];
        if(!used[j]){
            used[j]=true;
            if(match[j]==0||find(match[j])){
                match[j]=x;
                return true;
            }
        }
    }
    return false;
}
int main(){
    cin>>n1>>n2>>m;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
    }
    for(int i=1;i<=n1;i++){
        memset(used, false,sizeof used);
        if(find(i)){
           res++;
        }
    }
    cout<<res<<endl;
    return 0;
}