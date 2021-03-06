
//
// Created by wyl on 2022/3/11.
//

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
ll mod;
ll a[100005], sum[400005], mul[400005], laz[400005];

void up(int i) { sum[i] = (sum[(i << 1)] + sum[(i << 1) | 1]) % mod; }

void pd(int i, int s, int t) {
    int l = (i << 1), r = (i << 1) | 1, mid = (s + t) >> 1;
    if (mul[i] != 1) {  // 懒标记传递，两个懒标记
        mul[l] *= mul[i];
        mul[l] %= mod;
        mul[r] *= mul[i];
        mul[r] %= mod;
        laz[l] *= mul[i];
        laz[l] %= mod;
        laz[r] *= mul[i];
        laz[r] %= mod;
        sum[l] *= mul[i];
        sum[l] %= mod;
        sum[r] *= mul[i];
        sum[r] %= mod;
        mul[i] = 1;
    }
    if (laz[i]) {  // 懒标记传递
        sum[l] += laz[i] * (mid - s + 1);
        sum[l] %= mod;
        sum[r] += laz[i] * (t - mid);
        sum[r] %= mod;
        laz[l] += laz[i];
        laz[l] %= mod;
        laz[r] += laz[i];
        laz[r] %= mod;
        laz[i] = 0;
    }
    return;
}

void build(int s, int t, int i) {
    mul[i] = 1;
    if (s == t) {
        sum[i] = a[s];
        return;
    }
    int mid = s + ((t - s) >> 1);
    build(s, mid, i << 1);  // 建树
    build(mid + 1, t, (i << 1) | 1);
    up(i);
}

void chen(int l, int r, int s, int t, int i, ll z) { //区间乘
    int mid = s + ((t - s) >> 1);
    if (l <= s && t <= r) {
        mul[i] *= z;
        mul[i] %= mod;  // 这是取模的
        laz[i] *= z;
        laz[i] %= mod;  // 这是取模的
        sum[i] *= z;
        sum[i] %= mod;  // 这是取模的
        return;
    }
    pd(i, s, t);
    if (mid >= l) chen(l, r, s, mid, (i << 1), z);
    if (mid + 1 <= r) chen(l, r, mid + 1, t, (i << 1) | 1, z);
    up(i);
}

void add(int l, int r, int s, int t, int i, ll z) { //区间加
    int mid = s + ((t - s) >> 1);
    if (l <= s && t <= r) {
        sum[i] += z * (t - s + 1);
        sum[i] %= mod;  // 这是取模的
        laz[i] += z;
        laz[i] %= mod;  // 这是取模的
        return;
    }
    pd(i, s, t);
    if (mid >= l) add(l, r, s, mid, (i << 1), z);
    if (mid + 1 <= r) add(l, r, mid + 1, t, (i << 1) | 1, z);
    up(i);
}

ll getans(int l, int r, int s, int t,int i) {  // 区间求和
    int mid = s + ((t - s) >> 1);
    ll tot = 0;
    if (l <= s && t <= r) return sum[i];
    pd(i, s, t);
    if (mid >= l) tot += getans(l, r, s, mid, (i << 1));
    tot %= mod;
    if (mid + 1 <= r) tot += getans(l, r, mid + 1, t, (i << 1) | 1);
    return tot % mod;
}

int main(){
    scanf("%d%d%lld",&n,&m,&mod);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    build(1,n,1);
    for(int i=1;i<=m;i++){
        int pos;
        scanf("%d",&pos);
        if(pos==1){
            int x,y,k;
            scanf("%d%d%d",&x,&y,&k);
            chen(x,y,1,n,1,k);
        }else if(pos==2){
            int x,y,k;
            scanf("%d%d%d",&x,&y,&k);
            add(x,y,1,n,1,k);
        }else{
            int x,y;
            scanf("%d%d",&x,&y);
            printf("%lld\n", getans(x,y,1,n,1));
        }
    }
}