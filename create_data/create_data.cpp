
//
// Created by wyl on 2022/3/24.
//
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
string BASE_DIR="D:\\workspace\\clion-workspace\\algorithm-learn\\create_data\\";
struct node {
    string name;
    string DNA;
    string LN;
    string SN;
    string SO;
    string SR;
    string cf;
};
struct edge{
    string from;
    string from_pos;
    string to;
    string to_pos;
    string match;
    string SR;
    string L1;
    string L2;
    string cf;
};
map<string,int> nmap;
map<int,string> rmap;
map<int,node> node_map;
map<pair<int,int>,edge> edge_map;
map<int,int> begin_pos;
map<string,string> file_map;

vector<int> G[N];
int din[N];
int used[N];
int cnt = 0,tt = 0;
void bfs(int s){
    queue<int> q;
    q.push(s);
    int res = 0;
    while(q.size()){
        int t = q.front();q.pop();
        if(used[t])continue;
        used[t]=true,res++;
        for(int i=0;i<G[t].size();i++){
            q.push(G[t][i]);
        }
    }
    if(res!=0){
        tt++;
        begin_pos[tt]=s;
        cout<<"file Id:"<<tt<<endl;
        cout<<"started node come from:"<<file_map[rmap[s]]<<";\ncyclied:"<<(din[s]==0?"acycliced":"Looped")<<";\ntotol nodes:"<<res<<endl;
        cout<<"---------------------------------------------------------"<<endl;
    }
}
int main() {
    ifstream in;
    in.open(BASE_DIR + "GRCh38-20-0.10b.gfa");
    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        string pos;
        ss >> pos;
        if (pos == "S") {
            node nd;
            ss >> nd.name >> nd.DNA >> nd.LN >> nd.SN >> nd.SO >> nd.SR >> nd.cf;
            if(nmap[nd.name]==0){
                nmap[nd.name]=++cnt;
                rmap[cnt]=nd.name;
                node_map[cnt]=nd;
            }
            int pos = nd.SN.find("#");
            string s = nd.SN.substr(0,pos).substr(5);
            file_map[nd.name]=s;
        }
        if (pos == "L") {
            edge eg;
            ss >> eg.from >> eg.from_pos >> eg.to >> eg.to_pos >> eg.SR >> eg.L1 >> eg.L2 >> eg.cf;
            int from = nmap[eg.from],to = nmap[eg.to];
            edge_map[{from,to}]=eg;
            din[to]++;
            G[from].push_back(to);
        }
    }
    for(int i=1;i<=cnt;i++){
        bfs(i);
    }
    cout<<"please choose the fileId you wanted"<<endl;
    int begin;cin>>begin;begin=begin_pos[begin];
    memset(used,0,sizeof used);
    ofstream out;
    out.open(BASE_DIR+file_map[rmap[begin]]);
    queue<int> q;
    q.push(begin);
    vector<pair<int,int> > edges;
    while(q.size()){
        int t = q.front();q.pop();
        if(used[t])continue;
        used[t]=true;
        node nd = node_map[t];
        out <<"S\t"<<nd.name <<"\t"<< nd.DNA <<"\t"<< nd.LN <<"\t"<< nd.SN <<"\t"<< nd.SO <<"\t"<< nd.SR <<"\t"<< nd.cf<<endl;
        for(int i=0;i<G[t].size();i++){
            q.push(G[t][i]);
            edges.push_back({t,G[t][i]});
        }
    }
    for(auto a:edges){
        edge eg=edge_map[a];
        out <<"L\t"<< eg.from <<"\t"<< eg.from_pos <<"\t"<< eg.to <<"\t"<< eg.to_pos <<"\t"<< eg.SR <<"\t"<< eg.L1 <<"\t"<< eg.L2 <<"\t"<< eg.cf<<endl;
    }
}