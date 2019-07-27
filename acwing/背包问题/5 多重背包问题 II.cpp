#include <bits/stdc++.h> 
using namespace std;

int N,V;
int v[1005],w[1005],s[1005];
int f[2005];
int a[25000],b[25000];

int main(){
	int cnt;
	cin>>N>>V;
	for(int i=1;i<=N;i++){
		cin>>v[i]>>w[i]>>s[i];
	}
	cnt=1;
	for(int i=1;i<=N;i++){
		for(int j=1;j<s[i];j<<=1){
			a[cnt]=v[i]*j;
			b[cnt++]=w[i]*j;
			s[i]-=j;
		}
		if(s[i]){
			a[cnt]=v[i]*s[i];
			b[cnt++]=w[i]*s[i];
		}
	}
	for(int i=1;i<cnt;i++){
		for(int j=V;j>=0;j--){
			if(j>=a[i])
				f[j]=max(f[j],f[j-a[i]]+b[i]);
		}
	}
	cout << f[V] << endl;
}
