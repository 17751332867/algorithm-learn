
//
// Created by wyl on 2022/1/18.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 110;
int path[N]={1};
int n,k;
bool dfs(int u,int depth){
    if(u==depth){
        return path[u-1]==n;
    }
    bool used[N]={0};
    for(int i=u-1;i>=0;i--){
        for(int j=i;j>=0;j--){
            int s = path[i]+path[j];
            if(s<=path[u-1]||s>n||used[s]){
                continue;
            }
            used[s]=true;
            path[u]=s;
            if(dfs(u+1,depth))return true;
        }
    }
    return false;
}
//bool dfs(int u, int k)  // u表示当前层数, k表示最大的层数
//{
//    if (u == k) {
//        return path[u - 1] == n;
//    }
//
//    bool st[N] = {0}; // 通过 bool数组排除等效冗余
//
//    for (int i = u - 1; i >= 0; i--) {
//        for (int j = i; j >= 0; j--) {
//            int s = path[i] + path[j];
//            if (s > n || s <= path[u - 1] || st[s]) { // path一定是递增的
//                continue;
//            }
//
//            st[s]   = true;
//            path[u] = s;
//
//            if (dfs(u + 1, k)) {
//                return true;
//            }
//        }
//    }
//    return false;
//}

int main(){
    while(cin>>n&&n){
        k = 1;
        while(!dfs(1,k))k++;
        for(int j=0;j<k;j++){
            cout<<path[j]<<" ";
        }
        cout<<endl;
    }
}