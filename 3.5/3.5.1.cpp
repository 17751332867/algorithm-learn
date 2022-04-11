
//
// Created by wyl on 2022/3/5.
//

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<ll> fac;
ll n,minn;

void dfs(ll pos, ll s, ll tot) {
    if(s>n){
        return;
    }
    if (pos == fac.size()) {
        ll t = n - s;
        ll res = tot;
        while(t){
            t-=t&-t;
            res++;
        }
        minn = min(minn,res);
        return;
    }
    dfs(pos + 1, s + fac[pos], tot + 1);
    dfs(pos + 1, s, tot);
}

int main() {
    ll num = 1;
    for (int i = 2;; i++) {
        num = num * i;
        if (num > 1e12)break;
        fac.push_back(num);
    }
    int t;
    scanf("%d", &t);
    while (t--) {
        minn = 1e6;
        scanf("%lld", &n);
        dfs(0, 0, 0);
        printf("%lld\n",minn);
    }
}