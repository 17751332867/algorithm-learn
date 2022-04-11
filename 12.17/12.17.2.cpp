
//
// Created by wyl on 2021/12/17.
//

#include<bits/stdc++.h>
using namespace std;
vector<int> a;
int n;
void insert(int x){
    a.insert(upper_bound(a.begin(),a.end(),x),x);
}
int get(int x){
    int p = lower_bound(a.begin(),a.end(),x)-a.begin();
//    cout<<p<<endl;
    int r = a[p],l=a[max(0,p-1)];
    return min(abs(r-x),abs(x-l));
}

int main(){
    scanf("%d",&n);
    int res;scanf("%d",&res);
    a.push_back(res);
    for(int i=2;i<=n;i++){
        int x;scanf("%d",&x);
        res+=get(x);
//        cout<<res<<endl;
        insert(x);
    }
    printf("%d",res);
}