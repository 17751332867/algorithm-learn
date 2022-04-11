
//
// Created by wyl on 2022/2/4.
//

#include<bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;
map<int, int> s;
int a[N], n;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if(a[i]>a[i-1]){
            s[a[i-1]]++,s[a[i]]--;
        }
    }
    int res = 0, sumn = 0;
    for(auto t:s){
        sumn+=t.second;
        res = max(sumn,res);
    }
    printf("%d",res);
}