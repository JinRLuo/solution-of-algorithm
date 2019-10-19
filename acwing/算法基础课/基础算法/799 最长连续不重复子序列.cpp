#include <iostream>
#include <cstring> 
using namespace std;

const int maxn = 100010;
int n;
int a[maxn];
int m[maxn];

int main(){
	int res=0;
	memset(m,0,sizeof(m));
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int j=0;
	for(int i=0;i<n;i++){
		m[a[i]]++;
		while(m[a[i]]>1){
			m[a[j]]--;
			j++;
		}
		res=max(res,i-j+1);
	}
	cout << res << endl;
} 
