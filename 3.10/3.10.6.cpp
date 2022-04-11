
//
// Created by wyl on 2022/3/10.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 5001;
typedef pair<int,int> PII;
PII p[N];
int n;
double d[N];bool used[N];
double dist(PII p1,PII p2){
    double x = p1.first - p2.first;
    double y = p1.second - p2.second;
    return sqrt(x*x+y*y);
}
void prim(){
    for(int i=0;i<=n;i++){d[i]=0x3f3f3f3f;}
    d[1]=0;
    double res = 0;
    for(int i=0;i<n;i++){
        int t = -1;
        for(int j=1;j<=n;j++){
            if(!used[j]&&(t==-1||d[j]<d[t])){
                t = j;
            }
        }
        used[t]=true;
        res+=d[t];
        for(int j=1;j<=n;j++){
            d[j]=min(d[j],dist(p[t],p[j]));
        }
    }
    printf("%.2lf",res);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&p[i].first,&p[i].second);
    }
    prim();
}