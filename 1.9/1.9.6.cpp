
//
// Created by wyl on 2022/1/9.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 25;
string word[N];
int g[N][N];
int used[N];
int n;
int ans;
char start;
void dfs(int t,string s){
    ans = max((int)s.size(),ans);
    used[t]++;
    for(int i=1;i<=n;i++){
        if(g[t][i]!=0&&used[i]<2){
            dfs(i,s+word[i].substr(g[t][i]));
        }
    }
    used[t]--;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin>>word[i];
    }
    cin>>start;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<min(word[i].size(),word[j].size());k++){
                if(word[i].substr(word[i].size()-k)==word[j].substr(0,k)){
                    g[i][j]=k;break;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
        if(word[i][0]==start)
            dfs(i,word[i]);
    printf("%d\n",ans);
}