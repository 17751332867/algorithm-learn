
//
// Created by wyl on 2022/3/8.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
struct node{
    int idx,num,i;
}ez[N];
int n,m;
bool cmp(node n1,node n2){
    return n1.num<n2.num;
}
bool cmp1(node n1,node n2){
    return n1.idx<n2.idx;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        map<int,int> table;
        string s;
        getline(cin,s);
        getline(cin,s);
        cin>>n>>m;
        for(int i=1;i<=m;i++){
            scanf("%d%d",&ez[i].idx,&ez[i].num);ez[i].i;
            table[ez[i].idx] = i;
        }
        sort(ez+1,ez+m+1,cmp);
        vector<int> v;
        int res = 0;
        for(int i=1;i<=2*n;i++){
            v.push_back(ez[i].idx);
            res+=ez[i].num;
//            cout<<ez[i].num<<end
        }
        cout<<res<<endl;
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            cout<<table[v[i]]<<" "<<table[v[2*n-1-i]]<<endl;
        }
        cout<<endl;
    }
}