
//
// Created by wyl on 2021/12/5.
//

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 2e5+10;
ll n,m;ll sumn,data[N];
int main(){
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&data[i]);sumn+=data[i];
    }
    sort(data+1,data+n+1);
    cin>>m;
    for(ll i=0;i<m;i++){
        ll def,atk;
        scanf("%lld%lld",&def,&atk);
        ll res = 0;
        ll pos = lower_bound(data+1,data+n+1,def)-data;
        if(pos==n+1){
            res += def-data[n];
            if(atk>(sumn-data[n])){
                res +=atk-(sumn-data[n]);
            }
        }
        else if(pos==1){
            if(atk>(sumn-data[1])){
                res +=atk-(sumn-data[1]);
            }

        }else{
            ll temp1 = 0;
            if(atk>(sumn-data[pos])){
                temp1 +=atk-(sumn-data[pos]);
            }
            ll temp2 = def-data[pos-1];
            if(atk>(sumn-data[pos-1])){
                temp2 +=atk-(sumn-data[pos-1]);
            }
//            cout<<"temp1 "<<temp1<<"temp2 "<<temp2<<endl;
            res = min(temp1,temp2);

        }
        printf("%lld\n",res);
    }

}