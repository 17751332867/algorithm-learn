
//
// Created by wyl on 2021/12/27.
//

#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int t;
string s1, s2;

ll solve() {
    cin >> s1 >> s2;
    std::reverse(s1.begin(), s1.end());
    std::reverse(s2.begin(), s2.end());
    int p1 = 0, p2 = 0;
    stack<int> res;
    while (p1 < s1.size() && p2 < s2.size()) {
        int a = s1[p1] - '0', b = s2[p2] - '0';
        if (a > b) {
            if(s2[p2+1]!='1')return -1;
            else{
                b = b + 10;
                p2++;
            }
        }
        res.push(b-a);
        p1++;p2++;
    }
    if(p1!=s1.size()){
        return -1;
    }
    while(p2<s2.size()){
        int a = s2[p2++]-'0';
        res.push(a);
    }
    ll ans=0;
    while(res.size()){
        ans=ans*10+res.top();
        res.pop();
    }
    return ans;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        ll res = solve();
        cout<<res<<endl;
    }
}