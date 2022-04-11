
//
// Created by wyl on 2022/1/19.
//

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e7+10;
int tot = 1,last = 1;
struct Node{
    int len,fa;
    int ch[4];
}node[N];
LL f[N],ans;
char str[N];
int n,m;
void extend(int c){
    int p = last,np = last = ++tot;
    f[tot] = 1;
    node[np].len = node[p].len + 1;
    for(;p&&!node[p].ch[c];p=node[p].fa)node[p].ch[c] = np;
    if(!p)node[np].fa=1;
    else{
        int q = node[p].ch[c];
        if(node[q].len==node[p].len+1)node[np].fa=q;
        else{
            int nq = ++tot;
            node[nq] = node[q],node[nq].len = node[p].len+1;
            node[q].fa = node[np].fa = nq;
            for(;p&&node[p].ch[c]==q;p=node[p].fa)node[p].ch[c] = nq;
        }
    }
}
int get_c(char c){
    if(c=='N')return 1;
    if(c=='W')return 2;
    if(c=='S')return 3;
    return 0;
}
int main(){
    scanf("%d%d",&n,&m);
    scanf("%s",str);
    for(int i=0;str[i];i++)extend(get_c(str[i]));
    while(m--){
        scanf("%s",str);
        int p = 1,res=0;
        for(int i=0;str[i];i++){
            int c = get_c(str[i]);
            if(node[p].ch[c])p=node[p].ch[c],res++;
            else break;
        }
        printf("%d\n",res);
    }
    return 0;
}