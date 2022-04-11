
//
// Created by wyl on 2022/1/9.
//

#include<bits/stdc++.h>

using namespace std;
const int N = 15;
vector<int> g[N];
int n;
int a[N];
int res = N;

int gcd(int a, int b) {
    if (b) { return gcd(b, a % b); }
    else { return a; }
}

bool check(vector<int> g, int v) {
    for (int i = 0; i < g.size(); i++) {
        if (gcd(g[i], v) != 1) {
            return false;
        }
    }
    return true;
}

void dfs(int u, int used) {
    if (u == n) {
        res = min(res, used);
        return;
    }
    for (int i = 0; i < used; i++) {
        if(check(g[i],a[u])){
            g[i].push_back(a[u]);
            dfs(u+1,used);
            g[i].pop_back();
        }
    }
    g[used].push_back(a[u]);
    dfs(u+1,used+1);
    g[used].pop_back();
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)scanf("%d", &a[i]);
    dfs(0,0);
    printf("%d\n",res);
}