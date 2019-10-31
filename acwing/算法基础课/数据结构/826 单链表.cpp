#include <iostream>
using namespace std;

const int maxn = 100010;
int head,idx;
int e[maxn],ne[maxn];
int m;

void init(){
	head=-1;
	idx=0;
}

void add_to_head(int x){
	e[idx]=x;
	ne[idx]=head;
	head=idx++;
}

void add(int k,int x){
	ne[idx]=ne[k];
	e[idx]=x;
	ne[k]=idx++;
}

void remove(int x){
	ne[x]=ne[ne[x]];
}


int main(){
	int k,x;
	char c;
	cin>>m;
	init();
	while(m--){
		cin>>c;
		if(c=='H'){
			cin>>x;
			add_to_head(x);
		}else if(c=='D'){
			cin>>k;
			if(k==0)
				head=ne[head];
			else
				remove(k-1);
		}else if(c=='I'){
			cin>>k>>x;
			add(k-1,x);
		}
	}
	for(int i=head;i!=-1;i=ne[i]){
		cout << e[i] << " ";
	}
	cout << endl;
} 
