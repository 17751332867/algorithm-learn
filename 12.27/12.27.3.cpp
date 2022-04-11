
//
// Created by wyl on 2021/12/27.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n,data[N];
bool used[N];
int solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){used[i]= false;scanf("%d",&data[i]);}
    sort(data+1,data+n+1);
    int res = 0;
    int j=1;
    for(int i=1;i<=n;i++){
        if(data[i]<=n&&!used[data[i]]){used[data[i]]=true;continue;}
        while(used[j]){j++;}
        int temp = data[i];
        if(temp-j<=j)return -1;
        else{
            j++;
            res++;
        }
    }
    return res;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int res = solve();
        cout<<res<<endl;
    }
}