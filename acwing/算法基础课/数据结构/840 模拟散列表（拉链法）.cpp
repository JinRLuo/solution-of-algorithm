#include <iostream>
#include <cstring> 
using namespace std;

const int maxn = 100003;
int h[maxn];
int e[maxn],ne[maxn],idx;
int n;

int find(int x){
	int k=(x%maxn+maxn)%maxn;
	for(int i=h[k];i!=-1;i=ne[i]){
		if(e[i]==x){
			return 1;
		}
	}
	return 0;
}

void insert(int x){
	int k=(x%maxn+maxn)%maxn;
	e[idx]=x;
	ne[idx]=h[k];
	h[k]=idx++;
}

int main(){
	cin>>n;
	char c;
	int x;
	memset(h,-1,sizeof(h));
	for(int i=0;i<n;i++){
		cin>>c>>x;
		if(c=='I'){
			insert(x);
		}else{
			if(find(x))
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
	}
}
