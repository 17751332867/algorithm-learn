
//
// Created by wyl on 2022/1/20.
//

#include<bits/stdc++.h>

using namespace std;
//#define int long long
const int N = 2e6 + 10;
int a, b;
vector<int> primes;
bool used[N];

void get_primes() {
    used[1] = true;
    for (int i = 2; i <= 1e6+10; i++) {
        if (!used[i])primes.push_back(i);
        for (int j = 0; primes[j] * i <= 1e6+10; j++) {
            used[primes[j] * i] = true;
            if (i % primes[j] == 0)break;
        }
    }
}

void special_judge() {
    int res = 0;
    for (int i = 1; i <= b; i++) {
        if (used[i] == false)res++;
    }
    cout << res << endl;
}

signed main() {
    cin >> a >> b;
    get_primes();
    if (a == 1) {
        special_judge();
        return 0;
    }
//    for(int i=0;i<primes.size();i++){
//        cout<<primes[i]<<endl;
//    }
    memset(used, false, sizeof used);
    for (int i = 0; primes[i] * primes[i] <= b; i++) {
        int p = primes[i];
//        cout<<primes[i]<<endl;
        for (int j = max(2 * p, (int)(ceil(a / p) * p)); j <= b; j += p) {
//            cout<<j<<endl;
            used[j - a] = true;
        }
    }
    int res = 0;
    for (int i = 0; i <= b - a; i++) {
        if(used[i]== false) res++;
    }
    cout<<res<<endl;
}