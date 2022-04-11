
//
// Created by wyl on 2022/4/8.
//

#include<bits/stdc++.h>
using namespace std;
int n,m;
struct edge{
    int val,idx;
}ez[1000];
priority_queue<int> pq;
queue<edge> q;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        while (q.size())q.pop();
        while(pq.size())pq.pop();
        cin>>n>>m;
        for(int i=0;i<n;i++){
            scanf("%d",&ez[i].val);
            ez[i].idx = i;
            q.push(ez[i]);
            pq.push(ez[i].val);
        }
        int cnt = 0;
        while(q.size()){
            int tt = pq.top();
            edge t = q.front();
            q.pop();
            if(t.val==tt){
                pq.pop();
                cnt++;
                if(t.idx==m)break;
            }else{
                q.push(t);
            }
        }
        cout<<cnt<<endl;
    }
}