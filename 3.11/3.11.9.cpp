
//
// Created by wyl on 2022/3/11.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
vector<int> primes,res;
bool used[N];
int n;
void get_primes(int n){
    used[1]=true;
    for(int i=2;i<=n;i++){
        if(!used[n])primes.push_back(i);
        for(int j=0;primes[j]*i<=n;j++){
            used[primes[j]*i]=true;
            if(i%primes[j]==0)break;
        }
    }
}
int main(){
    get_primes(1e6);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int t;
        scanf("%d",&t);
        if(used[t]== false){
            res.push_back(t);
        }
    }
    for(int i=0;i<res.size();i++){
        printf("%d ",res[i]);
    }
}