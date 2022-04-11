
//
// Created by wyl on 2021/12/19.
//

#include<bits/stdc++.h>

using namespace std;
const int N = 1e6 + 10;

int n,m;
struct SuffixArray{
    char s[N];
    int  rak[N], sa[N], tax[N], tp[N],height[N];

    void Qsort() {
        for (int i = 0; i <= m; i++)tax[i] = 0;
        for (int i = 1; i <= n; i++)tax[rak[i]]++;
        for (int i = 1; i <= m; i++)tax[i] += tax[i - 1];
        for (int i = n; i >= 1; i--)sa[tax[rak[tp[i]]]--] = tp[i];
    }

    void SuffixSort() {
        m = 75;
        for (int i = 1; i <= n; i++)rak[i] = s[i] - '0' + 1, tp[i] = i;
        Qsort();
        for (int w = 1, p = 0; p < n; m = p, w <<= 1) {
            p = 0;
            for (int i = 1; i <= w; i++)tp[++p] = n - w + i;
            for (int i = 1; i <= n; i++)if(sa[i]>w)tp[++p]=sa[i]-w;
            Qsort();
            swap(tp,rak);
            rak[sa[1]] = p = 1;
            for(int i = 2; i<= n; i++){
                rak[sa[i]]=(tp[sa[i-1]]==tp[sa[i]]&&tp[sa[i-1]+w]==tp[sa[i]+w])?p:++p;
            }
        }
        for(int i=1;i<=n;i++){
            printf("%d ",sa[i]);
        }
    }
    void LCP()
    {
        int k=0;
        for(int i=1;i<=n;i++)rak[sa[i]]=i;
        for(int i=1;i<=n;i++)
        {
            if(rak[i]==1)continue;
            if(k)k--;
            int j=sa[rak[i]-1];
            while(i+k<=n&&j+k<=n&&s[i+k]==s[j+k])k++;
            height[rak[i]]=k;
        }
        for(int i=1;i<=n;i++)
            printf("%d ",height[i]);
        printf("\n");
    }
}SA;
int main() {
    scanf("%s",SA.s+1);
    n = strlen(SA.s+1);
    SA.SuffixSort();
    return 0;
}