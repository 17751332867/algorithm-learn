
//
// Created by wyl on 2022/3/12.
//

#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N = 1e6+10;
int a[N];
deque<PII> q;
int n,k;
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        while(!q.empty()&&a[i]<=q.back().first)q.pop_back();
        q.push_back({a[i],i});
        if(i-q.front().second>=k)q.pop_front();
        if(i>=k)cout<<q.front().first<<" ";
    }
    cout<<endl;q.clear();
    for(int i=1;i<=n;i++){
        while(!q.empty()&&a[i]>=q.back().first)q.pop_back();
        q.push_back({a[i],i});
        if(i-q.front().second>=k)q.pop_front();
        if(i>=k)cout<<q.front().first<<" ";
    }
}