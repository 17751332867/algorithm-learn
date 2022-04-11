
//
// Created by wyl on 2022/2/4.
//

#include<bits/stdc++.h>

using namespace std;
const int N = 1010;
int t, n;
char a[N];

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        scanf("%s", a);
        int x = 0, y = 0;
        double res = 0;
        for (int i = 0; i < n; i++) {
            if(a[i]=='L')x--;
            if(a[i]=='R')x++;
            if(a[i]=='U')y++;
            if(a[i]=='D')y--;
            res = max(res,sqrt(x*x+y*y));
        }
        cout<<fixed<<setprecision(12)<<res<<endl;
    }
}