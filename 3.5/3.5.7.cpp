
//
// Created by wyl on 2022/3/5.
//

#include<bits/stdc++.h>
using namespace std;
int n,a;
set<int> m;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        m.clear();
        for(int i=1;i<=n;i++){
            scanf("%d",&a);
            m.insert(a);
        }
        int tot = m.size();
        for(int i=1;i<=n;i++){
            if(i<=m.size()){
                printf("%d ",m.size());
            }else{
                printf("%d ",++tot);
            }
        }
        printf("\n");
    }
}