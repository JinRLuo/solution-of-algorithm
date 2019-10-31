#include <iostream>
#include <cstring> 
using namespace std;

const int maxn = 200003,null = 0x3f3f3f3f;
int h[maxn];
int n;

int find(int x){
	int k = (x%maxn+maxn)%maxn;
	while(h[k]!=null){
		if(h[k]==x)
			return k;
		else{
			if(k==maxn)
				k=0;
			else
				k++;
		}
	}
	return k;
}

int main(){
	int x;
	char c;
	cin>>n;
	memset(h,0x3f,sizeof(h));
	while(n--){
		cin>>c>>x;
		int k = find(x);
		if(c=='I'){
			if(h[k]!=x)
				h[k]=x;
		}else{
			if(h[k]==x)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
	}
}
