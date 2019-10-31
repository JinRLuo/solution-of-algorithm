#include <iostream>
using namespace std;

const int maxn = 100010;
int h[maxn];
int ph[maxn],hp[maxn];
int m;
int size,n;

void heap_swap(int a,int b){
	swap(ph[hp[a]],ph[hp[b]]);
	swap(hp[a],hp[b]);
	swap(h[a],h[b]);
}

void down(int x){
	int t=x;
	if(2*x<=size&&h[2*x]<h[t]) t=2*x;
	if(2*x+1<=size&&h[2*x+1]<h[t]) t=2*x+1;
	if(t!=x){
		heap_swap(t,x);
		down(t);
	}
}

void up(int x){
	if(x==1) return;
	int t=x/2;
	if(h[t]>h[x]){
		heap_swap(t,x);
		up(t);
	}
}

int main(){
	string s;
	int k,x;
	size=0;
	m=0;
	cin>>n;
	while(n--){
		cin>>s;
		if(s=="I"){
			cin>>x;
			h[++size]=x;
			ph[++m]=size;
			hp[size]=m;
			up(size);
		}else if(s=="PM"){
			cout << h[1] << endl;
		}else if(s=="DM"){
			heap_swap(1,size--);
			down(1);
		}else if(s=="D"){
			cin>>k;
			int t=ph[k];
			heap_swap(t,size--);
			up(t);
			down(t);
		}else{
			cin>>k>>x;
			int t=ph[k];
			h[t]=x;
			up(t);
			down(t);
		}
	}
//	for(int i=1;i<=size;i++){
//		cout << h[i] << " ";
//	}
//	cout << endl;
}
