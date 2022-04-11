
//
// Created by wyl on 2022/3/12.
//

#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N = 2e6+10;
deque<PII> p;
int a[N];
int n,k;
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        while (!p.empty()&&a[i]>=p.back().first)p.pop_back();
        p.push_back({a[i],i});
        if(i-p.front().second>=k){p.pop_front();}
        if(i>=k)cout<<p.front().first<<"\n";
    }
}