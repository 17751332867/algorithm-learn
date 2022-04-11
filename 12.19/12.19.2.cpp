
//
// Created by wyl on 2021/12/19.
//

#include<bits/stdc++.h>

using namespace std;
const int N = 1e6 + 10;
int n, m;
int pre[N];
char lastArray[N];
char preArray[N];
char reGainStr[N];
int cnt[N][26];

struct SuffixArray {//后缀数组n*logn(桶排+倍增)
    char s[N];
    int rak[N], sa[N], tax[N], tp[N], height[N];

    void Qsort() {
        for (int i = 0; i <= m; i++)tax[i] = 0;
        for (int i = 1; i <= n; i++)tax[rak[i]]++;
        for (int i = 1; i <= m; i++)tax[i] += tax[i - 1];
        for (int i = n; i >= 1; i--)sa[tax[rak[tp[i]]]--] = tp[i];
    }

    void SuffixSort() {
        m = 200;
        for (int i = 1; i <= n; i++)rak[i] = s[i], tp[i] = i;
        Qsort();
        for (int w = 1, p = 0; p < n; m = p, w <<= 1) {
            p = 0;
            for (int i = 1; i <= w; i++)tp[++p] = n - w + i;
            for (int i = 1; i <= n; i++)if (sa[i] > w)tp[++p] = sa[i] - w;
            Qsort();
            swap(tp, rak);
            rak[sa[1]] = p = 1;
            for (int i = 2; i <= n; i++) {
                rak[sa[i]] = (tp[sa[i - 1]] == tp[sa[i]] && tp[sa[i - 1] + w] == tp[sa[i] + w]) ? p : ++p;
            }
        }
    }

    void LCP() {
        int k = 0;
        for (int i = 1; i <= n; i++)rak[sa[i]] = i;
        for (int i = 1; i <= n; i++) {
            if (rak[i] == 1)continue;
            if (k)k--;
            int j = sa[rak[i] - 1];
            while (i + k <= n && j + k <= n && s[i + k] == s[j + k])k++;
            height[rak[i]] = k;
        }
//        for(int i=1;i<=n;i++)
//            printf("%d ",height[i]);
//        printf("\n");
    }
} SA;

void getLastArray() {

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
//        printf("%c ",SA.s[(SA.sa[i]+n-1)%n]);
        lastArray[i] = SA.s[(SA.sa[i] + n - 1) % n];
    }
    printf("%s\n", lastArray + 1);
}

int getPre() {
    pre[0] = 1;//表示恢复后的字符串是以#开头的
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        pre[SA.s[i] - 'a' + 1]++;
        preArray[++cnt] = SA.s[SA.sa[i]];
    }
    preArray[++cnt] = SA.s[SA.sa[n]];
    for (int i = 1; i < 27; i++) {
        pre[i] += pre[i - 1];
    }
    cout << preArray + 1 << endl;
}

void getRegainStr() {
    int pos = 1;
    char temp;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            if (lastArray[i] - 'a' == j) {
                cnt[i][j] = cnt[i - 1][j] + 1;
            } else {
                cnt[i][j] = cnt[i - 1][j];
            }
        }
    }
    for (int i = n; i >= 1; i--) {
        reGainStr[i] = lastArray[pos];
        temp = lastArray[pos];
        pos = pre[temp - 'a'] + cnt[pos][temp - 'a'];
    }
    printf("%s\n", reGainStr + 1);
}

int main() {
    cin >> SA.s + 1;//sdfsfdfdsdfgdfgfgfggfgdgfgd#
    n = strlen(SA.s + 1);
    SA.SuffixSort();
    SA.s[0] = '#';
    getPre();
    getLastArray();
    getRegainStr();
    string s;
    cin >> s;
    std::reverse(s.begin(), s.end());
    int l = 1, r = s.size() + 1;
    l = lower_bound(preArray+1,preArray+n+1,s[0])-preArray;
    r = upper_bound(preArray+1,preArray+n+1,s[0])-preArray;
    for (int i = 1; i < s.size(); i++) {
        int tl = lower_bound(lastArray+l,lastArray+r,s[i])-lastArray;
        int tr = upper_bound(lastArray+l,lastArray+r,s[i])-lastArray;
        int l=tl,r= tr;
        l = cnt[s[i]][l];
        r = cnt[s[i]][r];
    }
}