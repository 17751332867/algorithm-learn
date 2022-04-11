
//
// Created by wyl on 2022/3/6.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int n,c;
int a[N],x[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;cin>>n>>c;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        sort(a+1,a+n+1);
        if(a[1]!=1){
            cout<<"NO"<<endl;continue;
        }else{
            for(int i=1;i<=n;i++){
                x[a[i]]=true;
            }
            int cnt = 0;
            for(int i=1;i<=c;i++){
                if(x[i]==true){
                    a[++cnt]=i;
                }
            }
            bool flag = true;
            for(int i=1;i<=cnt;i++){
                int begin = *lower_bound(a+1,a+cnt+1,a[i]+1);
                for(int j=begin;j<=c;j+=a[i]){
                    int k = lower_bound(a+1,a+cnt+1,j)-a;
                    if(k==cnt)continue;
                    else{
                        int tar = j/a[i];
                        int f = *lower_bound(a+1,a+cnt+1,tar);
                        if(tar>a[cnt])continue;
                        if(f!=tar){
                            flag = false;
                        }
                    }
                }
            }
            if(flag){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
    }
}