
//
// Created by wyl on 2022/3/13.
//
//#pragma GCC optimize(1)
//#pragma GCC optimize(2)
//#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>

using namespace std;
const int MAXN = 2000000;  // 双倍字符串长度
const int CHAR_NUM = 5;   // 字符集个数，注意修改下方的 (-'a')
const int REPEATS_SIZE = 8;
vector<pair<int, int> > res;
int table[256];

void init() {
    table['A'] = 0;
    table['C'] = 1;
    table['G'] = 2;
    table['T'] = 3;
}

int trans(char c) {
    return table[c];
}

struct exSAM {
    int len[MAXN];             // 节点长度
    int link[MAXN];            // 后缀链接，link
    int next[MAXN][CHAR_NUM];  // 转移
    int node_id[MAXN];         // 每个转移对应的节点编号
    int id[MAXN];              // 每个状态对应的广搜顺序第一个节点编号
    int first_pos[MAXN];        // 第一次出现的位置
    int tot;                   // 节点总数：[0, tot)
    void init() {  // 初始化函数
        tot = 1;
        link[0] = -1;
    }

    int insertSAM(int last, int c, int idx) {  // last 为父 c 为子
        int cur = next[last][c];
        if (len[cur]) return cur;
        len[cur] = len[last] + 1;
        first_pos[cur] = len[cur] - 1;
        id[cur] = idx;
        int p = link[last];
        while (p != -1) {
            if (!next[p][c])
                next[p][c] = cur;
            else
                break;
            p = link[p];
        }
        if (p == -1) {
            link[cur] = 0;
            return cur;
        }
        int q = next[p][c];
        if (len[p] + 1 == len[q]) {
            link[cur] = q;
            return cur;
        }
        int clone = tot++;
        for (int i = 0; i < CHAR_NUM; ++i)
            next[clone][i] = len[next[q][i]] != 0 ? next[q][i] : 0;
        len[clone] = len[p] + 1;
        while (p != -1 && next[p][c] == q) {
            next[p][c] = clone;
            p = link[p];
        }
        link[clone] = link[q];
        link[cur] = clone;
        link[q] = clone;
        first_pos[clone] = first_pos[q];
        id[clone] = id[q];
        return cur;
    }

    int insertTrie(int cur, int c, int idx) {
        if (next[cur][c]) return next[cur][c];  // 已有该节点 直接返回
        node_id[tot] = idx;
        return next[cur][c] = tot++;  // 无该节点 建立节点
    }

    void insert(const string &s, int idx) {
        int root = 0;
        for (auto ch: s) root = insertTrie(root, trans(ch), idx);
    }

    void insert(const char *s, int n, int idx) {
        int root = 0;
        for (int i = 0; i < n; ++i)
            root =
                    insertTrie(root, trans(s[i]), idx);  // 一边插入一边更改所插入新节点的父节点
    }

    void build() {
        queue<pair<int, int>> q;
        for (int i = 0; i < 4; ++i)
            if (next[0][i]) { q.push({i, 0}); }
        while (!q.empty()) {  // 广搜遍历
            auto item = q.front();
            q.pop();
            int idx = node_id[next[item.second][item.first]];
            auto last = insertSAM(item.second, item.first, idx);
            for (int i = 0; i < 4; ++i)
                if (next[last][i]) q.push({i, last});
        }
    }
} exSam;

char s[MAXN];
int v[MAXN], path[MAXN],w[MAXN],first[MAXN];
int cnt_v=0,cnt_path=0,cnt_w=0,cnt_first=0;

int main() {
    init();
    ios::sync_with_stdio(false);
    int n;
    ifstream in;
    clock_t begin, end;
    in.open("D:\\workspace\\clion-workspace\\algorithm-learn\\suffix_auto_machine\\graph.gfa");
    begin = clock();
    exSam.init();
    while (true) {
        string s;
        getline(in, s);
        if (s[0] != 'S')break;
        stringstream ss(s);
        string t;
        int num;
        ss >> t >> num >> t;
        exSam.insert(t, num);
    }
    exSam.build();
    in.close();
    FILE* instream =  fopen("D:\\workspace\\clion-workspace\\algorithm-learn\\suffix_auto_machine\\read200.fa","r");
    FILE* outstream = fopen("D:\\workspace\\clion-workspace\\algorithm-learn\\suffix_auto_machine\\path200.txt","w");
    while (fscanf(instream,"%s",s)!=EOF) {
        fscanf(instream,"%s",s);
        int len = strlen(s);
        int u = 0;
        cnt_v=0,cnt_path=0,cnt_w=0,cnt_first=0;
        for (int i = 0; i < len; i++) {
            u = exSam.next[u][trans(s[i])];
            v[cnt_v++]=(exSam.id[u]);
            w[cnt_w++]=(exSam.first_pos[u] - len + 1);
        }

        int cnt = 1;
        for (int i = 0, j = 1; j < cnt_v; i++, j++) {
            if (v[i] == v[j]) { cnt++; }
            else {
                if (cnt >= REPEATS_SIZE) {
                    path[cnt_path++]=v[i];
                    first[cnt_first++]=w[i];
                }
                cnt = 1;
            }
        }
        if(cnt>=REPEATS_SIZE){
            path[cnt_path++]=(v[cnt_v-1]);
            first[cnt_first++]=(w[cnt_w-1]);
        }
        fprintf(outstream,"%d %d ",(cnt_path>=1?path[0]:exSam.id[u]),(cnt_first>=1?first[0]:exSam.first_pos[u] - len + 1));
        for(int i=0;i<cnt_path;i++){
            fprintf(outstream,"<%d",path[i]);
        }
        fprintf(outstream,"\n");
    }
    end = clock();
    cout << end - begin << endl;
    return 0;
}
