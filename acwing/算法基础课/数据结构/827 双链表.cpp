#include <iostream>
using namespace std;

const int maxn = 100010;
int l[maxn],r[maxn],e[maxn];
int m,idx;

void init(){
	r[0]=1;
	l[1]=0;
	idx=2;
}

void add(int k,int x){
	e[idx]=x;
	l[idx]=k;
	r[idx]=r[k];
	l[r[k]]=idx;
	r[k]=idx++;
}

void remove(int k){
	r[l[k]]=r[k];
	l[r[k]]=l[k];
}

int main(){
	string s;
	int k,x;
	init();
	cin>>m;
	while(m--){
		cin>>s;
		if(s=="L"){
			cin>>x;
			add(0,x);
		}else if(s=="R"){
			cin>>x;
			add(l[1],x);
		}else if(s=="D"){
			cin>>k;
			remove(k+1);
		}else if(s=="IL"){
			cin>>k>>x;
			add(l[k+1],x);
		}else if(s=="IR"){
			cin>>k>>x;
			add(k+1,x);
		}
	}
	for(int i=r[0];i!=1;i=r[i]){
		cout << e[i] << " ";
	}
	cout << endl;
} 
