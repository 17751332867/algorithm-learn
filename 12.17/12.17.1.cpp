
//
// Created by wyl on 2021/12/17.
//

#include<bits/stdc++.h>
using namespace std;
vector<int> a;
int n;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int opt,v;
        scanf("%d%d",&opt,&v);
        if(opt==1){a.insert(upper_bound(a.begin(),a.end(),v),v);}
        if(opt==2){a.erase(lower_bound(a.begin(),a.end(),v));}
        if(opt==3){printf("%d\n", lower_bound(a.begin(),a.end(),v)- a.begin()+1); }
        if(opt==4){ printf("%d\n",a[v-1]);}
        if(opt==5){ printf("%d\n", *--lower_bound(a.begin(),a.end(),v));}
        if(opt==6){ printf("%d\n", *upper_bound(a.begin(),a.end(),v));}
    }
}