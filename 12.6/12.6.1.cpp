
//
// Created by wyl on 2021/12/6.
//

#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,h,p;
signed main(){
    cin.sync_with_stdio(false);
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>h>>p;
        int times = 0;
        int sumn = pow(2,h)-1;
        for(int i=0;i<h;i++){
            int x = pow(2,i);
            if(p>=x){
                sumn-=x;
                times++;
            }else break;
        }
        times+= sumn/p;
        if(sumn%p!=0)times++;
        cout<<times<<endl;
    }
}