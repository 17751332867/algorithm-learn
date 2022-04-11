
//
// Created by wyl on 2022/2/4.
//

#include<bits/stdc++.h>

using namespace std;
const int N = 1010;
int n, a[N];
int ans;
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) { scanf("%d", &a[i]); }
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int t = a[j] -a[i];
            int res = upper_bound(a,a+n,a[j]+2*t)- lower_bound(a,a+n,a[j]+t);
//            cout<<res<<endl;
            ans += res;
        }
    }
    cout<<ans<<endl;
}