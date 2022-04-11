
//
// Created by wyl on 2022/3/5.
//

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
int n,a[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        sort(a+1,a+n+1);
        ll l=a[1],r=0;
        bool flag = false;
        for(int i=2,j=n;i<j;i++,j--){
            l+=a[i];r+=a[j];
            if(r>l){flag=true;}
//            cout<<l<<" "<<r<<endl;
        }
        if(flag){printf("YES\n");}
        else{ printf("NO\n");}

    }
}