#include <iostream>
using namespace std;

const int maxn = 100010;
int m;
int q[maxn];
int hh,tt;

int main(){
	cin>>m;
	int x;
	hh=0,tt=0;
	string s;
	while(m--){
		cin>>s;
		if(s=="push"){
			cin>>x;
			q[tt++]=x;
		}else if(s=="pop"){
			hh++;
		}else if(s=="empty"){
			if(hh==tt)
				cout << "YES" << endl;
			else 
				cout << "NO" << endl;
		}else{
			cout << q[hh] << endl;
		}
	}
}
