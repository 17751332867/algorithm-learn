
//
// Created by wyl on 2022/1/18.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 50010;
typedef pair<int,int> PII;
priority_queue<PII,vector<PII>,greater<PII> > q;
vector<PII> G[N];
int d[N];
bool used[N];
int s[10];
int n,m;
int res = 0x3f3f3f3f;
map<PII,int> table;
void dijkstra(int s){
    memset(d,0x3f,sizeof d);
    memset(used,false,sizeof used);
    d[s]=0;
    q.push({0,s});
    while (q.size()){
        int t = q.top().second;q.pop();
        if(used[t]==true)continue;
        used[t]=true;
        for(int i=0;i<G[t].size();i++){
            int pos = G[t][i].first,dist = G[t][i].second;
            if(d[pos]>d[t]+dist){
                d[pos]=d[t]+dist;
                q.push({d[pos],pos});
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    s[0]=1;
    for(int i=1;i<=5;i++)scanf("%d",&s[i]);
    for(int i=1;i<=m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        G[a].push_back({b,c});
        G[b].push_back({a,c});
    }
    for(int i=0;i<=5;i++){
        dijkstra(s[i]);
        for(int j=0;j<=5;j++){
            table[{s[i],s[j]}]=d[s[j]];
//            printf("%d %d %d\n",s[i],s[j],d[s[j]]);
        }
    }
    sort(s,s+5+1);
    do{
        int temp=0;
//        for(int i=0;i<=5;i++){
//            cout<<s[i]<<" ";
//        }
//        cout<<endl;
        for(int i=0,j=i+1;j<=5;i++,j++){
            temp+=table[{s[i],s[j]}];
        }
        res = min(temp,res);
    } while (next_permutation(s+1,s+6));
    printf("%d\n",res);
}