
//
// Created by wyl on 2022/3/5.
//

#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
vector<PII> v;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        v.clear();
        int x,y;
        for (int i = 0; i < 3; ++i) {
            scanf("%d %d",&x,&y);
            v.push_back({y,x});
        }
        std::sort(v.begin(), v.end());
        if(v[1].first==v[2].first){
            cout<<v[2].second-v[1].second<<endl;
        }else{
            cout<<0<<endl;
        }
    }
}