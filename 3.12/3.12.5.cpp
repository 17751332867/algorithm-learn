
//
// Created by wyl on 2022/3/12.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 5e4+10;
int n,k,a[N];
deque<int> q;
int b[N],c[N];
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        q.push_back(a[i]);
        while(q.back()-q.front()>k){
            q.pop_front();
        }
        b[i]=max(b[i-1],(int)q.size());
    }
    q.clear();
    for(int i=n;i>=1;i--){
        q.push_back(a[i]);
        while(q.front()-q.back()>k){
            q.pop_front();
        }
        c[i]=max(c[i+1],(int)q.size());
    }
    int res = 0;
    for(int i=1;i<=n;i++){
        res=max(b[i]+c[i+1],res);
    }
    cout<<res<<endl;
}