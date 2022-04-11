
//
// Created by wyl on 2021/12/20.
//

#include<iostream>
#include<cmath>
#include <cstdio>

using namespace std;
double s1,s2;
double dist,x,y,x2,y2;
int mins;
int hh,mm;
int main(){
    ios::sync_with_stdio(false);
    cin>>s1>>s2;
    while(cin>>x>>y>>x2>>y2){
        dist += sqrt(pow(x2-x,2)+pow(y2-y,2));
    }
    mins = round(dist/20*60/1000);
    hh = mins/60;mm=mins%60;
    printf("%d:%02d\n",hh,mm);
}