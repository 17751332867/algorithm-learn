
//
// Created by wyl on 2022/1/21.
//

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10;
int l, r, cnt;
int primes[N];
vector<int> res;
bool used[N];

void get_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!used[i])primes[cnt++] = i;
        for (int j = 0; primes[j] * i <= n; j++) {
            used[primes[j] * i] = true;
            if (i % primes[j] == 0)break;
        }
    }
}

signed main() {
    memset(used, 0, sizeof used);
    get_primes(1e6);
    while (cin >> l >> r) {
        cnt = 0;
        res.clear();
        memset(used, 0, sizeof used);
        for (int i = 0; primes[i] * primes[i] <= r; i++) {
            int p = primes[i];
//            cout<<p<<endl;
            for (int j = max(2 * p, (l+p-1)/p*p); j <= r; j += p) {
//                cout<< (l+p-1)/p*p<<" "<<j<<endl;
                used[j - l] = true;
            }
        }
        if(l==1){used[0]= true;}
        for (int i = 0; i <= r - l; i++) {
            if (used[i] == false)res.push_back(l + i);
        }
//        cout<<res.size()<<endl;
        if(res.size()<2){
            printf("There are no adjacent primes.\n");
        }else{
            int maxn = 0, minn = 0x3f3f3f3f;
            int minl,minr,maxl,maxr;
            for(int i=0,j=1;j<res.size();j++,i++){
                if(res[j]-res[i]>maxn){
                    maxl = res[i], maxr = res[j];
                    maxn = res[j] - res[i];
                }
                if(res[j]-res[i]<minn){
                    minl = res[i],minr = res[j];
                    minn = res[j] - res[i];
                }
            }
            printf("%d,%d are closest, %d,%d are most distant.\n",minl,minr,maxl,maxr);
        }
    }

}