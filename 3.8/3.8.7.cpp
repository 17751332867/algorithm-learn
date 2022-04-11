
//
// Created by wyl on 2022/3/9.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
struct node{
    int num,idx;
}d[N];
int a[N];
bool cmp(node n1,node n2){
    return n1.num<n2.num;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;cin>>n;
        a[0]=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            d[i].idx = i;d[i].num=a[i]-a[i-1]-1;
        }
        sort(d+1,d+n+1,cmp);
        node minn = d[1];
        node maxn = d[n];
        int res = minn.num;
        int tt = (maxn.num-1)/2;
        int idx = minn.idx;
        for(int i=1;i<=n;i++){
            if(d[i].idx == idx){

            }
        }
    }
}