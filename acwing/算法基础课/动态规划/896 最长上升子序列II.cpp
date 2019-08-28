#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 100010;
int n;
int a[maxn];
int q[maxn];

int main(){
	memset(q,0,sizeof(q));
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	int len=0;
	for(int i=0;i<n;i++){
		int l=0,r=len;
		while(l<r){
			int mid=(l+r+1)/2;
			if(q[mid]<a[i])
				l=mid;
			else
				r=mid-1;
		}
		q[r+1]=a[i];
		len=max(len,r+1);
	}
	cout << len << endl;
	return 0; 
}
