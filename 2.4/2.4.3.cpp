
//
// Created by wyl on 2022/2/4.
//

#include<bits/stdc++.h>

using namespace std;
const int N = 50010;
string a[N], b[N], c[N];
int n;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        a[i] = s;
        std::sort(s.begin(), s.end());
        b[i] = s;
        std::reverse(s.begin(), s.end());
        c[i] = s;
    }
    sort(b + 1, b + n + 1);
    sort(c + 1, c + n + 1);
    for (int i = 1; i <= n; i++) {
        string s = a[i];std::sort(s.begin(), s.end());
        string s1 = s;
        cout<<lower_bound(c+1,c+n+1,s)-c<<" ";
        std::reverse(s.begin(), s.end());
        string s2 = s;
        if(!(s1==s2))
            cout<<lower_bound(b+1,b+n+1,s)-b-1<<endl;
        else{
            cout<<lower_bound(b+1,b+n+1,s)-b<<endl;
        }
    }
}