
//
// Created by wyl on 2022/2/4.
//

#include<bits/stdc++.h>

using namespace std;
const int N = 1e6 + 10;
int n, a[N], s[N];
long long sumn;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++) {
        int t = 1000 - a[i];
        int j = lower_bound(a + i, a + n + 1, t) - a;
        sumn += (1000 - a[i]) * (j - i) - s[j - 1] + s[i - 1];
        sumn += a[i] * (n - j + 1) + s[n] - s[j - 1] - 1000 * (n - j + 1);
//        cout<<s[j-1]<<" "<<(1000 - a[i]) * (j - i) - s[j - 1]<<" "<<a[i] * (n - j + 1) + s[n] - s[j - 1] - 1000 * (n - j + 1)<<" "<<j<<endl;
    }
    printf("%lld\n",sumn);
}