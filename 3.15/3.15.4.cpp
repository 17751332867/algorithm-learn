#include<bits/stdc++.h>

using namespace std;
const int N = 200010;
int a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    queue<pair<int, int>> q;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        int st = 1, now = 1;
        while (st <= n) {
            while (st <= n && a[st] == 0) st++;
            now = st;
            while (now <= n && a[now] != 0) now++;
            q.push({st, now - 1});
            st = now + 1;
        }
        int maxn = 0, tl = n, tr = 0;
        while (!q.empty()) {
            int l = q.front().first, r = q.front().second;
            q.pop();
            int t1 = 0, t2 = 0;
            for (int i = l; i <= r; i++) {
                if (a[i] < 0) t1++;
                if (a[i] == 2 || a[i] == -2) t2++;
            }
            if (t1 % 2 == 0 && maxn < t2) maxn = t2, tl = l, tr = r;
            int t3 = 0, t4 = 0;
            int ql = l;
            while (a[ql] > 0) ql++;
            for (int i = ql + 1; i <= r; i++) { if (a[i] == 2 || a[i] == -2) t3++; }
            int qr = r;
            while (a[qr] > 0) qr--;
            for (int i = l; i < qr; i++) { if (a[i] == 2 || a[i] == -2) t4++; }
            if (t3 > maxn) maxn = t3, tl = ql + 1, tr = r;
            if (t4 > maxn) maxn = t4, tl = l, tr = qr - 1;
        }
        if (maxn == 0) cout << tl << ' ' << tr << endl;
        else cout << tl - 1 << ' ' << n - tr << endl;
    }
    return 0;
}
