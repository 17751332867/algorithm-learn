
//
// Created by wyl on 2022/1/21.
//

#include<bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;
int n, cnt = 0;
vector<int> primes;
bool used[N];

void get_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!used[i])primes.push_back(i);
        for (int j = 0; primes[j] * i <= n; j++) {
            used[primes[j] * i] = true;
            if (i % primes[j]==0)break;
        }
    }
}

int main() {
    cin >> n;
    get_primes(1e5+10);
    if(n<=2){ printf("1\n");}
    else{ printf("2\n");}
    for(int i=2;i<=n+1;i++){
        if(used[i]== false){
            printf("2 ");
        }else{
            printf("1 ");
        }
    }
    printf("\n");
}