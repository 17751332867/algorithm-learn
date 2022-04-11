
//
// Created by wyl on 2022/3/20.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
char str[N];
int cnt[N][127];
int main(){
        int t;
        scanf("%d",&t);
        while(t--){
            scanf("%s",str+1);
            int len = strlen(str+1);
            for(int i='a';i<='z';i++){
                cnt[len][i]=cnt[len+1][i]=0;
            }
            for(int i=len;i>=1;i--){
                for(int j='a';j<='z';j++){
                    if(str[i]==j){
                        cnt[i][j]=cnt[i+1][j]+1;
                    }else cnt[i][j]=cnt[i+1][j];
                }
            }
            int res = 0;
            for(int i=1;i<=len;i++){
                if(cnt[i][str[i]]==1){
                    res = i;break;
                }
            }
            printf("%s\n",str+res);
        }
}