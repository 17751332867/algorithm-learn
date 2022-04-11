
//
// Created by wyl on 2022/3/23.
//
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
typedef pair<int,int> PII;
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
string BASE_DIR="D:\\workspace\\clion-workspace\\algorithm-learn\\create_data\\";
set<pair<string,string> > m;
vector<int> G[N];
map<string,int> file_idx;
map<string,string> node_idx;
ofstream outs[N];

int cnt = 0;
int main(){
    ifstream in;
    in.open(BASE_DIR+"GRCh38-20-0.10b.gfa");
    string line;
    ofstream out;
    out.open(BASE_DIR+"out.txt");
    while(getline(in,line)){
        stringstream ss(line);
        string pos;ss>>pos;
        if(pos=="S"){
            node nd;
            ss>>nd.name>>nd.DNA>>nd.LN>>nd.SN>>nd.SO>>nd.SR>>nd.cf;
            int pos = nd.SN.find("#");
            string s = nd.SN.substr(0,pos).substr(5);
            node_idx[nd.name]=s;
            if(file_idx[s]==0){
                file_idx[s]=++cnt;
                outs[cnt].open(BASE_DIR+s);
            }
            outs[cnt]<<"S"<<"\t"<<nd.name<<"\t"<<nd.DNA<<"\t"<<nd.LN<<"\t"<<nd.SN<<"\t"<<nd.SO<<"\t"<<nd.SR<<"\t"<<nd.cf<<endl;
        }
        if(pos=="L"){
            edge eg;
            ss>>eg.from>>eg.from_pos>>eg.to>>eg.to_pos>>eg.match>>eg.SR>>eg.L1>>eg.L2>>eg.cf;
            string from_file = node_idx[eg.from];
            string to_file = node_idx[eg.to];
            if(from_file==to_file){
                int idx = file_idx[from_file];
                outs[idx]<<"L"<<"\t"<<eg.from<<"\t"<<eg.from_pos<<"\t"<<eg.to<<"\t"<<eg.match<<"\t"<<eg.to_pos<<"\t"<<eg.SR<<"\t"<<eg.L1<<"\t"<<eg.L2<<"\t"<<eg.cf<<endl;
            }else{
                m.insert({from_file,to_file});
            }
        }
    }
    cout<<m.size()<<endl;
    for(auto  a:m){
        cout<<a.first<<" "<<a.second<<endl;
    }
}
