#include <bits/stdc++.h>
using namespace std;

//priority_queue<int,vector<int>,greater<int> > q;
int c,l;

struct cow{
    int mins,maxs;
}cw[2505];

struct spf{
    int s,cover;
}sf[2505];

int cmp1(cow c1,cow c2){
    if(c1.mins==c2.mins)
        return c1.maxs>c2.maxs;
    return c1.mins>c2.mins;
}

int cmp2(spf s1,spf s2){
    return s1.s>s2.s;
}

int main(){
    int res=0;
    int a,b;
    cin >>c>>l;
    for(int i=0;i<c;i++){
        cin >> cw[i].mins >> cw[i].maxs;
    }
    for(int i=0;i<l;i++){
        cin >> sf[i].s >> sf[i].cover;
    }
    sort(cw,cw+c,cmp1);
    sort(sf,sf+l,cmp2);
    for(int i=0;i<c;i++){
        for(int j=0;j<l;j++){
            if(sf[j].s>=cw[i].mins&&sf[j].s<=cw[i].maxs&&sf[j].cover!=0){
                res++;
                sf[j].cover--;
                break;
            }
        }
    }
    cout << res << endl;
}
