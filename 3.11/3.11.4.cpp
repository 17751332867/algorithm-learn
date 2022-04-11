
//
// Created by wyl on 2022/3/11.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int n,a[N],b[N];
long long res = 0;
void msort(int l,int r){
    if(l==r)return;
    int mid = (l+r)/2;
    msort(l,mid);msort(mid+1,r);
    int i=l,j=mid+1,k=l;
    while(i<=mid&&j<=r){
        if(a[i]<=a[j])b[k++]=a[i++];
        else b[k++]=a[j++],res+=(1LL)*mid-i+1;
    }
    while(i<=mid){b[k++]=a[i++];}
    while(j<=r){b[k++]=a[j++];}
    for(int i=l;i<=r;i++){
        a[i]=b[i];
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    msort(1,n);
    cout<<res<<endl;
}