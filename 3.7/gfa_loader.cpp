#include <bits/stdc++.h>
using namespace std;

class Segment {
public:
    string seq;
    vector <int> link;

    Segment(string seq = ""): seq(seq) {}
};

class SeqGraph {
public:
    map <int, Segment> nodes;

    void build(string gaffile) {
        ifstream ifs(gaffile);
        string t;
        while(ifs >> t) {
            if(t == "S") {
                int id;
                string seq;
                ifs >> id >> seq;
                nodes[id] = Segment(seq);
            } else if(t == "L") {
                int l, r;
                string lo, ro, over;
                ifs >> l >> lo >> r >> ro >> over;
                nodes[l].link.push_back(r);
            }
        }
    }

    string path;
    vector <string> paths;

    void dfs(int id) {
        string ori_path = path;
        path = path + nodes[id].seq;
        if(nodes[id].link.size() == 0) {
            paths.push_back(path);
            return;
        }
        for(auto next: nodes[id].link) {
            dfs(next);
        }
        path = ori_path;
    }

    void allpaths() {
        path = "";
        dfs(1);
        cout << paths.size() << endl;
        /*
        for(auto p: paths) {
            cout << p << endl;
        }*/
    }
};



inline int h(char c) {
    switch(c){
        case 'A': return 0;
        case 'C': return 1;
        case 'G': return 2;
        case 'T': return 3;
    }
    return -1;
}

const string acid = "ACGT";
const int maxn = 500005;

class Trie {
public:
    int next[maxn][4];  // 转移
    int tot;                   // 节点总数：[0, tot)

    Trie() { tot = 1; memset(next, 0, sizeof(next));}

    int insertTrie(int cur, int c) {
        if (next[cur][c]) {
            return next[cur][c];
        }
        return next[cur][c] = tot++;
    }

    void insert(const string &s) {
        int root = 0;
        for (auto ch : s) {
            root = insertTrie(root, h(ch));
        }
    }

    void show() {
        for(int i = 0; i < tot; i ++) {
            cout << "=== node: " << i << endl;
            for(int j = 0; j < 4; j ++) {
                if(next[i][j]) {
                    cout << "+++ " << acid[j] << "\t" << next[i][j] << endl;
                }

            }
        }
    }
};


const int char_num = 4;
class GSAM {
public:
    int len[maxn];             // 节点长度
    int link[maxn];            // 后缀链接，link
    int next[maxn][char_num];  // 转移
    int tot;                   // 节点总数：[0, tot)

    void init() {  // 初始化函数
        tot = 1;
        link[0] = -1;
    }

    int insertSAM(int last, int c) {  // last 为父 c 为子
        int cur = next[last][c];
        if (len[cur]) return cur;
        len[cur] = len[last] + 1;
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
        for (int i = 0; i < char_num; ++i)
            next[clone][i] = len[next[q][i]] != 0 ? next[q][i] : 0;
        len[clone] = len[p] + 1;
        while (p != -1 && next[p][c] == q) {
            next[p][c] = clone;
            p = link[p];
        }
        link[clone] = link[q];
        link[cur] = clone;
        link[q] = clone;
        return cur;
    }

    int insertTrie(int cur, int c) {
        if (next[cur][c]) return next[cur][c];  // 已有该节点 直接返回
        return next[cur][c] = tot++;            // 无该节点 建立节点
    }

    void insert(const string &s) {
        int root = 0;
        for (auto ch : s) root = insertTrie(root, h(ch));
    }

    void insert(const char *s, int n) {
        int root = 0;
        for (int i = 0; i < n; ++i)
            root =
                    insertTrie(root, h(s[i]));  // 一边插入一边更改所插入新节点的父节点
    }

    void build() {
        queue<pair<int, int>> q;
        for (int i = 0; i < char_num; ++i)
            if (next[0][i]) q.push({i, 0});
        while (!q.empty()) {  // 广搜遍历
            auto item = q.front();
            q.pop();
            auto last = insertSAM(item.second, item.first);
            for (int i = 0; i < char_num; ++i)
                if (next[last][i]) q.push({i, last});
        }
    }

    void show() {
        for(int i = 0; i < tot; i ++) {
            cout << "=== " << i << ", len= " << len[i] << ", link= " << link[i] << endl;
            for(int j = 0; j < char_num; j ++) {
                if(next[i][j]) {
                    cout << "+++ " << (char)('A' + j) << "\t" << next[i][j] << endl;
                }
            }
        }
    }

    void graph_view() {
        for(int i = 0; i < tot; i ++) {
            cerr << i << endl;
        }
        for(int i = 0; i < tot; i ++) {
            for(int j = 0; j < char_num; j ++) {
                if(next[i][j]) {
                    cerr << i << "\t" << next[i][j] << "\t" << acid[j] << endl;
                }
            }
        }
    }

    bool search(string & s) {
        int cur = 0;
        for(auto ch : s) {
            if(next[cur][h(ch)]) {
                cur = next[cur][h(ch)];
            } else {
                return false;
            }
        }
        return true;
    }

};



GSAM gsam;
int main() {
    SeqGraph graph;
    graph.build("fa/graph.gfa");
    //graph.build("./graph.gfa");
    int totchar = 0;
    for(auto i: graph.nodes) {
        cout << i.first << ": " << i.second.seq << endl;
        totchar += i.second.seq.length();
        for(auto j: i.second.link) {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << "Total = " << totchar << endl;
    graph.allpaths();

    int pathtot = 0;
    for(auto p: graph.paths) {
        cout << p.length() << endl;
        pathtot += p.length();
    }
    cout << "All path = " << pathtot << endl;


    /*
    Trie trie;
    for(auto p: graph.paths) {
        trie.insert(p);
    }
    cout <<"Here?" << endl;
    */

    //trie.show();

    cout << "GSAM" << endl;

    gsam.init();
    for(auto p: graph.paths) {
        //cout << p << endl;
        gsam.insert(p);
        //int last = 1;
        //for(int i = 0; p[i]; i ++) {
        //SAM.insert(p[i] - 'A', last);
        //}
    }
    gsam.build();
    //gsam.show();
//gsam.graph_view();


    //ifstream ifs("read.fa");
    ifstream ifs("read1000.fa");
    //ifstream ifs("seq.fa");
    string name, t;
    int n = 0;
    while(getline(ifs, name)) {
        getline(ifs, t);
        //cout << t << endl;
        //if(name[0] != '>') {
        //	getchar();
        //	getchar();
        //	cout << "NO!\t" << name << endl;
        //}
        if(gsam.search(t)) {
            n++;
            //cout << "YES!\t" << name << endl;
        }
    }
    cout << "!!!" << n << endl;

    return 0;
}


