#include <iostream>
using namespace std;

const int maxn = 100010;
int n,m;
int h[maxn];
int size;

void down(int x){
	int t=x;
	if(2*x<=size&&h[t]>h[2*x]) t=2*x;
	if(2*x+1<=size&&h[t]>h[2*x+1]) t=2*x+1;
	if(t!=x){
		swap(h[x],h[t]);
		down(t);
	}
}

int main(){
	int x;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin >> h[i];
	}
	size=n;
	for(int i=n/2;i;i--){
		down(i);
	}
	for(int i=0;i<m;i++){
		cout << h[1] << endl;
		h[1]=h[size--];
		down(1);
	}
	for(int i=1;i<=n;i++){
		cout << h[i] << " ";
	}
	cout << endl;
} 
