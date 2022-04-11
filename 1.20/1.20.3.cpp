
//
// Created by wyl on 2022/1/20.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 1e8+10;
bool used[N];
vector<int> primes;
void get_primes(int n)
{
    for(int i=2;i<=n;i++){
        if(!used[i])primes.push_back(i);
        for(int j=0;primes[j]*i<=n;j++){
            used[primes[j]*i]=true;
            if(i%primes[j]==0)break;
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    get_primes(n);
    cout<<primes.size()<<endl;
}