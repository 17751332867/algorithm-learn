
//
// Created by wyl on 2022/1/7.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int sx,tx;
int M[N],dist[N];
int bfs(){
    queue<int > q;
    q.push(sx);

    while(q.size()){
        int t = q.front();q.pop();
        if(t==tx)return dist[tx];
        int x1 = t-1;
        if(x1<=N&&x1>=0&&dist[x1]==0){dist[x1]=dist[t]+1;q.push(x1);}
        int x2 = t+1;
        if(x2<=N&&x2>=0&&dist[x2]==0){dist[x2]=dist[t]+1;q.push(x2);}
        int x3 = 2*t;
        if(x3<=N&&x3>=0&&dist[x3]==0){dist[x3]=dist[t]+1;q.push(x3);}
//        cout<<x1<<" "<<x2<<" "<<x3<<endl;
    }
}
int main(){
    scanf("%d%d",&sx,&tx);
    printf("%d\n",bfs());
}