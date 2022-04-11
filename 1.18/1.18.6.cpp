
//
// Created by wyl on 2022/1/18.
//

#include<bits/stdc++.h>

using namespace std;
const int N = 2e5 + 10;
string ss[N];
char c;
int n;

bool cmp(string s1, string s2) {
    int c1 = count(s1.begin(), s1.end(), c);
    int c2 = count(s2.begin(), s2.end(), c);
    int oc1 = s1.size()-c1;
    int oc2 = s2.size()-c2;
    return c1-oc1>c2-oc2;
}

int main() {
    int t;
    cin.sync_with_stdio(false);
    cin >> t;
    while (t--) {
        int res = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> ss[i];
        }
        for (char i = 'a'; i <= 'e'; i++) {
            c = i;
            sort(ss + 1, ss + n + 1, cmp);
            int t1 = 0, t2 = 0;
            for (int j = 1; j <= n; j++) {
//                cout<<ss[j]<<endl;
                int cnt = std::count(ss[j].begin(), ss[j].end(), c);
                t1 += cnt;
                t2 += ss[j].size() - cnt;
//                cout << cnt << " " << t1 << " " << t2 << endl;
                if (t1 > t2) {
                    res = max(res, j);
                } else {
                    break;
                }
            }
        }
        printf("%d\n", res);
    }
}