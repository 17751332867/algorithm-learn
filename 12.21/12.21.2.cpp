#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int n,du[N];
int G[N][N];
stack<char> res;
int start = 150,cnt=0;
void dfs(int x){
    for(int i=1;i<=150;i++){
        if(G[x][i]>0){
            G[x][i]=G[i][x]=0;
            dfs(i);
        }
    }
    res.push(x);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        char str[3];
        scanf("%s",str);
        G[str[0]][str[1]]=1;
        G[str[1]][str[0]]=1;
        du[str[0]]++;du[str[1]]++;
    }
    for(int i=1;i<=150;i++){
        if(du[i]%2==1)start=min(start,i),cnt++;
    }
    if(cnt==0){
        for(int i=1;i<=150;i++){
            if(du[i]!=0)start=min(start,i);
        }
    }
    if(cnt!=0&&cnt!=2){
        return !printf("No Solution\n");
    }

    dfs(start);
    if(res.size()!=n+1){
        return !printf("No Solution\n");
    }
    while(res.size()){ printf("%c",res.top());res.pop();}
}