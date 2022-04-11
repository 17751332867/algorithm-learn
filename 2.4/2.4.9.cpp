
//
// Created by wyl on 2022/2/4.
//

#include<bits/stdc++.h>

using namespace std;
const int N = 2e5 + 10;
int t, n, A, B, a[N], b[N], res = 0;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &A, &B, &n);
        res = 0;
        for (int i = 1; i <= A; i++) { scanf("%d", &a[i]); }
        for (int i = 1; i <= B; i++) { scanf("%d", &b[i]); }
        if ((n + 1) / 2 > A || A + B < n) {
            printf("-1\n");
            continue;
        }
        sort(a + 1, a + A + 1, greater<int>());
        sort(b + 1, b + B + 1, greater<int>());

        for (int i = 1; i <= (n + 1) / 2; i++) {
            res += a[i];
        }
        int l = (n + 1) / 2 + 1, r = 1, sumn = (n + 1) / 2 + 1;
        while (sumn <= n) {
            if (a[l] >= b[r] && l <= A || r == B + 1)res += a[l], l++;
            else res += b[r], r++;
            sumn++;
        }
        printf("%d\n", res);
    }
}