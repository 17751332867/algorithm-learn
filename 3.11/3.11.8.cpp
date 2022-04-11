
//
// Created by wyl on 2022/3/11.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
vector<int> primes;
bool used[N+10];
void get_primes(int n){
    used[1]=true;
    for(int i=2;i<=n;i++){
        if(!used[i])primes.push_back(i);
        for(int j=0;primes[j]*i<=n;j++){
            used[primes[j]*i]=true;
            if(i%primes[j]==0)break;
        }
    }
}
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    get_primes(n);
    for(int i=0;i<q;i++){
        int t;
        scanf("%d",&t);
        printf("%d\n",primes[t-1]);
    }
}