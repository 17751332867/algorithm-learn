
//
// Created by wyl on 2022/1/21.
//

#include<bits/stdc++.h>

using namespace std;
const int N = 1e6 + 10;
int n;
vector<int> primes;
bool used[N];
int cnt[N];

void get_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!used[i])primes.push_back(i);
        for (int j = 0; primes[j] * i <= n; j++) {
            used[primes[j] * i] = true;
            if (i % primes[j] == 0)break;
        }
    }
}

void solve(int n) {
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            cnt[i]++;
            n /= i;
        }
    }
    cnt[n]++;
}

int main() {
    int n;
    cin >> n;
    get_primes(n);
    for(int i=2;i<=n;i++){
        solve(i);
    }
    for(int i=2;i<=n;i++){
        if(cnt[i]!=0){
            printf("%d %d\n",i,cnt[i]);
        }
    }
}