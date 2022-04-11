
//
// Created by wyl on 2022/3/5.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 5e3+10;
int s[N][N],m[N],a[N],b[N];
int n,k;
int main(){
       int t;
       scanf("%d",&t);
       while(t--){
           scanf("%d %d",&n,&k);
           for(int i=0;i<=n;i++){m[i]=INT_MIN;}
           for(int i=1;i<=n;i++){ scanf("%d",&a[i]);b[i]=b[i-1]+a[i];}
           for(int len=1;len<=n;len++){
               for(int r=len,l=r-len;r<=n;l++,r++){
                   s[l][r]=b[r]-b[l];
                   m[len]=max(s[l][r],m[len]);
               }
           }
           for(int i=0;i<=n;i++){
               int res = INT_MIN;
               for(int j=1;j<=n;j++){
//                   cout<<m[j]<<endl;
                   int t = m[j]+min(i,j)*k;
                   res = max(t,res);
               }
               res = max(0,res);
               printf("%d ",res);
           }
           printf("\n");
       }
}