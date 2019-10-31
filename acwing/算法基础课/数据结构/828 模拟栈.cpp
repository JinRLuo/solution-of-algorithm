#include <iostream>
using namespace std;

const int maxn = 100010;
int stk[maxn],tt;

int main(){
    tt=0;
    int m,x;
    string s;
    cin>>m;
    while(m--){
        cin>>s;
        if(s=="push"){
            cin>>x;
            stk[tt++]=x;
        }else if(s=="query"){
            cout << stk[tt-1] << endl;
        }else if(s=="pop"){
            tt--;
        }else{
            if(tt>0)
                cout << "NO" << endl;
            else 
                cout << "YES" << endl;
        }
    }
}

