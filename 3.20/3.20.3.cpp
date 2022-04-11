
//
// Created by wyl on 2022/3/20.
//

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
map<int,int> m;
int n, a[N];
ll sumn, cnt;

void dfs(ll x) {
    if(cnt>n)return;
    if(m[x]>0){
        m[x]--;return;
    }
    cnt++;
    dfs((x+1)/2);
    dfs(x/2);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        m.clear();
        sumn = 0;
        cnt = 1;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            m[a[i]]++;
            sumn += a[i];
        }
        dfs(sumn);
        if(cnt==n){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}