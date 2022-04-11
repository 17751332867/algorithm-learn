
//
// Created by wyl on 2022/3/9.
//

#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> PII;
const int N = 155;
double d[N][N], d1[N], d2[N];
char m[N][N];
PII p[N];
set<int> s;
vector<int> v1, v2;
int n, par[N];

double dist(PII p1, PII p2) {
    double x = p1.first - p2.first;
    double y = p1.second - p2.second;
    return sqrt(x * x + y * y);
}

int find(int x) {
    if (x == par[x])return x;
    else par[x] = find(par[x]);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)par[i] = i;
    for (int i = 1; i <= n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        p[i] = {x, y};
    }
    for (int i = 1; i <= n; i++) {
        scanf("%s", m[i] + 1);
        for (int j = 1; j <= n; j++) {
            if (m[i][j] == '1') {
                d[i][j] = dist(p[i], p[j]);
                int x = find(i);
                int y = find(j);
                par[x] = y;
            } else {
                d[i][j] = 0x3f3f3f3f;
            }
        }
        d[i][i] = 0;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    int temp = find(1);
    for (int i = 1; i <= n; i++) {
        s.insert(find(i));
        if (find(i) == temp) { v1.push_back(i); }
        else { v2.push_back(i); }
    }
    if (s.size() == n) {
        double res = 0x3f3f3f3f;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if(i!=j)
                res=min(res,dist(p[i],p[j]));
            }
        }
        printf("%.6lf",res);return 0;
    }
    double res1 = 0, res2 = 0, res3 = 0x3f3f3f3f;
    for (int i = 0; i < v1.size(); i++) {
        int x = v1[i];
        for (int j = 0; j < v1.size(); j++) {
            int y = v1[j];
            if (d[x][y] != 0x3f3f3f3f) {
                d1[x] = max(d1[x], d[x][y]);
            }
        }
        res1 = max(d1[x], res1);
    }
    for (int i = 0; i < v2.size(); i++) {
        int x = v2[i];
        for (int j = 0; j < v2.size(); j++) {
            int y = v2[j];
            if (d[x][y] != 0x3f3f3f3f) {
                d2[x] = max(d2[x], d[x][y]);
            }
        }
        res2 = max(d2[x], res2);
    }
    for (int i = 0; i < v1.size(); i++) {
        for (int j = 0; j < v2.size(); j++) {
            int x = v1[i], y = v2[j];
            res3 = min(d1[x] + d2[y] + dist(p[x], p[y]), res3);
        }
    }
    printf("%.6lf", max(max(res1, res2), res3));
}