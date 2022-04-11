
//
// Created by wyl on 2022/3/10.
//

#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
map<char,int> tab;
map<int,char> rtab;
int m,cnt=1;
int dist[100][100];
int d[100];
int main(){
    scanf("%d",&m);
    tab['Z']=1;
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            dist[i][j]=0x3f3f3f3f;
        }
        dist[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        char u,v;int w;cin>>u>>v>>w;
        if(tab[u]==0){tab[u]=++cnt;rtab[cnt]=u;}
        if(tab[v]==0){tab[v]=++cnt;rtab[cnt]=v;}
        dist[tab[u]][tab[v]]=min(dist[tab[u]][tab[v]],w);
        dist[tab[v]][tab[u]]=min(dist[tab[v]][tab[u]],w);
    }
    for(int k=1;k<=cnt;k++){
        for(int i=1;i<=cnt;i++){
            for(int j=1;j<=cnt;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
//    for(int i=1;i<=cnt;i++){
//        cout<<i<<" ";
//        for(int j=1;j<=cnt;j++){
//            cout<<dist[i][j]<<"\t";
//        }
//        cout<<endl;
//    }
    int res = 0x3f3f3f3f;char c;
    for(int i=2;i<=cnt;i++){
        if(rtab[i]>='A'&&rtab[i]<='Z'){
            if(dist[1][i]<res){
                res = dist[1][i];c=rtab[i];
            }
        }
    }
    cout<<c<<" "<<res<<endl;
}