
//
// Created by wyl on 2022/3/9.
//

#include<bits/stdc++.h>
using namespace std;
int n,res[10000];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        cin>>n;
        memset(res,0,sizeof res);
        deque<int> de;
        for(int i=0;i<n;i++){
            int a;cin>>a;
            de.push_back(a);
        }
        for(int i=n;i>=1;i--){
//            cout<<de.front()<<" "<<de.back()<<" "<<de.size()<<endl;
            if(de.back()==i){de.pop_back();continue;}
            int s=0;
            while(true){
                s++;
                if(de.front()==i){
                    de.pop_front();
                    break;
                }
                int x = de.front();de.pop_front();
//                cout<<x<<endl;
                de.push_back(x);
            }
            res[i]=s;
        }
        for(int i=1;i<=n;i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;
    }
}