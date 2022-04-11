
//
// Created by wyl on 2022/1/18.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 50050;
int a[N][6];
int main(){
    int t;
    scanf("%d",&t);
    a[0][0]=a[0][1]=a[0][2]=a[0][3]=a[0][4]=a[0][5]=1e9;
    while(t--){
        int n,ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            int cnt = 0;
            for(int j=1;j<=5;j++){
                scanf("%d",&a[i][j]);
//                cout<<a[i][j]<<" "<<a[ans][j]<<endl;
                if(a[i][j]<a[ans][j])cnt++;
            }
            if(cnt>=3)ans=i;
        }
        for(int i=1;i<=n;i++){
            int cnt=0;
            for(int j=1;j<=5;j++){
                if(a[i][j]<a[ans][j])cnt++;
            }
            if(cnt>=3)ans=-1;
        }
        printf("%d\n",ans);
    }
}