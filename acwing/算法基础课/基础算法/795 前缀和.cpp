#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 100010;
int n,m;
int a[maxn];
int l,r;

int main(){
	memset(a,0,sizeof(a)); 
	int t;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>t;
		a[i]=a[i-1]+t;
	}
	for(int i=0;i<m;i++){
		cin>>l>>r;
		cout << a[r]-a[l-1] << endl;
	}
	return 0;
} 
