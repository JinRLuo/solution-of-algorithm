#include <iostream>
using namespace std;

const int maxn = 1000100;
int q[maxn],a[maxn];
int hh=0,tt=-1;
int n,k; 

int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++){
		if(tt>=hh&&i-k+1>q[hh]) hh++;
		while(tt>=hh&&a[q[tt]]>=a[i]) tt--;
		q[++tt]=i;
		if(i>=k-1)
			cout << a[q[hh]] << " "; 
	}
	cout << endl;
	hh=0,tt=-1;
	for(int i=0;i<n;i++){
		if(tt>=hh&&i-k+1>q[hh]) hh++;
		while(tt>=hh&&a[q[tt]]<=a[i]) tt--;
		q[++tt]=i;
		if(i>=k-1)
			cout << a[q[hh]] << " ";
	}
	cout << endl;
}
