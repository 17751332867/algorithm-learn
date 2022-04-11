
//
// Created by wyl on 2022/2/2.
//

#include<bits/stdc++.h>

using namespace std;
int a[100], b[100];
int lena, lenb;

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) { a[i] = s[i] - '0';}
    lena = s.size();
    cin >> s;
    for (int i = 0; i < s.size(); i++) { b[i] = s[i] - '0';}
    lenb = s.size();

    for (int i = 0; i < lena; i++) {
        for (int j = 0; j < lenb; j++) {
            if (a[i] == 0)a[i] = 1;
            else a[i] = 0;
            int t = b[j];
            for (int k = 0; k <= 2; k++) {
                if (k != t) {
                    b[j] = k;
                    int na = 0, nb = 0;
                    for (int x = 0; x < lena; x++) {
                        na += a[x] * 1 << (lena - 1 - x);
//                        cout<<a[x];
                    }
//                    cout<<endl;
                    for (int x = 0; x < lena; x++) {
                        nb += b[x] * pow(3, lenb - 1 - x);
//                        cout<<b[x];
                    }
//                    cout<<endl;
                    if(na==nb)cout<<na<<endl;
                }
            }
            b[j] = t;
            if (a[i] == 0)a[i] = 1;
            else a[i] = 0;
        }
    }
}