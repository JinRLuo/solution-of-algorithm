#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 100010;
int n,m;
int l,r,c;
int a[maxn];
int s[maxn];

int main(){
	int t;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		a[i]=s[i]-s[i-1];
	}
	for(int i=1;i<=m;i++){
		cin>>l>>r>>c;
		a[l]+=c;
		a[r+1]-=c;
	}
	for(int i=1;i<=n;i++){
		a[i]=a[i]+a[i-1];
		cout << a[i] << " ";
	}
}
