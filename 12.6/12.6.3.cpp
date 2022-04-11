
//
// Created by wyl on 2021/12/6.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int t,n,m;
bool data[N];
int main(){
    cin.sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){data[i]=0;}
        for(int i=0;i<m;i++){
            int a,b,c;cin>>a>>b>>c;
            data[b]=1;
        }
        int root = 0;
        for(int i=1;i<=n;i++){
            if(data[i]==0){
                root = i;break;
            }
        }
        for(int i=1;i<=n;i++){
            if(i!=root){
                cout<<root<<" "<<i<<endl;
            }
        }
    }
}