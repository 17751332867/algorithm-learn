
//
// Created by wyl on 2022/1/10.
//

#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    scanf("%d",&n);
    int ln=2e9,lmin=0,rn=-2e9,rmin=0,minn;
    for(int i=1;i<=n;i++){
        int l,r,c;cin>>l>>r>>c;
        if(l<ln){ln=l;lmin=c;minn=2e9;}
        else if(l==ln){lmin=min(c,lmin);}
        if(r>rn){rn=r;rmin=c;minn=2e9;}
        else if(r==rn){rmin=min(c,rmin);}
        if(l==ln&&r==rn){minn=min(minn,c);}
        printf("%d\n",min(lmin+rmin,minn));
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}