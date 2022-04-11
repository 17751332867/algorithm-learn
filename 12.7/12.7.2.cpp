
//
// Created by wyl on 2021/12/7.
//

#include<iostream>
#include<iomanip>
using namespace std;
int t,W,H,x1,x2,y1,y2,w,h;
int main(){
    cin.sync_with_stdio(false);
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>W>>H>>x1>>y1>>x2>>y2>>w>>h;
        int w1 = x2-x1,h1 = y2-y1;
 //       cout<<w1<<" "<<w<<" "<<h1<<" "<<h<<endl;
        if(w1+w>W&&h1+h>H){
            cout<<-1<<endl;continue;
        }
        int t1=0x3f3f3f3f,t2=0x3f3f3f3f;
        if(w1+w<=W)t1 = max(w-max(x1,W-x2),0);
        if(h1+h<=H)t2 = max(h-max(y1,H-y2),0);
        cout<<fixed<<setprecision(9)<<1.0*min(t1,t2)<<endl;
    }
}